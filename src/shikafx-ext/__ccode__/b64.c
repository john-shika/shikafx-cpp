#include "./b64.h"

base64_data_t* create_base64_data(const char* val, const size_t size, const int pads) {
#ifdef DEBUG
    printf("[CC] create memory allocator for <base64_data_t> pointer\n");
#endif

    base64_data_t* ptr = malloc(sizeof *ptr);
    ptr->data = val;
    ptr->size = size;
    ptr->pads = pads;
    return ptr;
}

void drop_base64_data(const base64_data_t* base64_data, const bool drop_field) {
    base64_data_t* ptr = (base64_data_t*)base64_data;

    if (ptr == NULL) return;

#ifdef DEBUG
    printf("[CC] free up memory allocator for <base64_data_t> pointer\n");
#endif

    if (drop_field && ptr->data != NULL) drop_char_stack(ptr->data);

    free(ptr);
    ptr = NULL;
}

base64_calc_size_t* create_base64_calc_size(const size_t size, const int pads) {
#ifdef DEBUG
    printf("[CC] create memory allocator for <base64_calc_size_t> pointer\n");
#endif

    base64_calc_size_t* ptr = malloc(sizeof *ptr);
    ptr->size = size;
    ptr->pads = pads;
    return ptr;
}

void drop_base64_calc_size(const base64_calc_size_t* base64_calc_size) {
    base64_calc_size_t* ptr = (base64_calc_size_t*)base64_calc_size;

    if (ptr == NULL) return;

#ifdef DEBUG
    printf("[CC] free up memory allocator for <base64_calc_size_t> pointer\n");
#endif

    free(ptr);
    ptr = NULL;
}

base64_calc_size_t* base64_encoding_calc_size_func(const size_t size) {
    size_t bits = size * 8;

    size_t n = 0;
    size_t m = 0;
    while (m < bits) {
        m += 6;
        n += 1;
    }

    int pads = (int)(m - bits) / 2;
    return create_base64_calc_size(n, pads);
}

// using base64_decoding_calc_size_func method must trim all padding characters, before
// using base64_decoding_calc_size_func method for some reason, because
// this method does not handle padding size reduction properly

base64_calc_size_t* base64_decoding_calc_size_func(const size_t size) {
    size_t bits = size * 6;

    size_t n = 0;
    size_t m = bits;
    while (8 <= m) {
        m += -8;
        n += 1;
    }

    int pads = (int)m / 2;
    return create_base64_calc_size(n, pads);
}

base64_data_t* base64_encode_func(const data_t* data) {
    const size_t size = data->size;
    //byte_t* data = (byte_t*)malloc(sizeof(byte_t) * size);
    //memcpy(data, data_raw->data, size);
    //const byte_t* data = data_raw->data;

    base64_calc_size_t* base64_calc_size = base64_encoding_calc_size_func(size);
    size_t n = base64_calc_size->size;

    char* temp = create_char_stack(n);
    size_t idx = 0;
    size_t jdx = 0;
    int ov = 0;
    while (idx < size) {
        byte_t n1 = 0;
        n1 |= (data->data[idx] & 0b11111100) >> 2; // 0b00111111
        temp[jdx] = (char)n1;
        jdx += 1;

        byte_t n2 = 0;
        n2 |= (data->data[idx] & 0b00000011) << 4; // 0b00110000
        idx += 1;

        if (size <= idx) {
            temp[jdx] = (char)n2;
            //jdx += 1;
            ov = 4;
            break;
        }

        n2 |= (data->data[idx] & 0b11110000) >> 4; // 0b00001111
        temp[jdx] = (char)n2;
        jdx += 1;

        byte_t n3 = 0;
        n3 |= (data->data[idx] & 0b00001111) << 2; // 0b00111100
        idx += 1;

        if (size <= idx) {
            temp[jdx] = (char)n3;
            //jdx += 1;
            ov = 2;
            break;
        }

        n3 |= (data->data[idx] & 0b11000000) >> 6; // 0b00000011
        temp[jdx] = (char)n3;
        jdx += 1;

        byte_t n4 = 0;
        n4 |= (data->data[idx] & 0b00111111) << 0; // 0b00111111
        temp[jdx] = (char)n4;
        jdx += 1;

        idx += 1;
    }

    int pads = ov / 2;
    if (pads != base64_calc_size->pads) {
        panic("mismatch with calc size, base64_encode: pads = %d pads = %d", base64_calc_size->pads, pads);
    }

    //free up memory allocator
    drop_base64_calc_size(base64_calc_size);

    return create_base64_data(temp, n, pads);
}

