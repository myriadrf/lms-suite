########################################################################
# LMS7 driver library component
########################################################################

########################################################################
## Feature registration
########################################################################
include(FeatureSummary)
include(CMakeDependentOption)
cmake_dependent_option(ENABLE_LMS7LIB "Enable LMS7 driver support library" ON "TRUE" OFF)
add_feature_info(LMS7LIB ENABLE_LMS7LIB "LMS7 driver support library (v${LIME_SUITE_LIBVER})")
if (NOT ENABLE_LMS7LIB)
    return()
endif()

########################################################################
# pthread dependency
########################################################################
if (UNIX)
    set(CMAKE_THREAD_PREFER_PTHREAD ON)
    find_package(Threads)
    list(APPEND LMS7_LIBRARIES ${CMAKE_THREAD_LIBS_INIT})
endif()

########################################################################
# build library
########################################################################
file(GLOB LMS7_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src) #private headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include) #public headers

if(BUILD_SHARED_LIBS)
    add_definitions(-DLMS7_DLL)
endif(BUILD_SHARED_LIBS)

add_library(lms7 ${LMS7_SOURCES})
if(LMS7_LIBRARIES)
    target_link_libraries(lms7 ${LMS7_LIBRARIES})
endif(LMS7_LIBRARIES)
set_target_properties(lms7 PROPERTIES SOVERSION ${LIME_SUITE_SOVER})
set_target_properties(lms7 PROPERTIES VERSION ${LIME_SUITE_LIBVER})
set_target_properties(lms7 PROPERTIES DEFINE_SYMBOL "LMS7_DLL_EXPORTS")
set_property(TARGET lms7 PROPERTY POSITION_INDEPENDENT_CODE TRUE)

########################################################################
# install library
########################################################################
install(TARGETS lms7
    LIBRARY DESTINATION lib${LIB_SUFFIX} # .so file
    ARCHIVE DESTINATION lib${LIB_SUFFIX} # .lib file
    RUNTIME DESTINATION bin              # .dll file
)

########################################################################
# install headers
########################################################################
install(DIRECTORY include/lms7 DESTINATION include)
