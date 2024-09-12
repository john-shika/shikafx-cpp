#include <iostream>
#include <string>
#include "src/shikafx-ext/preload.hpp"

int main() {

    []() -> void {
        const std::string name = "Ahmad Asy Syafiq";
        auto base64_ascii = skx_make_shared(skfx_b64_enc::encode(name, true), false);
        std::cout << skx_copy_data_to_str(base64_ascii.get()) << std::endl;
    }();

    []() -> void {
        const char* base64_ascii = "QWhtYWQgQXN5IFN5YWZpcQpXb3JraW5nIE9uIENcQysrIExpYnJhcnkKV2l0aCBQcm9qZWN0IE5hbWUKU2hpa2FGeCBMaWJyYXJ5Cg==";

        auto data = skx_make_shared(skfx_b64_dec::decode(base64_ascii), false);
        skfx_ext_mod::hexdump_view(data.get());

        std::string value = skx_copy_data_to_str(data.get());
        std::cout << value << std::endl;
    }();

    []() -> void {
        size_t n = 13;
        auto nums = new typed_nums_t[n] {
                create_typed_nums__int(6),
                create_typed_nums__long(12),
                create_typed_nums__long(9),
                create_typed_nums__long(10),
                create_typed_nums__ushort(1),
                create_typed_nums__char(2),
                create_typed_nums__int(3),
                create_typed_nums__long(11),
                create_typed_nums__short(5),
                create_typed_nums__llong(8),
                create_typed_nums__int(7),
                create_typed_nums__ulong(0),
                create_typed_nums__double(4)
        };

        //skx_mergesort_typed_nums(nums, n);
        skx_quicksort_typed_nums(nums, n);
        //skx_sort_typed_nums(nums, n);

        for (size_t i = 0; i < n; i++) {
            printf("%.2Lf ", skx_typed_nums__to_ldouble(nums[i]));
        }

        std::cout << std::endl;
        delete[] nums;
    }();

    []() -> void {
        auto buff = "hello,   world!";
        auto in = skx_make_shared(create_data((const byte_t*)buff, strlen(buff)), false);

        buff = toUpperCase((const char*)in->data, in->size);

        auto temp = std::string(buff, buff + in->size);
        std::cout << "\"" << temp << "\"" << std::endl;
    }();

    []() -> void {
        auto buff = "HELLO,   WORLD!";
        auto in = skx_make_shared(create_data((const byte_t*)buff, strlen(buff)), false);

        buff = toLowerCase((const char*)in->data, in->size);

        auto temp = std::string(buff, buff + in->size);
        std::cout << "\"" << temp << "\"" << std::endl;
    }();

    []() -> void {
        auto buff = "  HELLO,   WORLD!      ";
        auto in = skx_make_shared(create_data((const byte_t*)buff, strlen(buff)), false);

        auto out = skx_make_shared(toTitleCase((const char*)in->data, in->size));

        auto temp = std::string(out->data, out->data + out->size);
        printf("size: %zu %zu\n", strlen((const char*)out->data), out->size);
        std::cout << "\"" << temp << "\"" << std::endl;
    }();

    []() -> void {
        auto buff = "  HELLO,   WORLD!      ";
        auto in = skx_make_shared(create_data((const byte_t*)buff, strlen(buff)), false);

        auto out = skx_make_shared(toCamelCase((const char*)in->data, in->size));

        auto temp = std::string(out->data, out->data + out->size);
        printf("size: %zu %zu\n", strlen((const char*)out->data), out->size);
        std::cout << "\"" << temp << "\"" << std::endl;
    }();

    []() -> void {
        auto buff = "  HELLO,   WORLD!      ";
        auto in = skx_make_shared(create_data((const byte_t*)buff, strlen(buff)), false);

        auto out = skx_make_shared(toSnakeCase((const char*)in->data, in->size));

        auto temp = std::string(out->data, out->data + out->size);
        printf("size: %zu %zu\n", strlen((const char*)out->data), out->size);
        std::cout << "\"" << temp << "\"" << std::endl;
    }();

    []() -> void {
        auto buff = "  HELLO,   WORLD!      ";
        auto in = skx_make_shared(create_data((const byte_t*)buff, strlen(buff)), false);

        auto out = skx_make_shared(toKebabCase((const char*)in->data, in->size));

        auto temp = std::string(out->data, out->data + out->size);
        printf("size: %zu %zu\n", strlen((const char*)out->data), out->size);
        std::cout << "\"" << temp << "\"" << std::endl;
    }();

    []() -> void {
        auto buff = "  HELLO,   WORLD!      ";
        auto in = skx_make_shared(create_data((const byte_t*)buff, strlen(buff)), false);

        auto out = skx_make_shared(toTrimStart((const char*)in->data, in->size));

        auto temp = std::string(out->data, out->data + out->size);
        printf("size: %zu %zu\n", strlen((const char*)out->data), out->size);
        std::cout << "\"" << temp << "\"" << std::endl;
    }();

    []() -> void {
        auto buff = "  HELLO,   WORLD!      ";
        auto in = skx_make_shared(create_data((const byte_t*)buff, strlen(buff)), false);

        auto out = skx_make_shared(toTrimEnd((const char*)in->data, in->size));

        auto temp = std::string(out->data, out->data + out->size);
        printf("size: %zu %zu\n", strlen((const char*)out->data), out->size);
        std::cout << "\"" << temp << "\"" << std::endl;
    }();

    []() -> void {
        auto buff = "  HELLO,   WORLD!      ";
        auto in = skx_make_shared(create_data((const byte_t*)buff, strlen(buff)), false);

        auto out = skx_make_shared(toTrim((const char*)in->data, in->size));

        auto temp = std::string(out->data, out->data + out->size);
        printf("size: %zu %zu\n", strlen((const char*)out->data), out->size);
        std::cout << "\"" << temp << "\"" << std::endl;
    }();

    []() -> void {
        auto buff = "  HELLO,   WORLD!      ";
        auto in = skx_make_shared(create_data((const byte_t*)buff, strlen(buff)), false);

        auto out = skx_make_shared(toUpperCamelCase((const char*)in->data, in->size));

        auto temp = std::string(out->data, out->data + out->size);
        printf("size: %zu %zu\n", strlen((const char*)out->data), out->size);
        std::cout << "\"" << temp << "\"" << std::endl;
    }();

    return EXIT_SUCCESS;
}
