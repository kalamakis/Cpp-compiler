#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
PROJECT_ROOT=$(cd -- "$SCRIPT_DIR/.." && pwd)
SKIP_BUILD=0

if [[ ${1:-} == "--no-build" ]]; then
    SKIP_BUILD=1
    shift
fi

if [[ $# -ne 0 ]]; then
    echo "Usage: $0 [--no-build]" >&2
    exit 2
fi

if ((SKIP_BUILD == 0)); then
    make -C "$PROJECT_ROOT" build
fi

compiler="$PROJECT_ROOT/bin/gcpp"
if [[ ! -x "$compiler" ]]; then
    echo "Compiler binary not found. Run 'make' first." >&2
    exit 1
fi

shopt -s nullglob
programs=("$PROJECT_ROOT"/examples/*.cpp)
if ((${#programs[@]} == 0)); then
    echo "No example programs were found." >&2
    exit 1
fi

test_root="$PROJECT_ROOT/build/tests"
rm -rf "$test_root"
mkdir -p "$test_root"

passed=0
failed=0

for program in "${programs[@]}"; do
    name=$(basename -- "$program")
    case_dir="$test_root/${name%.cpp}"
    mkdir -p "$case_dir"

    set +e
    (
        cd "$case_dir"
        "$compiler" "$program" >stdout.log 2>stderr.log
    )
    status=$?
    set -e

    if [[ $status -eq 0 && -s "$case_dir/out.asm" ]] && \
       ! grep -q '^ERROR:' "$case_dir/stderr.log"; then
        printf 'PASS  %s\n' "$name"
        ((passed += 1))
    else
        printf 'FAIL  %s\n' "$name"
        printf '      exit=%d, assembly=%s\n' \
            "$status" "$([[ -s "$case_dir/out.asm" ]] && echo present || echo missing)"
        if [[ -s "$case_dir/stderr.log" ]]; then
            sed 's/^/      /' "$case_dir/stderr.log"
        fi
        ((failed += 1))
    fi
done

printf '\nSmoke tests: %d passed, %d failed.\n' "$passed" "$failed"
((failed == 0))
