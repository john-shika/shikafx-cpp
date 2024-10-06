#ifndef SHIKAFX_DRIVER_PRELOAD
#define SHIKAFX_DRIVER_PRELOAD

#include "../shikafx-ext/preload.hpp"

auto skx_drv_hexdump_view(const char *data, size_t size, int cols) -> void;
auto skx_drv_base64_encode(const char *data, size_t size, bool padding) -> const data_t *;
auto skx_drv_base64_decode(const char *data, size_t size) -> const data_t *;
auto skx_drv_drop_data(const data_t *data, bool drop_field) -> void;

#endif // SHIKAFX_DRIVER_PRELOAD
