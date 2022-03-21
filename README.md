# torch-onnx

## Setup

Current state and overview:
* Bazel can build torch_mlir, but I don't know how to extract the Python packages
  that it builds for use in other things.
* So we're using Bazel to manage just the C++ code and using `pip` to install the
  python packages.

### Create Anaconda environment

Create a new [anaconda](https://anaconda.org) environment for this repo and activate it.
You may find [direnv](https://direnv.net/) handy for automatically activating and
deactivating the environment: `layout anaconda <env name>`.

### Install dependencies

```sh
git submodule update --init --recursive
conda config --add channels conda-forge
conda config --set channel_priority strict
# 3.9 to be compatible with torch-mlir pip packages.
conda install -c conda-forge bazel buildifier python=3.9
# So that python can find libpython.
# I think the better way to handle this would be to set LD_LIBRARY_PATH="${CONDA_PREFIX}/lib",
# but then I hit this issue: https://stackoverflow.com/questions/51408698.
sudo apt-get install libpython3.9
# ensure python is the one from conda env. If it's not, deactivate and activate.
which python
third_party/pip_install.sh
```

### Build and test

Build torch-mlir:

```sh
bazel build //third_party:torch_mlir
```

Test Python is set up properly:

```sh
python third_party/torch-mlir/python/test/annotations-sugar.py
```
