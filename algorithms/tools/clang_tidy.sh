#!/bin/bash
set -e
CC=clang
$(dirname "${BASH_SOURCE[0]}")/generate_compilation_database.sh

/usr/local/share/clang/run-clang-tidy.py -p="$(bazel info execution_root)" -header-filter=.*
