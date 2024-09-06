#ifndef SHIKAFX_EXTRAS_WRAPPER
#define SHIKAFX_EXTRAS_WRAPPER

#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <memory>
#include "./__ccode__/preload.h"
#include "./common.hpp"

auto skx_make_shared(const char* data) -> std::shared_ptr<char>;
auto skx_make_shared(const byte_t* data) -> std::shared_ptr<byte_t>;
auto skx_make_shared(const data_t* data, bool drop_field = true) -> std::shared_ptr<data_t>;
auto skx_make_shared(const base64_data_t* base64_data, bool drop_field = true) -> std::shared_ptr<base64_data_t>;
auto skx_make_shared(const base64_calc_size_t* base64_calc_size) -> std::shared_ptr<base64_calc_size_t>;

#endif // SHIKAFX_EXTRAS_WRAPPER
