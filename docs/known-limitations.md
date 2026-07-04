# Known limitations and future work

These notes consolidate the unfinished items that were recorded in the original project.
They are not all confirmed defects; some are areas that still need stronger validation or
comparison with the language specification.

- A function may be declared by prototype, called, and never defined without always producing
  the expected diagnostic.
- AST nodes and symbol-table entries are not consistently bound in every part of the compiler.
- Array and list validation needs broader edge-case coverage.
- Constant arrays are not currently supported.
- Enum validation needs additional edge-case checks.
- Class-field handling and related class semantics remain partially implemented.
- The supported grammar and semantics should be cross-checked systematically against the
  original language specification in `language-specification.pdf`.

The current test suite is a smoke test: it checks that the included valid programs compile and
produce non-empty MIPS assembly. It does not yet verify generated program output or diagnostic
quality for invalid programs.
