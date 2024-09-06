#ifndef C_SHIKAFX_EXTRAS_COMMONS_MERGESORT
#define C_SHIKAFX_EXTRAS_COMMONS_MERGESORT

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

//#define DEBUG

#include "../common.h"

// using int64_t, because skx_mergesort_typed_nums decrement low value at 0

void skx_mergesort_typed_nums__merge(typed_nums_t* data, int64_t left, int64_t mid, int64_t right);
void skx_mergesort_typed_nums__init(typed_nums_t* data, int64_t left, int64_t right);
void skx_mergesort_typed_nums(typed_nums_t* data, int64_t size);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_COMMONS_MERGESORT
