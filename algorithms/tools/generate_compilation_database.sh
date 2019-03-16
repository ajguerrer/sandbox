#!/bin/bash

# Generates a compile_commands.json file at $(bazel info execution_root) for
# your Clang tooling needs.

set -e

CC=clang CXX=clang++ bazel build \
  --experimental_action_listener=@io_kythe//kythe/cxx/tools/generate_compile_commands:extract_json \
  $(bazel query 'kind(cc_.*, //...)')

pushd $(bazel info execution_root) > /dev/null
echo "[" > compile_commands.json
find . -name '*.compile_command.json' -exec bash -c 'cat {} && echo ,' \; >> compile_commands.json
sed -i '$s/,$//' compile_commands.json
echo "]" >> compile_commands.json
popd > /dev/null
