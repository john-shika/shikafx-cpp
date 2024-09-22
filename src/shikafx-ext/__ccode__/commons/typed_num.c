#include "./typed_num.h"

typed_num_t create_typed_num__bool(const bool b) {
    typed_num_t tn;
    tn.kind = NumKind_BOOL;
    tn.value.b = b;
    return tn;
}

typed_num_t create_typed_num__char(const char c) {
    typed_num_t tn;
    tn.kind = NumKind_CHAR;
    tn.value.c = c;
    return tn;
}

typed_num_t create_typed_num__uchar(const unsigned char uc) {
    typed_num_t tn;
    tn.kind = NumKind_UCHAR;
    tn.value.uc = uc;
    return tn;
}

typed_num_t create_typed_num__short(const short s) {
    typed_num_t tn;
    tn.kind = NumKind_SHORT;
    tn.value.s = s;
    return tn;
}

typed_num_t create_typed_num__ushort(const unsigned short us) {
    typed_num_t tn;
    tn.kind = NumKind_USHORT;
    tn.value.us = us;
    return tn;
}

typed_num_t create_typed_num__int(const int i) {
    typed_num_t tn;
    tn.kind = NumKind_INT;
    tn.value.i = i;
    return tn;
}

typed_num_t create_typed_num__uint(const unsigned int ui) {
    typed_num_t tn;
    tn.kind = NumKind_UINT;
    tn.value.ui = ui;
    return tn;
}

typed_num_t create_typed_num__long(const long int l) {
    typed_num_t tn;
    tn.kind = NumKind_LONG;
    tn.value.l = l;
    return tn;
}

typed_num_t create_typed_num__ulong(const unsigned long int ul) {
    typed_num_t tn;
    tn.kind = NumKind_ULONG;
    tn.value.ul = ul;
    return tn;
}

typed_num_t create_typed_num__llong(const long long int ll) {
    typed_num_t tn;
    tn.kind = NumKind_LLONG;
    tn.value.ll = ll;
    return tn;
}

typed_num_t create_typed_num__ullong(const unsigned long long int ull) {
    typed_num_t tn;
    tn.kind = NumKind_ULLONG;
    tn.value.ull = ull;
    return tn;
}

typed_num_t create_typed_num__float(const float f) {
    typed_num_t tn;
    tn.kind = NumKind_FLOAT;
    tn.value.f = f;
    return tn;
}

typed_num_t create_typed_num__double(const double d) {
    typed_num_t tn;
    tn.kind = NumKind_DOUBLE;
    tn.value.d = d;
    return tn;
}

typed_num_t create_typed_num__ldouble(const long double ld) {
    typed_num_t tn;
    tn.kind = NumKind_LDOUBLE;
    tn.value.ld = ld;
    return tn;
}

long double skx_typed_num__to_ldouble(typed_num_t nums) {
    long double val;
    switch (nums.kind) {
        case NumKind_BOOL: val = nums.value.b; break;
        case NumKind_CHAR: val = nums.value.c; break;
        case NumKind_UCHAR: val = nums.value.uc; break;
        case NumKind_SHORT: val = nums.value.s; break;
        case NumKind_USHORT: val = nums.value.us; break;
        case NumKind_INT: val = nums.value.i; break;
        case NumKind_UINT: val = nums.value.ui; break;
        case NumKind_LONG: val = nums.value.l; break;
        case NumKind_ULONG: val = nums.value.ul; break;
        case NumKind_LLONG: val = nums.value.ll; break;
        case NumKind_ULLONG: val = nums.value.ull; break;
        case NumKind_FLOAT: val = nums.value.f; break;
        case NumKind_DOUBLE: val = nums.value.d; break;
        case NumKind_LDOUBLE: val = nums.value.ld; break;
        default: val = 0;
    }
    return val;
}

int skx_typed_num__cmp(typed_num_t a, typed_num_t b) {
    if (a.kind != b.kind) {
        long double va = skx_typed_num__to_ldouble(a);
        long double vb = skx_typed_num__to_ldouble(b);
        int comp = (va > vb) - (va < vb);
        return comp;
    } else {
        switch (a.kind) {
            case NumKind_BOOL: return (a.value.b > b.value.b) - (a.value.b < b.value.b);
            case NumKind_CHAR: return (a.value.c > b.value.c) - (a.value.c < b.value.c);
            case NumKind_UCHAR: return (a.value.uc > b.value.uc) - (a.value.uc < b.value.uc);
            case NumKind_SHORT: return (a.value.s > b.value.s) - (a.value.s < b.value.s);
            case NumKind_USHORT: return (a.value.us > b.value.us) - (a.value.us < b.value.us);
            case NumKind_INT: return (a.value.i > b.value.i) - (a.value.i < b.value.i);
            case NumKind_UINT: return (a.value.ui > b.value.ui) - (a.value.ui < b.value.ui);
            case NumKind_LONG: return (a.value.l > b.value.l) - (a.value.l < b.value.l);
            case NumKind_ULONG: return (a.value.ul > b.value.ul) - (a.value.ul < b.value.ul);
            case NumKind_LLONG: return (a.value.ll > b.value.ll) - (a.value.ll < b.value.ll);
            case NumKind_ULLONG: return (a.value.ull > b.value.ull) - (a.value.ull < b.value.ull);
            case NumKind_FLOAT: return (a.value.f > b.value.f) - (a.value.f < b.value.f);
            case NumKind_DOUBLE: return (a.value.d > b.value.d) - (a.value.d < b.value.d);
            case NumKind_LDOUBLE: return (a.value.ld > b.value.ld) - (a.value.ld < b.value.ld);
        }
    }
    return 0;
}

bool skx_typed_num__eq(typed_num_t a, typed_num_t b) {
    return skx_typed_num__cmp(a, b) == 0;
}

bool skx_typed_num__ge(typed_num_t a, typed_num_t b) {
    return 0 <= skx_typed_num__cmp(a, b);
}

bool skx_typed_num__gt(typed_num_t a, typed_num_t b) {
    return 0 < skx_typed_num__cmp(a, b);
}

bool skx_typed_num__le(typed_num_t a, typed_num_t b) {
    return skx_typed_num__cmp(a, b) <= 0;
}

bool skx_typed_num__lt(typed_num_t a, typed_num_t b) {
    return skx_typed_num__cmp(a, b) < 0;
}

void skx_typed_num__swap(typed_num_t* a, typed_num_t* b) {
    typed_num_t va = *a;
    *a = *b;
    *b = va;
}
