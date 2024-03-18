#include <cmath>
#include <algorithm>
#include <vector>
using i64 = long long;
using i128 = __int128_t;

/*
   @brief Returns the floor of the root of an integer.

   @param x An integer.
   @return floor(sqrt(x))
*/
i128 sqrti(i128 x){
    i128 q = std::max(0ll, i64(sqrtl(x)) - 2);
    while((q + 1) * (q + 1) <= x) ++q;
    return q;
}
/*
   @brief Returns continued fraction representing the root of an integer.

   @param x An integer.
   @return An array Given in the form [a0, (a1, a2, ... , an)] representing the continued fraction.
   @return Where (a1, a2, ... , an) repeats infinitely
*/
std::vector<i64> cont_frac_rt(i64 x) {
    // maintain fraction in the form (sqrt(x) + c) / b
    // by multiplying with conjugate after reciprocation

    //inital values
    i128 ic = sqrti(x), ib = x - ic * ic; 
    std::vector<i64> v{i64(ic)};
    if(!ib) return v;
    i128 c = ic, b = ib;
    do {
        //floor of sqrt
        i128 f = (ic + c) / b;
        v.push_back(f);
        //subtract floor and reciprocate fraction
        c = b * f - c;
        b = (x - c * c) / b;
        //repetiton begins when we reach the inital values
    } while(b != ib || c != ic);
    return v;
}