#ifndef C_SHIKAFX_EXTRAS_COMMONS_QUICKSORT
#define C_SHIKAFX_EXTRAS_COMMONS_QUICKSORT

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../common.h"

// using int64_t, because skx_quicksort_typed_nums decrement low value at 0

void skx_quicksort_typed_nums__swap(typed_nums_t* data, int64_t left, int64_t right);
int64_t skx_quicksort_typed_nums__partition(typed_nums_t* data, int64_t low, int64_t high);
void skx_quicksort_typed_nums__init(typed_nums_t* data, int64_t low, int64_t high);
void skx_quicksort_typed_nums(typed_nums_t* data, int64_t size);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_COMMONS_QUICKSORT