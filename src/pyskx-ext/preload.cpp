#include "preload.hpp"

auto cpp_hexdump_view(const char* data, size_t size, int cols) -> void {
    skfx_ext_mod::hexdump_view(data, size, cols);
}

/*
 * It sounds like the issue might be related to the lifetime and ownership of
 * the std::string object. In C++, std::string manages its own memory, and if
 * the string goes out of scope or is modified, the underlying data pointer
 * can become invalid. This can lead to undefined behavior, especially when
 * interfacing with Cython.
 * */

auto cpp_base64_encode(const char* data, size_t size, bool padding) -> data_t* {
    auto temp = skfx_b64_enc::encode((byte_t*)data, size, padding);
    //auto data_ptr = skx_make_shared(create_data((byte_t*)data, size), false);
    //auto base64_data_ptr = skx_make_shared(base64_encode_func(data_ptr.get()));
    //auto temp = base64_data_to_ascii_cvt_func(base64_data_ptr.get(), padding);
    return temp;
}

auto cpp_base64_decode(const char* data, size_t size) -> data_t* {
    auto out = skfx_b64_dec::decode(data, size);
    return out;
}

auto cpp_drop_data(const data_t* data, bool drop_field) -> void {
    drop_data(data, drop_field);
}
