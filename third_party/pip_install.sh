#!/usr/bin/env bash
set -o errexit
set -o pipefail

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

pip install -r "${SCRIPT_DIR}/torch-mlir/requirements.txt"
