#  @file CMakeLists.txt
#  @author Gaspard Kirira
#
#  Copyright 2025, Gaspard Kirira. All rights reserved.
#  https://github.com/vixcpp/vix
#  Use of this source code is governed by a MIT license
#  that can be found in the License file.
#
#  @brief Vix AI Distributed module.
#
#  Header-only distributed AI module for Vix.
#  Provides primitives for peer-to-peer communication, secure channels,
#  and federated learning workflows.
#
#  Public targets:
#    - vix_ai_distributed
#    - vix::ai::distributed
#
#  Installation:
#    Installs headers, exported targets, and CMake package files
#    for find_package(vix_ai_distributed CONFIG REQUIRED).

cmake_minimum_required(VERSION 3.20)

project(vix_ai_distributed VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(VIX_AI_DISTRIB_BUILD_TESTS "Build vix_ai_distributed tests" OFF)
option(VIX_AI_DISTRIB_INSTALL "Install vix_ai_distributed targets" ON)
option(VIX_AI_DISTRIB_WARNINGS "Enable extra warnings for vix_ai_distributed" ON)

if(DEFINED VIX_AI_VERSION)
  set(PROJECT_VERSION ${VIX_AI_VERSION})
endif()

add_library(vix_ai_distributed INTERFACE)
add_library(vix::ai::distributed ALIAS vix_ai_distributed)

target_include_directories(vix_ai_distributed INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(vix_ai_distributed INTERFACE cxx_std_20)

target_compile_definitions(vix_ai_distributed INTERFACE
  VIX_AI_DISTRIB_VERSION="${PROJECT_VERSION}"
)

if(VIX_AI_DISTRIB_WARNINGS)
  if(MSVC)
    target_compile_options(vix_ai_distributed INTERFACE /W4 /permissive-)
  else()
    target_compile_options(vix_ai_distributed INTERFACE
      -Wall
      -Wextra
      -Wpedantic
    )
  endif()
endif()

if(VIX_AI_DISTRIB_BUILD_TESTS AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt")
  include(CTest)
  enable_testing()
  add_subdirectory(test)
endif()

if(VIX_AI_DISTRIB_INSTALL)
  install(TARGETS vix_ai_distributed
    EXPORT vix_ai_distributedTargets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

  install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h"
  )

  install(EXPORT vix_ai_distributedTargets
    FILE vix_ai_distributedTargets.cmake
    NAMESPACE vix::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_distributed
  )

  configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/vix_ai_distributedConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_distributedConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_distributed"
  )

  write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_distributedConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
  )

  install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_distributedConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/vix_ai_distributedConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_distributed"
  )
endif()

message(STATUS "vix::ai::distributed configured (${PROJECT_VERSION})")
message(STATUS "Include dir: ${CMAKE_CURRENT_SOURCE_DIR}/include")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Install: ${VIX_AI_DISTRIB_INSTALL}")
message(STATUS "Tests: ${VIX_AI_DISTRIB_BUILD_TESTS}")
