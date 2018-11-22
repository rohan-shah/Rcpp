## Cross-Platform Rcpp

This is a severely cut-down version of Rcpp, which excludes almost all the R code. The purpose of this is

1. This version can be compiled as a static library.
2. This version comes with cmake build files.
3. This version compiles with Visual Studio on Windows. 

Although it was always possible to compile R extensions using Visual Studio, this was extremely unpleasant without access to Rcpp. And it is sometimes necessary to use Visual Studio on Windows because

1. The default toolchain on Windows is *bad*. Espceially the debugger, which is unable to even give a stack trace in most cases.
2. Some libraries (Qt, Intels MKL) only work with Visual Studio on Windows, or the work necessary to recompile them is huge. 

Example packages where it was necessary or desirable to use Visual Studio are mpMapInteractive (github) and residualConnectivity (github). 
In the case of mpMapInteractive we use the Qt package, which is extremely complicated. It's hard to debug such a complicated package on Windows without access to a decent compiler / debugger.
In the case of residualConnectivity, this is a Monte Carlo package and performance is important. It also incorporates multithreading andthe Qt library. 

## General Use

Any R package compiled using this static library must

1. Define a variable 'extern "C" char* package_name'. 
2. Include the R file Rcpp_exceptions.R
3. Call R_init_Rcpp from the R_init_* function of your shared library. 

## Windows 

On windows the CMake build scripts are only designed to build a 64-bit version of this package. Supported outputs are Visual Studio solution files and NMake Makefiles. 

### Compiling this package on Windows using Visual Studio

1. Choose a binary directory (E.g. <RcppRoot>/build).
2. Run the cmake gui. 
3. Enter source code directory "<RcppRoot>" and binaries directory (E.g.<RcppRoot>/build). 
4. Set R_COMMAND to <R_HOME>/bin/x64/R.exe. Ensure that you choose the 64-bit version. 
5. If the output is going to be NMake Makefiles, set CMAKE_BUILD_TYPE appropriately (E.g. as either Release or Debug)
6. Hit Configure and when prompted choose a Visual Studio 64-bit output, or NMake Makefiles.
7. When configuring succeeds, hit generate. 

The configuration scripts generate an import library for R.dll. This means that the scripts must be able to run cl.exe and lib.exe. If this step fails, check that cl.exe and lib.exe can run. If not, you may need to set up the correct environment for the compiler (by running a script such as vcvarsx86_amd64.bat) before running cmake.

### Linking against this package on Windows

1. Run the cmake gui.
2. Add variable Rcpp_DIR and enter the value for the Rcpp binary directory (E.g. <RcppRoot>/build)
3. Hit Configure and choose a Visual Studio 64-bit output, or NMake Makefiles. 

## Linux

### Compiling this package on Linux

1. Choose a binary directory (E.g. <RcppRoot>/build).
2. Change directory to the binary directory.
3. Run cmake <RcppRoot>. The configure script will attempt to locate R by itself. If it cannot be found, specifying the variable R_COMMAND (the command that runs R) by adding -DR_COMMAND=<..> to the cmake command. 

### Linking against this package on Linux

Add -DRcpp_DIR=<...> followed by the binary directory to your call to cmake. 

## OS X

Compilation on OS X is untested. 

## Credit

This package was originally branched from commit 4f168e68e7fe5ee45b3e292979ec23d0fcbf80d3 of Rcpp, which is written by Dirk Eddelbuettel, Romain Francois, JJ Allaire, Kevin Ushey, Doug Bates, and John Chambers
