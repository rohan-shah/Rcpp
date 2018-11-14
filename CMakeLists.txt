project(Rcpp)
cmake_minimum_required(VERSION 3.1)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(R REQUIRED)

set(SourceFiles api.cpp attributes.cpp barrier.cpp Date.cpp extra_math_functions.cpp Module.cpp Rcpp_init.cpp)
set(HeaderFiles extra_math_functions.h internal.h msc_inttypes.h msc_unistd.h)
add_library(Rcpp STATIC ${SourceFiles} ${HeaderFiles})
#POSITION_INDEPENDENT_CODE is not  relevant for windows
set_property(TARGET Rcpp PROPERTY POSITION_INDEPENDENT_CODE True)
target_include_directories(Rcpp PUBLIC ${PROJECT_SOURCE_DIR}/include ${R_INCLUDE_DIR})

find_package(R REQUIRED)

set(RCPP_LIB_FILE $<TARGET_FILE:Rcpp>)
configure_file(${PROJECT_SOURCE_DIR}/RcppConfig.cmake.in ${PROJECT_BINARY_DIR}/RcppConfig.cmake @ONLY)
if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
	if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "19.0")
		#Add a define to account for different name of certain function
		add_definitions(-Dsnprintf=_snprintf)
	endif()

	target_compile_definitions(Rcpp PUBLIC _CRT_SECURE_NO_WARNINGS)
else()
	#The string "$<TARGET_FILE:Rcpp>" was stored into the variable RCPP_LIB_FILE, so it's now present as a string in the file ${PROJECT_BINARY_DIR}/RcppConfig.cmake. This command actually expands it. 
	file(GENERATE OUTPUT ${PROJECT_BINARY_DIR}/RcppConfig.cmake INPUT ${PROJECT_BINARY_DIR}/RcppConfig.cmake)
endif()
