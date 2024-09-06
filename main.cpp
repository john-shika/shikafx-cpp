#include <iostream>
#include <string>
#include "src/shikafx-ext/preload.hpp"

int main() {

    const std::string name = "Ahmad Asy Syafiq";
    auto base64_ascii = skfx_b64_enc::encode(name, true);
    std::cout << base64_ascii << std::endl;

    const char* b64 = "QWhtYWQgQXN5IFN5YWZpcQpXb3JraW5nIE9uIENcQysrIExpYnJhcnkKV2l0aCBQcm9qZWN0IE5hbWUKU2hpa2FGeCBMaWJyYXJ5Cg==";

    auto data = skx_make_shared(skfx_b64_dec::decode(b64), false);
    skfx_ext_mod::hexdump_view(data.get());

    std::string value = skfx_ext_mod::cast_data_to_str(data.get());
    std::cout << value << std::endl;

    auto nums = new typed_nums_t[10] {
            create_typed_nums__int(6),
            create_typed_nums__long(9),
            create_typed_nums__ushort(1),
            create_typed_nums__char(2),
            create_typed_nums__int(3),
            create_typed_nums__short(5),
            create_typed_nums__llong(8),
            create_typed_nums__int(7),
            create_typed_nums__ulong(0),
            create_typed_nums__double(4)
    };

    //skx_mergesort_typed_nums(nums, 10);
    //skx_quicksort_typed_nums(nums, 10);
    skx_sort_typed_nums(nums, 10);

    for (int64_t i = 0; i < 10; i++) {
        printf("%.2Lf ", skx_typed_nums__to_ldouble(nums[i]));
    }

    delete[] nums;

    // Output: 0.00 1.00 2.00 3.00 4.00 5.00 6.00 7.00 8.00 9.00

    std::cout << std::endl;

    return EXIT_SUCCESS;
}
