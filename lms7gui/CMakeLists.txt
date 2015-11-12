########################################################################
# LMS7 GUI library component
########################################################################

########################################################################
## WX dependency
########################################################################
find_package(wxWidgets COMPONENTS richtext xml html xrc adv aui core base gl)
message(STATUS "wxWidgets_FOUND: ${wxWidgets_FOUND}")
message(STATUS "wxWidgets_USE_FILE: ${wxWidgets_USE_FILE}")
message(STATUS "wxWidgets_LIBRARIES: ${wxWidgets_LIBRARIES}")

########################################################################
## Feature registration
########################################################################
include(FeatureSummary)
include(CMakeDependentOption)
cmake_dependent_option(ENABLE_LMS7GUI "Enable LMS7 GUI support library" ON "ENABLE_LMS7LIB;wxWidgets_FOUND" OFF)
add_feature_info(LMS7GUI ENABLE_LMS7GUI "LMS7 GUI support library")
if (NOT ENABLE_LMS7GUI)
    return()
endif()
