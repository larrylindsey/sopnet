cmake_minimum_required(VERSION 2.6)
include(${CMAKE_SOURCE_DIR}/cmake/include/define_module.cmake)

#######################
# project information #
#######################

project(sopnet)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)

###############
# config file #
###############

configure_file(
  ${PROJECT_SOURCE_DIR}/cmake/config.h.in
  ${PROJECT_BINARY_DIR}/config.h
)

#####################
# compiler settings #
#####################

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -Wextra -fomit-frame-pointer")
set(CMAKE_CXX_FLAGS_DEBUG   "-g -Wall -Wextra")
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Release or Debug" FORCE)
endif()

#######################
# project directories #
#######################

include_directories(${PROJECT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})

# does not include modules/catmaidsopnet
add_subdirectory(modules)

add_subdirectory(sopnet)

# catmaidsopnet depends on sopnet
add_subdirectory(modules/catmaidsopnet)

add_subdirectory(pysopnet)

add_subdirectory(binaries)
