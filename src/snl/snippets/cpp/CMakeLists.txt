# SPDX-FileCopyrightText: 2023 The Naja authors <https://github.com/xtofalex/naja/blob/main/AUTHORS>
#
# SPDX-License-Identifier: Apache-2.0

add_executable(snl_snippet
  ${PROJECT_SOURCE_DIR}/src/snl/snippets/app/src/SNLUniverseSnippet.cpp
  ${PROJECT_SOURCE_DIR}/src/snl/snippets/app/src/SNLSnippet.cpp
)
add_executable(snl_receiver
  ${PROJECT_SOURCE_DIR}/src/snl/snippets/app/src/SNLUniverseSnippet.cpp
  ${PROJECT_SOURCE_DIR}/src/snl/snippets/app/src/SNLReceiver.cpp
)
add_executable(snl_sender
  ${PROJECT_SOURCE_DIR}/src/snl/snippets/app/src/SNLUniverseSnippet.cpp
  ${PROJECT_SOURCE_DIR}/src/snl/snippets/app/src/SNLSender.cpp
)

target_link_libraries(snl_snippet naja_snl)
target_link_libraries(snl_receiver naja_snl_dump)
target_link_libraries(snl_sender naja_snl_dump)