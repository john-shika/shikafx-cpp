#include "./utils.hpp"

auto skx_copy_str(const std::string& val) -> std::string {
    auto buff = skx_copy_str_to_char_stack(val);
    auto temp = std::string(buff, buff + val.size());
    return temp;
}

auto skx_cast_str_to_byte_stack(const std::string& val) -> const byte_t* {
    auto temp = (const byte_t*)val.data();
    return temp;
}

auto skx_cast_str_to_data(const std::string& val) -> const data_t* {
    auto buff = skx_cast_str_to_byte_stack(val);
    auto temp = create_data(buff, val.size());
    return temp;
}

auto skx_copy_str_to_byte_stack(const std::string& val) -> byte_t* {
    auto buff = skx_cast_str_to_byte_stack(val);
    auto temp = create_byte_stack(val.size());
    memcpy(temp, buff, val.size());
    return temp;
}

auto skx_copy_str_to_char_stack(const std::string& val) -> char* {
    auto temp = copy_char_stack_wnt_func(val.data(), val.size());
    return temp;
}

auto skx_copy_str_to_data(const std::string& val) -> const data_t* {
    auto buff  = skx_copy_str_to_byte_stack(val);
    auto temp = create_data(buff, val.size());
    return temp;
}

auto skx_cast_data_to_byte_stack(const data_t* data) -> const byte_t* {
    return data->data;
}

auto skx_copy_data_to_byte_stack(const data_t* data) -> byte_t* {
    auto temp = copy_byte_stack_func(data->data, data->size);
    return temp;
}

auto skx_copy_data_to_char_stack(const data_t* data) -> char* {
    auto buff = (const char*)data->data;
    auto temp = copy_char_stack_wnt_func(buff, data->size);
    return temp;
}

auto skx_copy_data_to_str(const data_t* data) -> std::string {
    auto buff = skx_copy_data_to_char_stack(data);
    auto temp = std::string(buff, buff + data->size);
    return temp;
}

auto skx_hexdump_view(const byte_t* data, size_t size, int cols) -> void {

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
            if (!Ansi_isDrawable(val)) {
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

auto skx_hexdump_view(const char* data, size_t size, int cols) -> void {
    auto buff = (const byte_t*)data;
    skx_hexdump_view(buff, size, cols);
}

auto skx_hexdump_view(const data_t* data, int cols) -> void {
    skx_hexdump_view(data->data, data->size, cols);
}

auto skx_hexdump_view(const std::string& val, int cols) -> void {
    skx_hexdump_view(val.data(), val.size(), cols);
}
