########################################################################
# LMS7 driver library component
########################################################################

########################################################################
## Feature registration
########################################################################
include(FeatureSummary)
include(CMakeDependentOption)
cmake_dependent_option(ENABLE_LMS7LIB "Enable LMS7 driver support library" ON "TRUE" OFF)
add_feature_info(LMS7LIB ENABLE_LMS7LIB "LMS7 driver support library")
if (NOT ENABLE_LMS7LIB)
    return()
endif()

