# torch-onnx

## Setup

### Create Anaconda environment

Create a new [anaconda](https://anaconda.org) environment for this repo and activate it.
You may find [direnv](https://direnv.net/) handy for automatically activating and
deactivating the environment: `layout anaconda <env name>`.

TODO: Make the environment in subdirectory of the repo.
Add that directory to gitignore.
Then we can check in the VSCode settings that refer to that environment.

### Install dependencies

apt version
```sh
sudo apt install libstdc++-10-dev clang-12 lld-12
sudo ln -s clang-12 $(dirname $(which clang-12))/clang
sudo ln -s clang++-12 $(dirname $(which clang++-12))/clang++
sudo ln -s lld-12 $(dirname $(which lld-12))/lld
```

conda version, not working, but I'd like it to.
```sh
conda install -c conda-forge libgcc clang lld
```

```sh
git submodule update --init --recursive
conda config --add channels conda-forge
conda config --set channel_priority strict
# 3.9 to be compatible with torch-mlir pip packages.
conda install -c conda-forge cmake ninja python=3.9
# So that python can find libpython.
# I think the better way to handle this would be to set LD_LIBRARY_PATH="${CONDA_PREFIX}/lib",
# but then I hit this issue: https://stackoverflow.com/questions/51408698.
sudo apt-get install libpython3.9
# ensure python is the one from conda env. If it's not, deactivate and activate.
[[ -z $(which python | grep ${CONDA_PREFIX}) ]] && echo "You need to reactivate conda"
```

Once you're sure you've got the right Python in use, install additional third-party dependencies:
```sh
third_party/pip_install.sh
```


### Build and test

Build torch-mlir:

```sh
cmake -G Ninja -B build -DCMAKE_C_COMPILER:FILEPATH=clang -DCMAKE_CXX_COMPILER:FILEPATH=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=ON -DCMAKE_EXE_LINKER_FLAGS_INIT="-fuse-ld=lld" -DCMAKE_MODULE_LINKER_FLAGS_INIT="-fuse-ld=lld" -DCMAKE_SHARED_LINKER_FLAGS_INIT="-fuse-ld=lld"
cmake --build build
```

Test Python is set up properly:

```sh
python third_party/torch-mlir/python/test/annotations-sugar.py
```
