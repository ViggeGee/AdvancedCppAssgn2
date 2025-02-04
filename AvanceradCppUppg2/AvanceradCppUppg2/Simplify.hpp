#pragma once
#include <type_traits> 

// Simplify.hpp
template<class T>
struct SimplifyType {
    using type = T;
};

// Specialization for const
template<class T>
struct SimplifyType<const T> {
    using type = T;
};

// Specialization for reference (&)
template<class T>
struct SimplifyType<T&> {
    using type = T;
};

// Specialization for pointer (*)
template<class T>
struct SimplifyType<T*> {
    using type = T;
};

// Specialization for array ([])
template<class T>
struct SimplifyType<T[]> {
    using type = T;
};

// Helper alias
template<class T>
using SimplifyType_t = typename SimplifyType<T>::type;

template<class T>
struct BaseType {
    using type = typename BaseType<typename SimplifyType<T>::type>::type;
};

// Base case: when no more modifiers are left
template<>
struct BaseType<int> {
    using type = int;
};

// Base case: when no more modifiers are left
template<>
struct BaseType<float> {
    using type = float;
};

template<>
struct BaseType<double> {
    using type = double;
};

// Helper alias
template<class T>
using BaseType_t = typename BaseType<T>::type;