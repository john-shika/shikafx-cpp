#include "./num_typed.h"

NumTyped_t createNumTyped__bool(const bool value) {
    NumTyped_t num;
    num.kind = NumTyped_BOOL;
    num.value._bool = value;
    return num;
}

NumTyped_t createNumTyped__char(const char value) {
    NumTyped_t num;
    num.kind = NumTyped_CHAR;
    num.value._char = value;
    return num;
}

NumTyped_t createNumTyped__uchar(const unsigned char value) {
    NumTyped_t num;
    num.kind = NumTyped_UCHAR;
    num.value._uchar = value;
    return num;
}

NumTyped_t createNumTyped__short(const short value) {
    NumTyped_t num;
    num.kind = NumTyped_SHORT;
    num.value._short = value;
    return num;
}

NumTyped_t createNumTyped__ushort(const unsigned short value) {
    NumTyped_t num;
    num.kind = NumTyped_USHORT;
    num.value._ushort = value;
    return num;
}

NumTyped_t createNumTyped__int(const int value) {
    NumTyped_t num;
    num.kind = NumTyped_INT;
    num.value._int = value;
    return num;
}

NumTyped_t createNumTyped__uint(const unsigned int value) {
    NumTyped_t num;
    num.kind = NumTyped_UINT;
    num.value._uint = value;
    return num;
}

NumTyped_t createNumTyped__long(const long int value) {
    NumTyped_t num;
    num.kind = NumTyped_LONG;
    num.value._long = value;
    return num;
}

NumTyped_t createNumTyped__ulong(const unsigned long int value) {
    NumTyped_t num;
    num.kind = NumTyped_ULONG;
    num.value._ulong = value;
    return num;
}

NumTyped_t createNumTyped__long64(const long long int value) {
    NumTyped_t num;
    num.kind = NumTyped_LONG64;
    num.value._long64 = value;
    return num;
}

NumTyped_t createNumTyped__ulong64(const unsigned long long int value) {
    NumTyped_t num;
    num.kind = NumTyped_ULONG64;
    num.value._ulong64 = value;
    return num;
}

NumTyped_t createNumTyped__float(const float value) {
    NumTyped_t num;
    num.kind = NumTyped_FLOAT;
    num.value._float = value;
    return num;
}

NumTyped_t createNumTyped__double(const double value) {
    NumTyped_t num;
    num.kind = NumTyped_DOUBLE;
    num.value._double = value;
    return num;
}

NumTyped_t createNumTyped__double128(const long double value) {
    NumTyped_t num;
    num.kind = NumTyped_DOUBLE128;
    num.value._double128 = value;
    return num;
}

long double skx_NumTyped__to_double128(NumTyped_t num) {
    long double val;
    switch (num.kind) {
        case NumTyped_BOOL: val = num.value._bool; break;
        case NumTyped_CHAR: val = num.value._char; break;
        case NumTyped_UCHAR: val = num.value._uchar; break;
        case NumTyped_SHORT: val = num.value._short; break;
        case NumTyped_USHORT: val = num.value._ushort; break;
        case NumTyped_INT: val = num.value._int; break;
        case NumTyped_UINT: val = num.value._uint; break;
        case NumTyped_LONG: val = num.value._long; break;
        case NumTyped_ULONG: val = num.value._ulong; break;
        case NumTyped_LONG64: val = num.value._long64; break;
        case NumTyped_ULONG64: val = num.value._ulong64; break;
        case NumTyped_FLOAT: val = num.value._float; break;
        case NumTyped_DOUBLE: val = num.value._double; break;
        case NumTyped_DOUBLE128: val = num.value._double128; break;
        default: val = 0;
    }
    return val;
}

int skx_NumTyped__cmp(NumTyped_t a, NumTyped_t b) {
    if (a.kind != b.kind) {
        long double va = skx_NumTyped__to_double128(a);
        long double vb = skx_NumTyped__to_double128(b);
        int comp = (va > vb) - (va < vb);
        return comp;
    } else {
        switch (a.kind) {
            case NumTyped_BOOL: return (a.value._bool > b.value._bool) - (a.value._bool < b.value._bool);
            case NumTyped_CHAR: return (a.value._char > b.value._char) - (a.value._char < b.value._char);
            case NumTyped_UCHAR: return (a.value._uchar > b.value._uchar) - (a.value._uchar < b.value._uchar);
            case NumTyped_SHORT: return (a.value._short > b.value._short) - (a.value._short < b.value._short);
            case NumTyped_USHORT: return (a.value._ushort > b.value._ushort) - (a.value._ushort < b.value._ushort);
            case NumTyped_INT: return (a.value._int > b.value._int) - (a.value._int < b.value._int);
            case NumTyped_UINT: return (a.value._uint > b.value._uint) - (a.value._uint < b.value._uint);
            case NumTyped_LONG: return (a.value._long > b.value._long) - (a.value._long < b.value._long);
            case NumTyped_ULONG: return (a.value._ulong > b.value._ulong) - (a.value._ulong < b.value._ulong);
            case NumTyped_LONG64: return (a.value._long64 > b.value._long64) - (a.value._long64 < b.value._long64);
            case NumTyped_ULONG64: return (a.value._ulong64 > b.value._ulong64) - (a.value._ulong64 < b.value._ulong64);
            case NumTyped_FLOAT: return (a.value._float > b.value._float) - (a.value._float < b.value._float);
            case NumTyped_DOUBLE: return (a.value._double > b.value._double) - (a.value._double < b.value._double);
            case NumTyped_DOUBLE128: return (a.value._double128 > b.value._double128) - (a.value._double128 < b.value._double128);
        }
    }
    return 0;
}

bool skx_NumTyped__eq(NumTyped_t a, NumTyped_t b) {
    return skx_NumTyped__cmp(a, b) == 0;
}

bool skx_NumTyped__ge(NumTyped_t a, NumTyped_t b) {
    return 0 <= skx_NumTyped__cmp(a, b);
}

bool skx_NumTyped__gt(NumTyped_t a, NumTyped_t b) {
    return 0 < skx_NumTyped__cmp(a, b);
}

bool skx_NumTyped__le(NumTyped_t a, NumTyped_t b) {
    return skx_NumTyped__cmp(a, b) <= 0;
}

bool skx_NumTyped__lt(NumTyped_t a, NumTyped_t b) {
    return skx_NumTyped__cmp(a, b) < 0;
}

void skx_NumTyped__swap(NumTyped_t* a, NumTyped_t* b) {
    NumTyped_t temp = *a;
    *a = *b;
    *b = temp;
}
