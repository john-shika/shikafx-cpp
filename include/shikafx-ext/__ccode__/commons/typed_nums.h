#ifndef C_SHIKAFX_EXTRAS_TYPED_NUMS
#define C_SHIKAFX_EXTRAS_TYPED_NUMS

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdbool.h>

typedef union {
    bool b; // 8-bits
    char c; // 8-bits
    unsigned char uc; // 8-bits
    short s; // 16-bits
    unsigned short us; // 16-bits
    int i; // 32-bits
    unsigned int ui; // 32-bits
    long int l; // 32-bits ~ 64-bits
    unsigned long int ul; // 32-bits ~ 64-bits
    long long int ll; // 64-bits
    unsigned long long int ull; // 64-bits
    float f; // 32-bits
    double d; // 64-bits
    long double ld; // 80-bits ~ 96-bits ~ 128-bits
} nums_t;

typedef enum {
    BOOL,
    CHAR,
    UCHAR,
    SHORT,
    USHORT,
    INT,
    UINT,
    LONG,
    ULONG,
    LLONG,
    ULLONG,
    FLOAT,
    DOUBLE,
    LDOUBLE
} nums_kind;

typedef struct {
    nums_kind kind;
    nums_t value;
} typed_nums_t;

typed_nums_t create_typed_num__bool(bool b);
typed_nums_t create_typed_num__char(char c);
typed_nums_t create_typed_num__uchar(unsigned char uc);
typed_nums_t create_typed_num__short(short s);
typed_nums_t create_typed_num__ushort(unsigned short us);
typed_nums_t create_typed_num__int(int i);
typed_nums_t create_typed_num__uint(unsigned int ui);
typed_nums_t create_typed_num__long(long int l);
typed_nums_t create_typed_num__ulong(unsigned long int ul);
typed_nums_t create_typed_num__llong(long long int ll);
typed_nums_t create_typed_num__ullong(unsigned long long int ull);
typed_nums_t create_typed_num__float(float f);
typed_nums_t create_typed_num__double(double d);
typed_nums_t create_typed_num__ldouble(long double ld);

long double skx_typed_nums__to_ldouble(typed_nums_t nums);

int skx_typed_nums__cmp(typed_nums_t a, typed_nums_t b);

bool skx_typed_nums__eq(typed_nums_t a, typed_nums_t b);
bool skx_typed_nums__ge(typed_nums_t a, typed_nums_t b);
bool skx_typed_nums__gt(typed_nums_t a, typed_nums_t b);
bool skx_typed_nums__le(typed_nums_t a, typed_nums_t b);
bool skx_typed_nums__lt(typed_nums_t a, typed_nums_t b);

void skx_typed_nums__swap(typed_nums_t* a, typed_nums_t* b);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_TYPED_NUMS
