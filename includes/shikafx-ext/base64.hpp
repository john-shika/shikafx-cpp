#ifndef SHIKAFX_EXTRAS_BASE64_CUSTOM
#define SHIKAFX_EXTRAS_BASE64_CUSTOM

#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <memory>
#include "./wrapper.hpp"
#include "./common.hpp"
#include "./utils.hpp"

#define skfx_base64_mod shikafx::ext::base64_custom
#define skfx_base64_enc skfx_base64_mod::Encoder
#define skfx_base64_dec skfx_base64_mod::Decoder

// short using
#define skx_b64_enc skfx_base64_enc::encode
#define skx_b64_dec skfx_base64_dec::decode

namespace skfx_base64_mod {

    class Encoder {
    public:
        Encoder() = default;

        static auto encode(const byte_t* buff, size_t size, bool padding = true) -> const data_t*;
        static auto encode(const data_t* data, bool padding = true) -> const data_t*;
        static auto encode(const std::string& val, bool padding = true) -> const data_t*;

    };

    class Decoder {
    public:
        Decoder() = default;

        static auto decode(const std::string& val) -> const data_t*;
        static auto decode(const data_t* data) -> const data_t*;
        static auto decode(const char* val, size_t size) -> const data_t*;
    };
}

#endif // SHIKAFX_EXTRAS_BASE64_CUSTOM
