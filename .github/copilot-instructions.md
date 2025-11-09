# repo-specific Copilot instructions

Purpose: help AI coding agents be immediately productive in this small C++ study repo.

Big picture
- This is a lightweight "toy" C++ study repository: small, standalone .cpp programs (root and `leetcode/`) intended to be compiled into single-file executables. Examples: `hello_world.cpp`, `leetcode/leetcode_two_sum.cpp`, `leetcode/leetcode_1071.cpp`.
- Build artifacts are collected in `build/` and that directory is ignored by git (`.gitignore` contains `/build/`). Binary names follow the source basename (e.g. `hello_world` from `hello_world.cpp`).

Build & run workflows (discovered)
- Preferred quick workflow: use the VS Code task labeled `C/C++: g++ build active file`. That task compiles the active editor file and writes an executable under `build/<source-basename>`.
- Binaries already present in `build/` can be executed directly for manual verification.
- The repository does not include a project-wide Makefile or CI; expect to compile single files individually. There are a few higher-level test harnesses (e.g. `leetcode/leetcode_test.cpp`) that you can compile and run like other sources.

Conventions and patterns
- One translation unit per exercise: each `.cpp` is self-contained and usually contains its own `main()` when intended to run directly.
- File naming: most LeetCode solutions use the `leetcode_*.cpp` pattern and live under `leetcode/`.
- Output location: compiled binaries are expected to live in `build/` and that folder should not be modified in source control.
- Minimal dependencies: files use the standard library only; there are no external package manifests or third-party libs present.

What AI agents should do first
- Open `hello_world.cpp` and a target `leetcode/*.cpp` to see the minimal program layout and how tests/harness files are structured.
- When creating or editing code, keep binaries emitted to `build/` in mind and avoid editing files in `build/` (they are generated artifacts).
- Search for `leetcode_test.cpp` when you need an example harness that runs multiple functions.

Files to reference
- `.gitignore` — confirms `build/` is ignored.
- `hello_world.cpp`, `README.md` — the simplest examples.
- `leetcode/leetcode_test.cpp` — example of a test harness.
- `leetcode/*.cpp` — the collection of exercises to mirror for new solutions.

If anything above is inaccurate or you'd like the file to include explicit compile commands or a Makefile suggestion, tell me and I'll update this file.
