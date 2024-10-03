#ifndef C_SHIKAFX_EXTRAS_UTILS_MERGESORT
#define C_SHIKAFX_EXTRAS_UTILS_MERGESORT

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//#define DEBUG

#include "../common.h"

// using size_t, because skx_mergesort_typed_nums decrement low value at 0

void skx_mergesort_typed_num__merge(typed_num_t* data, size_t left, size_t mid, size_t right);
void skx_mergesort_typed_num__init(typed_num_t* data, size_t left, size_t right);
void skx_mergesort_typed_num(typed_num_t* data, size_t size);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_UTILS_MERGESORT
