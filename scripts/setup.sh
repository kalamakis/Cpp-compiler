#!/usr/bin/env bash
set -euo pipefail

required=(gcc make flex bison)
optional=(dot)

run_as_root() {
    if [[ $(id -u) -eq 0 ]]; then
        "$@"
    elif command -v sudo >/dev/null 2>&1; then
        sudo "$@"
    else
        echo "Administrator privileges are required to install packages." >&2
        exit 1
    fi
}

missing=()
for command_name in "${required[@]}"; do
    command -v "$command_name" >/dev/null 2>&1 || missing+=("$command_name")
done

if ((${#missing[@]} == 0)); then
    echo "Required build tools are already installed."
else
    echo "Missing tools: ${missing[*]}"
    echo "Installing the compiler toolchain..."

    if command -v apt-get >/dev/null 2>&1; then
        run_as_root apt-get update
        run_as_root apt-get install -y build-essential flex bison graphviz
    elif command -v dnf >/dev/null 2>&1; then
        run_as_root dnf install -y gcc make flex bison graphviz
    elif command -v yum >/dev/null 2>&1; then
        run_as_root yum install -y gcc make flex bison graphviz
    elif command -v pacman >/dev/null 2>&1; then
        run_as_root pacman -S --needed gcc make flex bison graphviz
    elif command -v brew >/dev/null 2>&1; then
        brew install flex bison graphviz
        echo "On macOS, add Homebrew's Flex and Bison directories to PATH if needed."
    else
        echo "Unsupported package manager." >&2
        echo "Install GCC, Make, Flex and Bison manually, then run 'make'." >&2
        exit 1
    fi
fi

for command_name in "${required[@]}"; do
    command -v "$command_name" >/dev/null 2>&1 || {
        echo "Dependency check failed: '$command_name' is still unavailable." >&2
        exit 1
    }
done

for command_name in "${optional[@]}"; do
    if ! command -v "$command_name" >/dev/null 2>&1; then
        echo "Optional tool '$command_name' is missing; AST PNG rendering will be skipped."
    fi
done

echo "Environment is ready. Run 'make' to build the compiler."
