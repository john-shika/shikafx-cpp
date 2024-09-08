#include "preload.hpp"

auto cpp_hexdump_view(const char* data, size_t size, int cols) -> void {
    skx_hexdump_view(data, size, cols);
}

/*
 * It sounds like the issue might be related to the lifetime and ownership of
 * the std::string object. In C++, std::string manages its own memory, and if
 * the string goes out of scope or is modified, the underlying data pointer
 * can become invalid. This can lead to undefined behavior, especially when
 * interfacing with Cython.
 * */

auto cpp_base64_encode(const char* data, size_t size, bool padding) -> data_t* {
    auto temp = skx_b64_enc((byte_t*)data, size, padding);
    return temp;
}

auto cpp_base64_decode(const char* data, size_t size) -> data_t* {
    auto out = skx_b64_dec(data, size);
    return out;
}

auto cpp_drop_data(const data_t* data, bool drop_field) -> void {
    drop_data(data, drop_field);
}
