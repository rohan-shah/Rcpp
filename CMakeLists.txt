project(Rcpp)
cmake_minimum_required(VERSION 3.1)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(R REQUIRED)

set(SourceFiles api.cpp attributes.cpp barrier.cpp Date.cpp extra_math_functions.cpp Module.cpp Rcpp_init.cpp)
set(HeaderFiles extra_math_functions.h internal.h msc_inttypes.h msc_unistd.h)
add_library(Rcpp STATIC ${SourceFiles} ${HeaderFiles})
target_include_directories(Rcpp PUBLIC ${PROJECT_SOURCE_DIR}/include ${R_INCLUDE_DIR})
set_property(TARGET Rcpp PROPERTY POSITION_INDEPENDENT_CODE ON)

find_package(R REQUIRED)

set(RCPP_LIB_FILE $<TARGET_FILE:Rcpp>)
configure_file(${PROJECT_SOURCE_DIR}/RcppConfig.cmake.in ${PROJECT_BINARY_DIR}/RcppConfig.cmake @ONLY)
if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
	#Add a define to account for different name of certain function
	add_definitions(-Dsnprintf=_snprintf)

	target_compile_definitions(Rcpp PUBLIC _CRT_SECURE_NO_WARNINGS)
else()
	file(GENERATE OUTPUT ${PROJECT_BINARY_DIR}/RcppConfig.cmake INPUT ${PROJECT_BINARY_DIR}/RcppConfig.cmake)
endif()
