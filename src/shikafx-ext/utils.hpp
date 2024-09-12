#ifndef SHIKAFX_EXTRAS_UTILS
#define SHIKAFX_EXTRAS_UTILS

#include <iostream>
#include <string>
#include <bitset>
#include <iomanip>
#include "./common.hpp"

#define skfx_ext_mod shikafx::ext::utils

// short using
#define skx_copy_str skfx_ext_mod::copy_str
#define skx_cast_str_to_bytes skfx_ext_mod::cast_str_to_bytes
#define skx_cast_str_to_data skfx_ext_mod::cast_str_to_data
#define skx_copy_str_to_bytes skfx_ext_mod::copy_str_to_bytes
#define skx_copy_str_to_chars skfx_ext_mod::copy_str_to_chars
#define skx_copy_str_to_data skfx_ext_mod::copy_str_to_data
#define skx_cast_data_to_bytes skfx_ext_mod::cast_data_to_bytes
#define skx_copy_data_to_bytes skfx_ext_mod::copy_data_to_bytes
#define skx_copy_data_to_chars skfx_ext_mod::copy_data_to_chars
#define skx_copy_data_to_str skfx_ext_mod::copy_data_to_str
#define skx_hexdump_view skfx_ext_mod::hexdump_view

namespace skfx_ext_mod {

    auto copy_str(const std::string& val) -> std::string;
    auto cast_str_to_bytes(const std::string& val) -> const byte_t*;
    auto cast_str_to_data(const std::string& val) -> const data_t*;
    auto copy_str_to_bytes(const std::string& val) -> byte_t*;
    auto copy_str_to_chars(const std::string& val) -> char*;
    auto copy_str_to_data(const std::string& val) -> data_t*;
    auto cast_data_to_bytes(const data_t* data) -> const byte_t*;
    auto copy_data_to_bytes(const data_t* data) -> byte_t*;
    auto copy_data_to_chars(const data_t* data) -> char*;
    auto copy_data_to_str(const data_t* data) -> std::string;

    auto hexdump_view(const byte_t* data, size_t size, int cols = 16) -> void;
    auto hexdump_view(const char* data, size_t size, int cols = 16) -> void;
    auto hexdump_view(const data_t* data, int cols = 16) -> void;
    auto hexdump_view(const std::string& val, int cols = 16) -> void;
}

#endif // SHIKAFX_EXTRAS_UTILS
