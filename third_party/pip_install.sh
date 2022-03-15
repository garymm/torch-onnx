#!/usr/bin/env bash
set -o errexit
set -o pipefail

pip install -r third_party/torch-mlir/requirements.txt
# Keep this in sync with the submodule
SNAPSHOT=$(git -C third_party/torch-mlir tag --points-at | grep snapshot | tail -1)
pip install "https://github.com/llvm/torch-mlir/releases/download/${SNAPSHOT}/torch_mlir-0.0.1-cp39-cp39-linux_x86_64.whl"
