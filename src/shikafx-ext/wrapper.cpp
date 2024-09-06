#include "./wrapper.hpp"

auto skx_make_shared(const char* data) -> std::shared_ptr<char> {
    auto mPtr = (char*)data; // make editable pointer

    std::shared_ptr<char> shared_ptr(mPtr, [=](char* ptr) -> void {

#ifdef DEBUG
        std::cout << "[CXX] free up memory allocator for <char> pointer" << std::endl;
#endif
        drop_char_stack(ptr);
        ptr = nullptr;
    });

    return shared_ptr;
}

auto skx_make_shared(const byte_t* data) -> std::shared_ptr<byte_t> {
    auto mPtr = (byte_t*)data; // make editable pointer

    std::shared_ptr<byte_t> shared_ptr(mPtr, [=](byte_t* ptr) -> void {

#ifdef DEBUG
        std::cout << "[CXX] free up memory allocator for <byte_t> pointer" << std::endl;
#endif
        drop_byte_stack(ptr);
        ptr = nullptr;
    });

    return shared_ptr;
}

auto skx_make_shared(const data_t* data, bool drop_field) -> std::shared_ptr<data_t> {
    auto mPtr = (data_t*)data; // make editable pointer

    std::shared_ptr<data_t> shared_ptr(mPtr, [=](data_t* ptr) -> void {

#ifdef DEBUG
        std::cout << "[CXX] free up memory allocator for <data_t> pointer" << std::endl;
#endif
        drop_data(ptr, drop_field);
        ptr = nullptr;
    });

    return shared_ptr;
}

auto skx_make_shared(const base64_data_t* base64_data, bool drop_field) -> std::shared_ptr<base64_data_t> {
    auto mPtr = (base64_data_t*)base64_data; // make editable pointer

    std::shared_ptr<base64_data_t> shared_ptr(mPtr, [=](base64_data_t* ptr) -> void {

#ifdef DEBUG
        std::cout << "[CXX] free up memory allocator for <base64_data_t> pointer" << std::endl;
#endif
        drop_base64_data(ptr, drop_field);
        ptr = nullptr;
    });

    return shared_ptr;
}

auto skx_make_shared(const base64_calc_size_t* base64_calc_size) -> std::shared_ptr<base64_calc_size_t> {
    auto mPtr = (base64_calc_size_t*)base64_calc_size; // make editable pointer

    std::shared_ptr<base64_calc_size_t> shared_ptr(mPtr, [=](base64_calc_size_t* ptr) -> void {

#ifdef DEBUG
        std::cout << "[CXX] free up memory allocator for <base64_calc_size_t> pointer" << std::endl;
#endif
        drop_base64_calc_size(ptr);
        ptr = nullptr;
    });

    return shared_ptr;
}
