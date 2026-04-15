cmake_minimum_required(VERSION 3.20)

#  @file test/CMakeLists.txt
#  @author Gaspard Kirira
#
#  Copyright 2025, Gaspard Kirira. All rights reserved.
#  https://github.com/vixcpp/vix
#  Use of this source code is governed by a MIT license
#  that can be found in the License file.
#
#  @brief Tests for the vix_ai_distributed module.
#
#  Minimal assert-based tests for the distributed AI module.
#  Each test is built as a small executable and registered with CTest.

add_executable(vix_ai_distrib_test_peer
  peer_tests.cpp
)
target_link_libraries(vix_ai_distrib_test_peer
  PRIVATE
    vix::ai::distributed
)
target_compile_features(vix_ai_distrib_test_peer PRIVATE cxx_std_20)
add_test(NAME distrib_peer COMMAND vix_ai_distrib_test_peer)
set_tests_properties(distrib_peer PROPERTIES LABELS "distributed;peer")

add_executable(vix_ai_distrib_test_secure
  secure_tests.cpp
)
target_link_libraries(vix_ai_distrib_test_secure
  PRIVATE
    vix::ai::distributed
)
target_compile_features(vix_ai_distrib_test_secure PRIVATE cxx_std_20)
add_test(NAME distrib_secure COMMAND vix_ai_distrib_test_secure)
set_tests_properties(distrib_secure PROPERTIES LABELS "distributed;secure")

add_executable(vix_ai_distrib_test_fl
  fl_tests.cpp
)
target_link_libraries(vix_ai_distrib_test_fl
  PRIVATE
    vix::ai::distributed
)
target_compile_features(vix_ai_distrib_test_fl PRIVATE cxx_std_20)
add_test(NAME distrib_fl COMMAND vix_ai_distrib_test_fl)
set_tests_properties(distrib_fl PROPERTIES LABELS "distributed;federated")

add_executable(vix_ai_distrib_test_sync
  sync_tests.cpp
)
target_link_libraries(vix_ai_distrib_test_sync
  PRIVATE
    vix::ai::distributed
)
target_compile_features(vix_ai_distrib_test_sync PRIVATE cxx_std_20)
add_test(NAME distrib_sync COMMAND vix_ai_distrib_test_sync)
set_tests_properties(distrib_sync PROPERTIES LABELS "distributed;sync")
