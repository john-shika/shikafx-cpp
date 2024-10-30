#ifndef C_SHIKAFX_EXTRAS_COMMON_TYPED_NUM
#define C_SHIKAFX_EXTRAS_COMMON_TYPED_NUM

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdbool.h>

typedef union {
    bool _bool; // 8-bits
    char _char; // 8-bits
    unsigned char _uchar; // 8-bits
    short _short; // 16-bits
    unsigned short _ushort; // 16-bits
    int _int; // 32-bits
    unsigned int _uint; // 32-bits
    long int _long; // 32-bits ~ 64-bits
    unsigned long int _ulong; // 32-bits ~ 64-bits
    long long int _long64; // 64-bits
    unsigned long long int _ulong64; // 64-bits
    float _float; // 32-bits
    double _double; // 64-bits
    long double _double128; // 80-bits ~ 96-bits ~ 128-bits
} NumTyped_value;

typedef enum {
    NumTyped_BOOL,
    NumTyped_CHAR,
    NumTyped_UCHAR,
    NumTyped_SHORT,
    NumTyped_USHORT,
    NumTyped_INT,
    NumTyped_UINT,
    NumTyped_LONG,
    NumTyped_ULONG,
    NumTyped_LONG64,
    NumTyped_ULONG64,
    NumTyped_FLOAT,
    NumTyped_DOUBLE,
    NumTyped_DOUBLE128
} NumTyped_kind;

typedef struct {
    NumTyped_kind kind;
    NumTyped_value value;
} NumTyped_t;

NumTyped_t createNumTyped__bool(bool value);
NumTyped_t createNumTyped__char(char value);
NumTyped_t createNumTyped__uchar(unsigned char value);
NumTyped_t createNumTyped__short(short value);
NumTyped_t createNumTyped__ushort(unsigned short value);
NumTyped_t createNumTyped__int(int value);
NumTyped_t createNumTyped__uint(unsigned int value);
NumTyped_t createNumTyped__long(long int value);
NumTyped_t createNumTyped__ulong(unsigned long int value);
NumTyped_t createNumTyped__long64(long long int value);
NumTyped_t createNumTyped__ulong64(unsigned long long int value);
NumTyped_t createNumTyped__float(float value);
NumTyped_t createNumTyped__double(double value);
NumTyped_t createNumTyped__double128(long double value);

long double skx_NumTyped__to_double128(NumTyped_t num);

int skx_NumTyped__cmp(NumTyped_t a, NumTyped_t b);

bool skx_NumTyped__eq(NumTyped_t a, NumTyped_t b);
bool skx_NumTyped__ge(NumTyped_t a, NumTyped_t b);
bool skx_NumTyped__gt(NumTyped_t a, NumTyped_t b);
bool skx_NumTyped__le(NumTyped_t a, NumTyped_t b);
bool skx_NumTyped__lt(NumTyped_t a, NumTyped_t b);

void skx_NumTyped__swap(NumTyped_t* a, NumTyped_t* b);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_SHIKAFX_EXTRAS_COMMON_TYPED_NUM
