#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
PROJECT_ROOT=$(cd -- "$SCRIPT_DIR/.." && pwd)
CALLER_DIR=$PWD
SKIP_BUILD=0

if [[ ${1:-} == "--no-build" ]]; then
    SKIP_BUILD=1
    shift
fi

if [[ $# -lt 1 || $# -gt 2 ]]; then
    echo "Usage: $0 [--no-build] <input.cpp> [output.asm]" >&2
    exit 2
fi

input=$1
if [[ "$input" != /* ]]; then
    input="$CALLER_DIR/$input"
fi

if [[ ! -f "$input" ]]; then
    echo "Input file not found: $input" >&2
    exit 2
fi

stem=$(basename -- "$input")
stem=${stem%.*}

if [[ $# -eq 2 ]]; then
    output=$2
    [[ "$output" == /* ]] || output="$CALLER_DIR/$output"
else
    output="$PROJECT_ROOT/output/$stem.asm"
fi

if ((SKIP_BUILD == 0)); then
    make -C "$PROJECT_ROOT" build
fi

compiler="$PROJECT_ROOT/bin/gcpp"
if [[ ! -x "$compiler" ]]; then
    echo "Compiler binary not found. Run 'make' first." >&2
    exit 1
fi

work_dir="$PROJECT_ROOT/build/run/$stem"
rm -rf "$work_dir"
mkdir -p "$work_dir" "$(dirname -- "$output")"

set +e
(
    cd "$work_dir"
    "$compiler" "$input" >stdout.log 2>stderr.log
)
status=$?
set -e

cat "$work_dir/stdout.log"
cat "$work_dir/stderr.log" >&2

if [[ $status -ne 0 ]] || grep -q '^ERROR:' "$work_dir/stderr.log"; then
    echo "Compilation failed." >&2
    exit 1
fi

if [[ ! -s "$work_dir/out.asm" ]]; then
    echo "Compilation did not produce a non-empty out.asm file." >&2
    exit 1
fi

cp "$work_dir/out.asm" "$output"

artifact_base=${output%.asm}
if [[ -f "$work_dir/ast.dot" ]]; then
    cp "$work_dir/ast.dot" "${artifact_base}.ast.dot"
fi
if [[ -f "$work_dir/ast.png" ]]; then
    cp "$work_dir/ast.png" "${artifact_base}.ast.png"
fi

echo "Assembly: $output"
[[ -f "${artifact_base}.ast.dot" ]] && echo "AST (DOT): ${artifact_base}.ast.dot"
[[ -f "${artifact_base}.ast.png" ]] && echo "AST (PNG): ${artifact_base}.ast.png"
