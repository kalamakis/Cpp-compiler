# CPP Compiler

An educational compiler for **CPP**, the C++-like language defined by the included university
project specification. This is not a compiler for the complete ISO C++ language.

The compiler uses **Flex** and **Bison** for the front end, performs semantic analysis and AST
construction, lowers the program to a three-address intermediate representation, and emits
**MIPS assembly**.

## Compilation pipeline

```text
CPP source
   -> Flex lexer
   -> Bison parser
   -> Semantic analysis and symbol table
   -> Abstract syntax tree (AST)
   -> Three-address intermediate representation (IR)
   -> MIPS assembly
```

## Implemented areas

The current implementation includes support for many of the language constructs used by the
project specification and examples:

- primitive types, strings, arrays and lists;
- variable, function and parameter declarations, including reference parameters;
- arithmetic, relational and logical expressions;
- `if`, `while`, `for`, `break`, `continue` and `return`;
- `typedef` and enums;
- classes, access sections and basic inheritance-related syntax;
- `cin` and `cout` style input/output;
- AST visualization, intermediate-code generation and MIPS code generation.

Some features are partial or need stronger validation. See
[`docs/known-limitations.md`](docs/known-limitations.md).

## Repository layout

```text
.
├── src/                 Compiler source, Flex lexer and Bison grammar
├── examples/            Valid CPP programs used as examples and smoke tests
├── scripts/             Setup, run and test helpers
├── docs/                Language specification and known limitations
├── .github/workflows/   Continuous-integration build
├── Makefile             Main build interface
└── README.md
```

Earlier milestone copies and generated build files from the original student repository are not
included in this cleaned version. The actively used final implementation is preserved under
`src/`.

## Requirements

- GCC or a compatible C compiler
- GNU Make
- Flex
- Bison
- Graphviz, optional but recommended for AST PNG generation

Linux and WSL are the primary supported environments. On Debian or Ubuntu, the helper script can
install the dependencies:

```bash
./scripts/setup.sh
```

Alternatively:

```bash
sudo apt-get update
sudo apt-get install build-essential flex bison graphviz
```

## Build

```bash
make
```

The compiler executable is created at:

```text
bin/gcpp
```

Generated parser, lexer and object files are kept under `build/` rather than mixed with the
source tree.

## Compile an example

```bash
./scripts/run.sh examples/arrays_and_functions.cpp
```

By default, generated artifacts are written to `output/`:

```text
output/arrays_and_functions.asm
output/arrays_and_functions.ast.dot
output/arrays_and_functions.ast.png   # when Graphviz is available
```

A custom assembly path can be supplied as the second argument:

```bash
./scripts/run.sh examples/strings.cpp output/strings.asm
```

The same operation is available through Make:

```bash
make run INPUT=examples/strings.cpp
make run INPUT=examples/strings.cpp OUTPUT=output/custom.asm
```

The compiler executable may also be called directly. In that case, it writes `out.asm`,
`ast.dot` and, when Graphviz is installed, `ast.png` in the current working directory:

```bash
./bin/gcpp examples/strings.cpp
```

## Tests

Run the included smoke tests with:

```bash
make test
```

The test script compiles every program under `examples/` in an isolated directory and verifies
that compilation completes without a reported parser error and produces non-empty MIPS assembly.
It does not yet execute the generated MIPS programs or compare their output with expected values.

## Debug output

Debug features are controlled by macros in [`src/settings.h`](src/settings.h):

- `FLEX_DEBUG` controls lexer diagnostics;
- `HASHTBL_DEBUG` controls symbol-table diagnostics;
- `AST_DEBUG` enables AST generation;
- `IR_DEBUG` prints the generated quadruples.

The current defaults retain the behavior of the original project, including AST and IR output.

## Language specification

The original Greek-language project specification is preserved at
[`docs/language-specification.pdf`](docs/language-specification.pdf). Among other differences from
standard C++, the defined CPP language treats keywords without case sensitivity.

## Cleaning generated files

```bash
make clean
```

This removes `build/`, `bin/` and `output/`.
