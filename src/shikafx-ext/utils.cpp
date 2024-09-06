#include "./utils.hpp"

auto skfx_ext_mod::copy_str(const std::string& val) -> std::string {
    std::string temp = (const char*)skfx_ext_mod::copy_str_to_bytes(val);
    return temp;
}

// copy without null terminate
auto skfx_ext_mod::copy_str_to_bytes(const std::string& val) -> byte_t* {
    auto buff = cast_str_to_byte_stack(val); // not copied
    auto temp = create_byte_stack(val.size());
    memcpy(temp, buff, val.size());
    return temp;
}

auto skfx_ext_mod::copy_str_to_char_stack_wnt(const std::string& val) -> char* {
    return copy_char_stack_wnt_func(val.data(), val.size());
}

auto skfx_ext_mod::copy_str_to_byte_stack_wnt(const std::string& val) -> byte_t* {
    auto buff = cast_str_to_byte_stack(val);
    return copy_byte_stack_wnt_func(buff, val.size());
}

/*
 * It sounds like the issue might be related to the lifetime and ownership of
 * the std::string object. In C++, std::string manages its own memory, and if
 * the string goes out of scope or is modified, the underlying data pointer
 * can become invalid. This can lead to undefined behavior, especially when
 * interfacing with Cython.
 * */

auto skfx_ext_mod::copy_str_to_data(const std::string& val) -> data_t* {
    //return skfx_ext_mod::cast_str_to_data(copy_str(val));
    return create_data(copy_str_to_bytes(val), val.size());
}

auto skfx_ext_mod::cast_str_to_data(const std::string& val) -> data_t* {
    auto buff = cast_str_to_byte_stack(val); // not copied
    return create_data(buff, val.size());
}

// copy without null terminate
auto skfx_ext_mod::cast_str_to_byte_stack(const std::string& val) -> const byte_t* {
    auto buff = (const byte_t*)val.data();
    return buff;
}

auto skfx_ext_mod::cast_data_to_str(const data_t* data) -> std::string {
    std::string temp(data->data, data->data + data->size);
    return temp;
}

auto skfx_ext_mod::copy_data_to_str(const data_t* data) -> std::string {
    auto temp = skfx_ext_mod::cast_data_to_str(data);
    return copy_str(temp);
}

// copy without null terminate
auto skfx_ext_mod::copy_data_to_byte_stack(const data_t* data) -> byte_t* {
    auto buff = copy_byte_stack_func(data->data, data->size);
    return buff;
}

auto skfx_ext_mod::copy_data_to_char_stack_wnt(const data_t* data) -> char* {
    return (char*)skfx_ext_mod::copy_data_to_byte_stack_wnt(data);
}

auto skfx_ext_mod::copy_data_to_byte_stack_wnt(const data_t* data) -> byte_t* {
    return copy_byte_stack_wnt_func(data->data, data->size);
}

auto skfx_ext_mod::hexdump_view(const byte_t* data, size_t size, int cols) -> void {

    size_t i = 0;
    size_t j = 0;

    std::string vLine = (const char*)u8"<│>";

    while (i < size) {

        //number
        std::cout << std::setfill('0') << std::setw(8) << std::hex << j;
        std::cout << " " << vLine << " ";

        size_t x = i + cols;
        size_t k = skfx_com_mod::min_size_t(x, size);

        //hexadecimal
        for (size_t m = i; m < k; m++) {
            auto val = static_cast<int>(data[m]);
            std::cout << std::setfill('0') << std::setw(2) << std::hex << val;
            std::cout << " ";
        }

        //continue
        for (size_t m = k; m < x; m++) {
            std::cout << ".. ";
        }

        std::cout << vLine << " ";

        //drawable
        for (size_t m = i; m < k; m++) {
            auto val = data[m];
            if (!is_ascii_drawable(val)) {
                std::cout << ".";
                continue;
            }
            std::cout << val;
        }

        //continue
        for (size_t m = k; m < x; m++) {
            std::cout << " ";
        }

        std::cout << " " << vLine;

        std::cout << std::endl;
        i += cols;
        j += 1;
    }
}

auto skfx_ext_mod::hexdump_view(const char* data, size_t size, int cols) -> void {
    auto buff = (const byte_t*)data;
    skfx_ext_mod::hexdump_view(buff, size, cols);
}

auto skfx_ext_mod::hexdump_view(const data_t* data, int cols) -> void {
    skfx_ext_mod::hexdump_view(data->data, data->size, cols);
}

auto skfx_ext_mod::hexdump_view(const std::string& val, int cols) -> void {
    skfx_ext_mod::hexdump_view(val.data(), val.size(), cols);
}
