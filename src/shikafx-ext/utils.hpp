#ifndef SHIKAFX_EXTRAS_UTILS
#define SHIKAFX_EXTRAS_UTILS

#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>
#include "./common.hpp"

#define skfx_ext_mod shikafx::ext::utils

namespace skfx_ext_mod {

    auto copy_str(const std::string& val) -> std::string;

    // copy without null terminate
    auto copy_str_to_bytes(const std::string& val) -> byte_t*;

    auto copy_str_to_char_stack_wnt(const std::string& val) -> char*;
    auto copy_str_to_byte_stack_wnt(const std::string& val) -> byte_t*;

    auto copy_str_to_data(const std::string& val) -> data_t*;
    auto cast_str_to_data(const std::string& val) -> data_t*;

    // copy without null terminate
    auto cast_str_to_byte_stack(const std::string& val) -> const byte_t*;

    auto copy_data_to_str(const data_t* data) -> std::string;

    // copy without null terminate
    auto copy_data_to_byte_stack(const data_t* data) -> byte_t*;

    auto copy_data_to_char_stack_wnt(const data_t* data) -> char*;
    auto copy_data_to_byte_stack_wnt(const data_t* data) -> byte_t*;

    auto cast_data_to_str(const data_t* data) -> std::string;

    auto hexdump_view(const byte_t* data, size_t size, int cols = 16) -> void;
    auto hexdump_view(const char* data, size_t size, int cols = 16) -> void;
    auto hexdump_view(const data_t* data, int cols = 16) -> void;
    auto hexdump_view(const std::string& val, int cols = 16) -> void;
}

#endif // SHIKAFX_EXTRAS_UTILS
