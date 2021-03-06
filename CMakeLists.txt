cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(SCHNApps
	LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")
set(CGAL_DONT_OVERRIDE_CMAKE_FLAGS TRUE CACHE BOOL "preserve cmake flags" FORCE)

#### Default build type
if(NOT CMAKE_BUILD_TYPE AND NOT MSVC)
	set(CMAKE_BUILD_TYPE "Release")
endif()

#### Numerical precision
option(SCHNAPPS_DOUBLE_PRECISION "Use double precision." ON)

#### Aligned Vector3
option(SCHNAPPS_ALIGNED_VEC3 "Use Eigen's AlignedVector3 by default." OFF)

#### SCHNAPPS PATH / SCHNAPPS_SOURCE_DIR
set(SCHNAPPS_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(SCHNAPPS_SOURCE_DIR ${SCHNAPPS_PATH})

#### CGOGN_PATH / CGOGN_SOURCE_DIR
set(CGOGN_PATH "${SCHNAPPS_PATH}/../CGoGN_2" CACHE PATH "CGoGN root dir")
set(CGOGN_BUILD_PATH "${SCHNAPPS_PATH}/../CGoGN_2-build" CACHE PATH "CGoGN build or install dir")

set(CGOGN_SOURCE_DIR ${CGOGN_PATH})

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CGOGN_BUILD_PATH})

#### Build configuration
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

include(${CGOGN_PATH}/cmake/utilities.cmake)

if(MSVC)
	add_flags(CMAKE_CXX_FLAGS "/bigobj")
endif()

add_subdirectory(${SCHNAPPS_SOURCE_DIR}/schnapps)
