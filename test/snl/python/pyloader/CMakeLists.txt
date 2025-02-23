# SPDX-FileCopyrightText: 2023 The Naja authors <https://github.com/xtofalex/naja/blob/main/AUTHORS>
#
# SPDX-License-Identifier: Apache-2.0

INCLUDE(GoogleTest)

SET(snl_pyloader_tests
  SNLPyDBLoaderTest0.cpp
  SNLPrimitivesTest0.cpp
)

ADD_EXECUTABLE(snlPyLoaderTests ${snl_pyloader_tests})
target_compile_definitions(snlPyLoaderTests PRIVATE
  SNL_PRIMITIVES_TEST_PATH="${CMAKE_CURRENT_SOURCE_DIR}")
TARGET_LINK_LIBRARIES(snlPyLoaderTests naja_snl_pyloader gtest gmock gtest_main)

gtest_discover_tests(
  snlPyLoaderTests
  PROPERTIES ENVIRONMENT
  PYTHONPATH=${PROJECT_BINARY_DIR}/src/snl/python/snl_wrapping
)

SET(snl_pyedit_tests
  SNLPyEditTest0.cpp
)

ADD_EXECUTABLE(snlPyEditTests ${snl_pyedit_tests})
target_compile_definitions(snlPyEditTests PRIVATE
  SNL_PYEDIT_TEST_PATH="${CMAKE_CURRENT_SOURCE_DIR}")
TARGET_LINK_LIBRARIES(snlPyEditTests naja_snl_pyloader gtest gmock gtest_main)
gtest_discover_tests(
  snlPyEditTests
  PROPERTIES ENVIRONMENT
  PYTHONPATH=${PROJECT_BINARY_DIR}/src/snl/python/snl_wrapping
)