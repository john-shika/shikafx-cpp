#ifndef C_SHIKAFX_EXTRAS_COMMONS_QUICKSORT
#define C_SHIKAFX_EXTRAS_COMMONS_QUICKSORT

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../common.h"

// using size_t, because skx_quicksort_typed_nums decrement low value at 0

void skx_quicksort_typed_nums__swap(typed_nums_t* data, size_t left, size_t right);
size_t skx_quicksort_typed_nums__partition(typed_nums_t* data, size_t low, size_t high);
void skx_quicksort_typed_nums__init(typed_nums_t* data, size_t low, size_t high);
void skx_quicksort_typed_nums(typed_nums_t* data, size_t size);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_COMMONS_QUICKSORT