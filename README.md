# torch-onnx

## Setup

### Create Anaconda environment

Create a new [anaconda](https://anaconda.org) environment for this repo and activate it.
You may find [direnv](https://direnv.net/) handy for automatically activating and
deactivating the environment: `layout anaconda <env name>`.

### Install dependencies

```sh
git submodule update --init --recursive
conda install -c conda-forge bazel buildifier python
# ensure python is the one from conda env
which python
pip install -r third_party/torch-mlir/requirements.txt
```

### Build and test

TODO
