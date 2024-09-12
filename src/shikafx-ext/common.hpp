#ifndef SHIKAFX_EXTRAS_COMMON
#define SHIKAFX_EXTRAS_COMMON

#define skfx_com_mod shikafx::ext::common

// short using
#define skx_min skfx_com_mod::min_int
#define skx_min32 skfx_com_mod::min_int
#define skx_min64 skfx_com_mod::min_size_t
#define skx_max skfx_com_mod::max_int
#define skx_max32 skfx_com_mod::max_int
#define skx_max64 skfx_com_mod::max_size_t

#define skx_make_shared_from_raw_ptr skfx_com_mod::make_shared_from_raw_ptr

namespace skfx_com_mod {

    auto min_int(int value) -> int;

    template<typename... Args>
    auto min_int(int val, Args... args) -> int {
        int m = min_int(args...);
        return (val <= m) ? val : m;
    }

    auto max_int(int value) -> int;

    template<typename... Args>
    auto max_int(int val, Args... args) -> int {
        int m = max_int(args...);
        return (m <= val) ? val : m;
    }

    auto min_size_t(size_t value) -> size_t;

    template<typename... Args>
    auto min_size_t(size_t val, Args... args) -> size_t {
        size_t m = min_size_t(args...);
        return (val <= m) ? val : m;
    }

    auto max_size_t(size_t value) -> size_t;

    template<typename... Args>
    auto max_size_t(size_t val, Args... args) -> size_t {
        size_t m = max_size_t(args...);
        return (m <= val) ? val : m;
    }

    template<typename T>
    auto make_shared_from_raw_ptr(const T* data, bool stacked = false) -> std::shared_ptr<T> {
        auto mPtr = (T*)data; // make editable pointer

        std::shared_ptr<T> shared_ptr(mPtr, [=](T* ptr) -> void {
            if (stacked) {
#ifdef DEBUG
                std::cout << "[CXX] free up memory allocator for <T> stack pointer" << std::endl;
#endif
                delete[] ptr;
                ptr = nullptr;
            }

#ifdef DEBUG
            std::cout << "[CXX] free up memory allocator for <T> pointer" << std::endl;
#endif
            delete ptr;
            ptr = nullptr;
        });
        return shared_ptr;
    }
}

#endif // SHIKAFX_EXTRAS_COMMON
