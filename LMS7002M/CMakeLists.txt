########################################################################
# Project setup
########################################################################
cmake_minimum_required(VERSION 2.8)
project(LimeSuite)
enable_language(CXX)
enable_testing()

#LIME_SUITE_LIBVER is a formal release version
set(LIME_SUITE_LIBVER "2015.11.0")

#LIME_SUITE_SOVER is an ABI compatibility number
set(LIME_SUITE_SOVER "0")

########################################################################
# select the release build type by default to get optimization flags
########################################################################
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE "Release")
   message(STATUS "Build type not specified: defaulting to release.")
endif(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")

########################################################################
# compiler flags
########################################################################
if(CMAKE_COMPILER_IS_GNUCXX)
    #force a compile-time error when symbols are missing
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")

    #common warnings to help encourage good coding practices
    add_compile_options(-Wall)
    add_compile_options(-Wextra)

    #symbols are only exported from libraries/modules explicitly
    add_compile_options(-fvisibility=hidden)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility-inlines-hidden")
endif()

########################################################################
# add components
########################################################################
add_subdirectory(lms7lib)
add_subdirectory(lms7gui)

########################################################################
# summary
########################################################################
include(FeatureSummary)
message(STATUS "")
message(STATUS "######################################################")
message(STATUS "## ${PROJECT_NAME} enabled features")
message(STATUS "######################################################")
feature_summary(WHAT ENABLED_FEATURES)
message(STATUS "######################################################")
message(STATUS "## ${PROJECT_NAME} disabled features")
message(STATUS "######################################################")
feature_summary(WHAT DISABLED_FEATURES)
message(STATUS "Install prefix: ${CMAKE_INSTALL_PREFIX}")
