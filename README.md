##Cross-Platform Rcpp

This is a severely cut-down version of Rcpp, which excludes almost all the R code. The purpose of this is

1. This version can be compiled as a static library.
2. This version comes with cmake build files.
3. This version compiles with Visual Studio on Windows. 

Although it was always possible to compile R extensions using Visual Studio, this was extremely unpleasant without access to Rcpp. And it is sometimes necessary to use Visual Studio on Windows because

1. The default toolchain on Windows is *bad*. Espceially the debugger, which is unable to even give a stack trace in most cases.
2. Some libraries (Qt, Intels MKL) only work with Visual Studio on Windows, or the work necessary to recompile them is huge. 

Example packages where it was necessary or desirable to use Visual Studio are mpMapInteractive (github) and the residualConnectivity. 
In the case of mpMapInteractive we use the Qt package, which is extremely complicated. It's hard to debug such a complicated package on Windows without access to a decent compiler / debugger.
In the case of residualConnectivity, this is a Monte Carlo package and performance is important. It also incorporates multithreading andthe Qt library. 

##General Use

For an example of the general package lay-out required to link against this static library, see package mpMapInteractive on github. Any R package compiled using this static library must

1. Define a variable 'extern "C" char* package_name'. 
2. Include the R file Rcpp_exceptions.R
3. Call R_init_Rcpp from the R_init_* function of your shared library. 

##Windows 

On windows the src/Makefile.in is converted by CMake to a file src/Makefile.win, which redirects the package build command to the binary directory.

###Compiling this package on windows

1. Choose a binary directory (I use <RcppRoot>/build but anything will do).
2. Run the cmake gui. 
3. Enter source code directory "<RcppRoot>" and binaries directory "<RcppRoot>/build". 
4. Hit Configure and choose a 64-bit Visual Studio project. Cmake must be able to find R.exe. If it can't you need to add a directory to your PATH and restart the cmake gui. 
5. When configuring succeeds, hit generate. 
6. Open <RcppRoot>/build/Rcpp.sln and compile debug and release versions. 

###Linking against this package on windows

1. Run the cmake gui FROM A VISUAL STUDIO TOOLS COMMAND PROMPT. 
2. Add variable Rcpp_DIR with value "<RcppRoot>/build"
3. Hit Configure and choose NMake makefiles. 
4. You can now build the binary parts of the package by either running nmake from "<PackageRoot>/src/build" or by running "R CMD INSTALL <PackageRoot>". 

##Credit

This package was originally branched from commit 4329fa51b4cb92387f79000e7005e6f4798caed6 of Rcpp, which is written by Dirk Eddelbuettel, Romain Francois, JJ Allaire, Kevin Ushey, Doug Bates, and John Chambers
