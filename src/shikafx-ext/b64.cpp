#include "./b64.hpp"

auto skfx_b64_enc::encode(const byte_t* buff, size_t size, bool padding) -> std::string {
    auto data_ptr = skx_make_shared(create_data(buff, size), false); // not copied
    auto temp = skfx_b64_enc::encode(data_ptr.get(), padding);
    return temp; // don't make it short, let shared pointer release first!
}

auto skfx_b64_enc::encode(const data_t* data, bool padding) -> std::string {
    auto base64_data_ptr = skx_make_shared(base64_encode_func(data));
    auto data_ptr = skx_make_shared(base64_data_to_ascii_cvt_func(base64_data_ptr.get(), padding), false);
    auto temp = skfx_ext_mod::cast_data_to_str(data_ptr.get());
    return temp; // don't make it short, let shared pointer release first!
}

auto skfx_b64_enc::encode(const std::string& val, bool padding) -> std::string {
    auto data_ptr = skx_make_shared(skfx_ext_mod::cast_str_to_data(val), false); // not copied
    auto temp = skfx_b64_enc::encode(data_ptr.get(), padding);
    return temp; // don't make it short, let shared pointer release first!
}

auto skfx_b64_dec::decode(const std::string& val) -> data_t* {
    auto data_ptr = skx_make_shared(skfx_ext_mod::cast_str_to_data(val), false); // not copied
    auto temp = skfx_b64_dec::decode(data_ptr.get());
    return temp; // don't make it short, let shared pointer release first!
}

auto skfx_b64_dec::decode(const data_t* data) -> data_t* {
    auto buff = (const char*)data->data; // not copied
    auto temp = skfx_b64_dec::decode(buff, data->size);
    return temp; // don't make it short, let shared pointer release first!
}

auto skfx_b64_dec::decode(const char* val, size_t size) -> data_t* {
    auto base64_data_ptr = skx_make_shared(ascii_to_base64_data_cvt_func(val, size)); // copied
    auto temp = base64_decode_func(base64_data_ptr.get());
    return temp; // don't make it short, let shared pointer release first!
}
