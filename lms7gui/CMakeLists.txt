########################################################################
# LMS7 GUI library component
########################################################################

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

########################################################################
# lms7lib dependency
########################################################################
include_directories(${PROJECT_SOURCE_DIR}/lms7lib/include)
list(APPEND LMS7_GUI_LIBRARIES lms7)
if(BUILD_SHARED_LIBS)
    add_definitions(-DLMS7_DLL)
endif(BUILD_SHARED_LIBS)

########################################################################
# wx dependency
########################################################################
list(APPEND LMS7_GUI_LIBRARIES ${wxWidgets_LIBRARIES})
include(${wxWidgets_USE_FILE})

########################################################################
# fft dependency
########################################################################
add_subdirectory(fft)
include_directories(fft)
list(APPEND LMS7_GUI_LIBRARIES fftviewer)

########################################################################
# build library
########################################################################
file(GLOB LMS7_GUI_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src) #private headers

add_library(lms7gui ${LMS7_GUI_SOURCES})
if(LMS7_GUI_LIBRARIES)
    target_link_libraries(lms7gui ${LMS7_GUI_LIBRARIES})
endif(LMS7_GUI_LIBRARIES)
set_target_properties(lms7gui PROPERTIES SOVERSION ${LIME_SUITE_SOVER})
set_target_properties(lms7gui PROPERTIES VERSION ${LIME_SUITE_LIBVER})
set_target_properties(lms7gui PROPERTIES DEFINE_SYMBOL "LMS7_GUI_DLL_EXPORTS")
set_property(TARGET lms7gui PROPERTY POSITION_INDEPENDENT_CODE TRUE)
