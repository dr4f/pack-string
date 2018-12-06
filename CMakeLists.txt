cmake_minimum_required(VERSION 3.5)

# Project for pack string library #
PROJECT(pack-string)

# Project source files variable #
SET(pack_string_sources
    PackString.cpp
)

# Pack String Custom Definitions #
# 1. PSM_ARRAY_EXP_GROW - Determines if storage grows exponentionally or linearly
###################################
add_definitions(-DPSM_ARRAY_EXP_GROW)

# Built Libraries #
add_library(pack-string-stat STATIC "${pack_string_sources}")
add_library(pack-string-shared SHARED "${pack_string_sources}")

# Enables Testing for project #
enable_testing()

# Pack String Testing Macro #
macro(PACK_STRING_TEST file_name)
add_executable(${file_name} tests/${file_name}.cpp)
target_link_libraries(${file_name} pack-string-stat)
target_include_directories(${file_name} PUBLIC ${PROJECT_SOURCE_DIR})
add_test(${file_name} ${file_name})
endmacro(PACK_STRING_TEST)

PACK_STRING_TEST(test_pack_string)
PACK_STRING_TEST(test_malloc_array)

# Write a small build receipt #
string(TIMESTAMP pack_string_build_time)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/build_receipt.txt "pack-string Built at : ${pack_string_build_time}\n")
