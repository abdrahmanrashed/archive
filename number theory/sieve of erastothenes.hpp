#include <numeric>
#include <vector>

/*
   @brief Generates all primes up to n.

   @tparam T Type of elements.
   @param n Sieve limit.
   @return A pair of vectors. The first constains all primes up to n.
   @return The second contains the smallest factor of all integers up to n.
*/
template<class T = unsigned>
std::pair<std::vector<T>, std::vector<T>> sieve(size_t n){
    static_assert(std::is_integral<T>(), "value type must be integer");
    std::vector<T> primes, least_factor(n + 1);
    std::iota(least_factor.begin(), least_factor.end(), 0);
    for(T i = 2; i <= n; ++i){
        if(least_factor[i] == i) primes.push_back(i);
        for(auto& p : primes){
            T j = i * p;
            if(j > n) break;
            least_factor[j] = p;
            if(least_factor[i] == p) break;
        }
    }
    return {primes, least_factor};
}