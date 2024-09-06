#ifndef PYTHON_SHIKAFX_EXTRAS_PRELOAD
#define PYTHON_SHIKAFX_EXTRAS_PRELOAD

#include "../shikafx-ext/preload.hpp"

auto cpp_hexdump_view(const char* data, size_t size, int cols) -> void;
auto cpp_base64_encode(const char* data, size_t size, bool padding) -> data_t*;
auto cpp_base64_decode(const char* data, size_t size) -> data_t*;
auto cpp_drop_data(const data_t* data, bool drop_field) -> void;

#endif // PYTHON_SHIKAFX_EXTRAS_PRELOAD
