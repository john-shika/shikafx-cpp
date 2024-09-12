#ifndef C_SHIKAFX_EXTRAS_UTILS_SORT
#define C_SHIKAFX_EXTRAS_UTILS_SORT

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../common.h"

void skx_sort_typed_nums__swap(typed_nums_t *data, size_t a, size_t b);
void skx_sort_typed_nums(typed_nums_t *data, size_t size);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_UTILS_SORT