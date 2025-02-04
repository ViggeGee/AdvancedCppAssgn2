#pragma once
#include <type_traits>
#include <string>

// Version for noexcept copy constructible types (pass by value)
template <class T, typename std::enable_if_t<std::is_nothrow_copy_constructible_v<T>, int> = 0>
bool UseValueCallOrReference(T) {
    return true;
}

// Version for types that are not noexcept copy constructible (pass by reference)
template <class T, typename std::enable_if_t<!std::is_nothrow_copy_constructible_v<T>, int> = 0>
bool UseValueCallOrReference(const T&) {
    return false;
}
