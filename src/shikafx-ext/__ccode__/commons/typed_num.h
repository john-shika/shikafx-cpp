#ifndef C_SHIKAFX_EXTRAS_COMMON_TYPED_NUM
#define C_SHIKAFX_EXTRAS_COMMON_TYPED_NUM

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
} num_t;

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
} num_kind;

typedef struct {
    num_kind kind;
    num_t value;
} typed_num_t;

typed_num_t create_typed_num__bool(bool b);
typed_num_t create_typed_num__char(char c);
typed_num_t create_typed_num__uchar(unsigned char uc);
typed_num_t create_typed_num__short(short s);
typed_num_t create_typed_num__ushort(unsigned short us);
typed_num_t create_typed_num__int(int i);
typed_num_t create_typed_num__uint(unsigned int ui);
typed_num_t create_typed_num__long(long int l);
typed_num_t create_typed_num__ulong(unsigned long int ul);
typed_num_t create_typed_num__llong(long long int ll);
typed_num_t create_typed_num__ullong(unsigned long long int ull);
typed_num_t create_typed_num__float(float f);
typed_num_t create_typed_num__double(double d);
typed_num_t create_typed_num__ldouble(long double ld);

long double skx_typed_num__to_ldouble(typed_num_t nums);

int skx_typed_num__cmp(typed_num_t a, typed_num_t b);

bool skx_typed_num__eq(typed_num_t a, typed_num_t b);
bool skx_typed_num__ge(typed_num_t a, typed_num_t b);
bool skx_typed_num__gt(typed_num_t a, typed_num_t b);
bool skx_typed_num__le(typed_num_t a, typed_num_t b);
bool skx_typed_num__lt(typed_num_t a, typed_num_t b);

void skx_typed_num__swap(typed_num_t* a, typed_num_t* b);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_COMMON_TYPED_NUM