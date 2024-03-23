#include <cmath>
#include <algorithm>

/*
   @brief Returns the floor of the square root of a number.

   @param x A non-negative numerical value. Must be implicitly convertible to primitive type for sqrt calculation.
   @return floor(sqrt(x))
*/
template<class T>
T sqrti(T x){
    T rt = std::max<T>(0, T(sqrtl(x)) - 2);
    if(std::is_floating_point<T>()) rt = floorl(rt);
    while((rt + 1) * (rt + 1) <= x) ++rt;
    return rt;
}