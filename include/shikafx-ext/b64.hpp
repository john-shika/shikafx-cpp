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

#define skfx_b64_mod shikafx::ext::base64_custom
#define skfx_b64_enc skfx_b64_mod::Encoder
#define skfx_b64_dec skfx_b64_mod::Decoder

namespace skfx_b64_mod {

    class Encoder {
    public:
        Encoder() = default;

        static auto encode(const byte_t* buff, size_t size, bool padding = true) -> std::string;
        static auto encode(const data_t* data, bool padding = true) -> std::string;
        static auto encode(const std::string& val, bool padding = true) -> std::string;

    };

    class Decoder {
    public:
        Decoder() = default;

        static auto decode(const std::string& val) -> data_t*;
        static auto decode(const data_t* data) -> data_t*;
        static auto decode(const char* val, size_t size) -> data_t*;
    };
}

#endif // SHIKAFX_EXTRAS_BASE64_CUSTOM
