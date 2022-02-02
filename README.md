## Description:
A C++ project that contains implementation of various algorithms, containers and solutions for the standard problems.
The project contains a core library and tests that are going to test the library.

## Content:
The project contains implementations for:
1. Algorithms
2. Containers
3. Smart Pointers
4. Multithreading
5. Design patterns
6. Cpp20

## Generate build files:
IMPORTANT: Cmake version 3.21.0 or higher is needed to generate the project.
To generate makefiles from the command line.
From the project root:

    mkdir build
    cd build
    cmake ..

Makefiles should be created.
Now, to compile the executables and link them.

    make

To run all tests easily.

    make test

### Generate Xcode project:
To generate Xcode project from the command line.
From the project root:

    ./build_xcode.cmake

Xcode project should be created in build_xcode folder.
Now, to open the project in Xcode editor.

    open build_xcode/CppTests.xcodeproj
