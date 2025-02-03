#pragma once


//When 𝑚=0 m = 0, return 𝑛 + 1 (base case).
//When 𝑚 > 0 and 𝑛 = 0, call Ackermann(m - 1, 1).
//When 𝑚 > 0 and 𝑛 > 0, call Ackermann(m - 1, Ackermann(m, n - 1))

template <int m, int n>
struct Ackermann
{
    static const int value = Ackermann<m - 1, Ackermann<m, n - 1>::value>::value;
};

template <int m>
struct Ackermann<m,0>
{
    static const int value = Ackermann<m - 1, 1>::value;
};

// Base case specialization: stops recursion when X == 0
//Varför använder vi static här??
template <int n>
struct Ackermann<0, n> 
{
    static const int value = n + 1;
};





