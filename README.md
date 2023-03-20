# Branch to build Flash Algo for micro:bit V2 with nRF52833 target

This branch has been created to build the Flash Algo for nRF52833 that will
be used for DAPLink, specifically for the micro:bit DAPLink build.

The changes in the branch from upstream are:
- Added unmerged PR setting GCC optimisation level to `Os`: https://github.com/pyocd/FlashAlgo/pull/67
- Added the build output files
- Updated this README

The build was done using the `ghcr.io/microbit-foundation/daplink:2022.01.1` docker image, which uses GCC v10.3:

```
$ docker run -v $(pwd):/home --rm ghcr.io/microbit-foundation/daplink:2022.01.1 arm-none-eabi-gcc --version
arm-none-eabi-gcc (GNU Arm Embedded Toolchain 10.3-2021.07) 10.3.1 20210621 (release)
Copyright (C) 2020 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

Build command and output:

```
$ docker run -v $(pwd):/home --rm ghcr.io/microbit-foundation/daplink:2022.01.1 progen build -v -t make_gcc_arm nrf52833
progen DEBUG    This should be the project root: /home
progen.tools DEBUG      Generating: projectfiles/make_gcc_arm/nrf52833/Makefile
progen.project DEBUG    Building for tool: make_gcc_arm
progen.project DEBUG    {'make_gcc_arm': {'path': 'projectfiles/make_gcc_arm/nrf52833', 'files': {'makefile': 'projectfiles/make_gcc_arm/nrf52833/Makefile'}}}
progen.tools.gccarm DEBUG       Building make project: projectfiles/make_gcc_arm/nrf52833
progen.tools.gccarm DEBUG       ['make', '-j', '1', 'all']
Preprocessing ../../../source/FlashAlgo.ld
Compiling ../../../source/nordic/nrf52833/FlashDev.c
Compiling ../../../source/nordic/nrf52833/FlashPrg.c
Linking build/nrf52833.elf
Memory region         Used Size  Region Size  %age Used
   text    data     bss     dec     hex filename
   4604       0       0    4604    11fc build/nrf52833.elf
   4604       0       0    4604    11fc (TOTALS)
Converting build/nrf52833.hex
Converting build/nrf52833.bin
progen.tools.gccarm INFO        Built nrf52833 with the status: no errors
```

Blobs generation:

```
$ docker run -v $(pwd):/home --rm ghcr.io/microbit-foundation/daplink:2022.01.1 python scripts/generate_blobs.py projectfiles/make_gcc_arm/nrf52833/build/nrf52833.elf --blob_start 0x20000000
Flash Device:
  name=b'nRF52833'
  version=0x101
  type=1
  start=0x0
  size=0x80000
  page_size=0x4
  value_empty=0xff
  prog_timeout_ms=100
  erase_timeout_ms=3000
  sectors:
    start=0x0, size=0x80000
    start=0x10001000, size=0x308
```


-----

# FlashAlgo

Framework for building Arm "FLM" style flash programming algorithms.


## Other options

Before you consider adding a flash algo here, you might wish to check if an open source flash algo already exists
for your device or a similar device. Many of the FLM flash algos included in CMSIS Device Family Packs (DFPs) come with source code. For instance, the Keil DFPs include sources.

You can download a DFP for your device from the official CMSIS-Pack list: [by pack](https://www.keil.com/dd2/pack/) or [by part number](https://www.keil.com/dd2/).

DFPs extract as zips (change the extension). For the DFPs created by Keil, .FLM algos and code are under `./CMSIS/Flash/`. Other vendors may have algos in a different folder, and may or may not include source.


## Development Setup

Skip any step where a compatible tool already exists

1. Install [Python 3.6 or later](https://www.python.org/downloads/) and make sure it's added to path
2. Install [Git](https://git-scm.com/downloads) and make sure it's added to path
3. Install a supported toolchain:
    1. [GNU Arm Embedded](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm)
    2. [Keil MDK-ARM](https://www.keil.com/download/product/)
4. Install GNU Make.

```
$ git clone https://github.com/mbedmicro/FlashAlgo
$ python3 -mvenv venv
$ source venv/bin/activate
$ pip install -r requirements.txt
```

## Develop

### GCC with Make

1. Update tools and generate project files. This should be done everytime you pull new changes

```
$ progen build -t make_gcc_arm
```

Add the project name(s) to the command if you only want to build a limited set of projects. You can list available projects with `progen list -f projects.yaml projects`.

### MDK

```
$ progen generate -t uvision
$ tools\launch_uvision.bat

```
Now open the project file for the desired target in `.\projectfiles\uvision\<target>\`

To change the RAM base address to something other than the default value of 0x20000000, add the argument `--blob_start <hex-ram-address>` in "Projects ❱ Options ❱ User ❱ After Build/Rebuild section of the µVision project.


## Adding a new project

For adding new targets start from template and use these docs...

## Contributions

We welcome contributions! Please see the [contribution guidelines](CONTRIBUTING.md) for detailed requirements.
In order to foster a healthy and safe community, all contributors are expected to follow the
[code of conduct](CODE_OF_CONDUCT.md).

To report bugs, please [create an issue](https://github.com/pyocd/FlashAlgo/issues/new) in the GitHub project.


