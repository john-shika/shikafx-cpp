#include "./b64.hpp"

auto skx_b64_enc(const byte_t* buff, size_t size, bool padding) -> const data_t* {
    auto data = skx_make_shared(create_data(buff, size), false); // not copied
    auto temp = skx_b64_enc(data.get(), padding);
    return temp;
}

auto skx_b64_enc(const data_t* data, bool padding) -> const data_t* {
    auto base64_data = skx_make_shared(base64_encode_func(data));
    auto temp = base64_data_to_ascii_cvt_func(base64_data.get(), padding);
    return temp;
}

auto skx_b64_enc(const std::string& val, bool padding) -> const data_t* {
    auto data = skx_make_shared(skfx_ext_mod::cast_str_to_data(val), false); // not copied
    auto temp = skx_b64_enc(data.get(), padding);
    return temp;
}

auto skx_b64_dec(const std::string& val) -> const data_t* {
    auto data = skx_make_shared(skfx_ext_mod::cast_str_to_data(val), false); // not copied
    auto temp = skx_b64_dec(data.get());
    return temp;
}

auto skx_b64_dec(const data_t* data) -> const data_t* {
    auto buff = (const char*)data->data; // not copied
    auto temp = skx_b64_dec(buff, data->size);
    return temp;
}

auto skx_b64_dec(const char* val, size_t size) -> const data_t* {
    auto base64_data = skx_make_shared(ascii_to_base64_data_cvt_func(val, size)); // copied
    auto temp = base64_decode_func(base64_data.get());
    return temp;
}
