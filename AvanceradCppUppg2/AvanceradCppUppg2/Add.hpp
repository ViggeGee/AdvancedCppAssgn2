#pragma once

// General case: recursive step
//Varför använder vi static här??
template <int X, int Y>
struct Add {
    static const int value = Add<X - 1, Y + 1>::value;
};

// Base case specialization: stops recursion when X == 0
//Varför använder vi static här??
template <int Y>
struct Add<0, Y> {
    static const int value = Y;
};

// Recursive function (runtime)
inline int AddFun(int x, int y) {
    if (x == 0)
        return y;
    return AddFun(x - 1, y + 1);
}
