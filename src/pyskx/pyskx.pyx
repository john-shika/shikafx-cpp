#!cython
# cython: language_level=3
cdef extern from "shikafx-drv/preload.hpp":
    ctypedef struct data_t:
        const unsigned char* data
        size_t size

    void skx_drv_hexdump_view(const char* data, size_t size, int cols)
    const data_t* skx_drv_base64_encode(const char* data, size_t size, bint padding)
    const data_t* skx_drv_base64_decode(const char* data, size_t size)
    void skx_drv_drop_data(const data_t* data, bint drop_field)

cdef bytearray cast_data_to_bytes(const data_t* data):
    if data == NULL:
        return bytearray(0)

    temp = bytearray(data.size)
    for i in range(data.size):
        temp[i] = data.data[i]

    return temp

def py_hexdump_view(str data, int cols = 16):
    cdef bytes buff = data.encode("utf-8")
    cdef size_t size = len(buff)
    skx_drv_hexdump_view(buff, size, cols)

def py_base64_encode(str data, bint padding = 1) -> str:
    cdef bytes buff = data.encode("utf-8")
    cdef size_t size = len(buff)
    cdef const data_t* out = skx_drv_base64_encode(buff, size, padding)
    temp = cast_data_to_bytes(out)
    skx_drv_drop_data(out, 0)
    return temp.decode("utf-8")

def py_base64_decode(str data) -> bytearray:
    cdef bytes buff = data.encode("utf-8")
    cdef size_t size = len(buff)
    cdef const data_t* out = skx_drv_base64_decode(buff, size)
    temp = cast_data_to_bytes(out)
    skx_drv_drop_data(out, 0)
    return temp
