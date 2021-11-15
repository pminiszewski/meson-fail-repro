Environment: 
OS: Windows 10
Meson: 0.60.1
Ninja: 1.10.2
Python: Python 3.8.2

Scenario: Using custom targets to generate protobuf messages. Generated code should be turned into reusable dependency that can be easily referenced by other targets. Furthermore generated protobuf headers should also be installed as they are part of the SDK API.

Problem:

The project will fail if more than one job is used during compilation. Ninja will compile sources depending on protobuf messages before actually running protoc and generating required code. This problem does not appear when generator is used instead of custom target.


To reproduce:

1. clone this repo
2. `meson setup build`
3. `meson compile -C build -j16`

Result: Compilation will fail with error: 
`../src/runtime/src/main.cpp(5): fatal error C1083: Cannot open include file: 'hello.pb.h': No such file or directory`

build again but use only one job:
1. `meson setup --wipe build`
2. `meson compile -C build -j1`

Result: Compilation will succeed.

Expected behavior:
Meson succeeds regardless of number of parallel jobs.