const data_t* base64_decode_func(const base64_data_t* data) {
    const size_t size = data->size;
    //char* data = (char*)malloc(sizeof(char) * size);
    //memcpy(data, base64_data_raw->data, size);
    //const char* data = base64_data->data;

    base64_calc_size_t* base64_calc_size = base64_decoding_calc_size_func(size);
    size_t n = base64_calc_size->size;

    byte_t* temp = create_byte_stack(n);
    size_t idx = 0;
    size_t jdx = 0;
    int ov = 0;
    while (idx < size) {
        byte_t n1 = 0;
        n1 |= (data->data[idx] & 0b00111111) << 2; // 0b11111100
        idx += 1;

        if (size <= idx) {
            //temp[jdx] = n1;
            //jdx += 1;
            ov = 6;
            break;
        }

        n1 |= (data->data[idx] & 0b00110000) >> 4; // 0b00000011
        temp[jdx] = n1;
        jdx += 1;

        byte_t n2 = 0;
        n2 |= (data->data[idx] & 0b00001111) << 4; // 0b11110000
        idx += 1;

        if (size <= idx) {
            //temp[jdx] = n2;
            //jdx += 1;
            ov = 4;
            break;
        }

        n2 |= (data->data[idx] & 0b00111100) >> 2; // 0b00001111
        temp[jdx] = n2;
        jdx += 1;

        byte_t n3 = 0;
        n3 |= (data->data[idx] & 0b00000011) << 6; // 0b11000000
        idx += 1;

        if (size <= idx) {
            //temp[jdx] = n3;
            //jdx += 1;
            ov = 2;
            break;
        }

        n3 |= (data->data[idx] & 0b00111111) >> 0; // 0b00111111
        temp[jdx] = n3;
        jdx += 1;

        idx += 1;
    }

    int pads = ov / 2;
    if (pads != base64_calc_size->pads) {
        panic("mismatch with calc size, base64_decode: pads = %d pads = %d", base64_calc_size->pads, pads);
    }

    //free up memory allocator
    drop_base64_calc_size(base64_calc_size);

    return create_data(temp, n);
}

const data_t* base64_data_to_ascii_cvt_func(const base64_data_t* data, const bool padding) {
    int pads = data->pads;
    if (!padding) pads = 0;

    const char* characters = BASE64_CHARACTERS;
    char pad = BASE64_PADDING;

    //end str with null
    const size_t size = data->size + pads + 1;

    byte_t* temp = create_byte_stack(size);

    for (size_t i = 0; i < data->size; i++) {
        char j = data->data[i];
        temp[i] = characters[j];
    }

    for (int i = 0; i < pads; i++) {
        size_t idx = data->size + i;
        temp[idx] = pad;
    }

    //end str with null
    //temp[data->size + pads] = 0;

    return create_data(temp, size);
}

base64_data_t* ascii_to_base64_data_cvt_func(const char* val, const size_t size) {
    size_t n = size;

    int pads = 0;
    const char* characters = BASE64_CHARACTERS;
    const int characters_size = BASE64_CHARACTERS_SIZE;
    char pad = BASE64_PADDING;

    for (uint_t i = 0; i < n; i++) {
        uint_t j = n - i - 1;
        char chr = val[j];
        if (chr != pad) {
            break;
        }
        pads += 1;
    }

    n += -pads;
    char* temp = create_char_stack(n);
    //memcpy(temp, data, len);

    for (size_t i = 0; i < n; i++) {
        char chr = val[i];
        bool found = false;
        for (int j = 0; j < characters_size; j++) {
            if (characters[j] == chr) {
                found = true;
                temp[i] = j;
                break;
            }
        }
        if (!found) {
            panic("mismatch with base64 characters");
        }
    }

    return create_base64_data(temp, n, pads);
}
