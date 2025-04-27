#include <vector>
#include "sqrti.hpp"

/**
    @brief Returns continued fraction representing the root of an integer.
    @tparam T type of elements.
    @param x An integer.
    @return An array Given in the form [a0, (a1, a2, ... , an)] representing the continued fraction.
    @return Where (a1, a2, ... , an) repeats infinitely.
*/
template<class T>
std::vector<T> cont_frac_rt(const T& x) {
    // maintain fraction in the form (sqrt(x) + c) / b
    // by multiplying with conjugate after reciprocation

    //inital values
    T ic = sqrti(x), ib = x - ic * ic; 
    std::vector<T> v{ic};
    if(!ib) return v;
    T c = ic, b = ib;
    do {
        //floor of sqrt
        T f = (ic + c) / b;
        v.push_back(f);
        //subtract floor and reciprocate fraction
        c = b * f - c;
        b = (x - c * c) / b;
        //repetiton begins when we reach the inital values
    } while(b != ib || c != ic);
    return v;
}