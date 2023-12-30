# Continuous Deployment of QT Wasm Application using Github Actions

## Introduction

[Insert introduction here]

## Background

### AQT install

[Another QT installer (AQT)](https://github.com/miurahr/aqtinstall) is an inofficial command line interface (CLI) tool for downloading prebuilt Qt binaries, documents and sources. It is an alternative to using the official graphical Qt installer or building QT from [source](https://github.com/qt/qt5).

AQT is a Python program and can be installed using the pip package manager.
```bash
pip install aqtinstall
```

AQT is used to install qt as following: 
```bash
python -m aqt install-qt <HOST> <PLATFORM> <VERSION> <ARCH> -O <OUTPUT_DIR>
```

| KEY          | Examples                                  | Description                                       |
| ------------ | ----------------------------------------- | ------------------------------------------------- |
| `<HOST>`     | `linux`, `windows` or `mac`               | The operating system that is used for development |
| `<PLATFORM>` | `desktop`, `ios`, `winrt`, or `android`   | The type of device that is used for development   |
| `<VERSION>`  | `5.9.7`, `5.12.1`, etc                    | The QT Version                                    |
| `<ARCH>`     | `gcc_64`, `clang_64`, `wasm_singlethread` | The compile target architecture                   |
| `<OUTPUT_DIR>` | `.qt`                                   | The directory that QT is installed to             |

Be aware that not all combinations of parameters are possible as this is dependend on the availability of precompiled binaries on the Qt distribution site and its mirror. Luckily AQT offers a possiblity to check the availability via the following command. You have the flexibility to omit parameters from the right side, allowing you to obtain a list of potential options for the first missing parameter.

```bash
python -m aqt list-qt <HOST> <PLATFORM> <VERSION> <ARCH>
```

### Emscripten (WebAssembly compiler)

Emscripten compiles C and C++ to WebAssembly, which can run in web browsers such as Chrome.
It is distributed in the [Emscripten SDK (EMSDK)](https://github.com/emscripten-core/emsdk) with contains all required compilation tools.

EMSDK can be cloned from its official github reporsitory and then be used to install the required version of Emscripten.
```bash
git clone https://github.com/emscripten-core/emsdk.git .emsdk
.emsdk/emsdk install <VERSION>
```

For information on the required Emscripten version for each version of QT, please consult the [QT5](https://doc.qt.io/qt-5/wasm.html) or [QT6](https://doc.qt.io/qt-6/wasm.html) documentation.

Before Emscripten can be used the respective version needs to be activated with the following command.
```bash
.emsdk/emsdk activate <VERSION>
```

On Windows hosts this command adds all relevant Emscripten Tools such as `EMCC`, `EMCMAKE` and `EMRUN` to path. On Linux hosts the following command must be executed additionally.
```bash
source .emsdk/emsdk_env.sh
```

## Implementation

### Create CMAKE Project using QT

[Insert content for section 2 here]

### Helper script for local compilation

### Create Github Action

## Conclusion

[Insert conclusion here]

## Reference

[Insert any references or citations here]

## Info

```json
{
    "author": "Fabian Segatz",
    "title": "Continuous Deployment of QT Wasm Application using Github Actions",
    "date": "2023-11-15"
    "version": "0.0.1",
    "description": "",
    "tag": ["ci", "cd", "qt", "wasm", "c++", "cmake", "gui"]
}
```



