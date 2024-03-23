#include <iostream>
#include "../sieve of erastothenes.hpp"

template<class T>
void print_vector(const std::vector<T>& v){
    std::cout << '[';
    for(int i = 0; i < v.size(); ++i){
        std::cout << v[i] << (i + 1 == v.size() ? "" : ", ");
    }
    std::cout << ']';
}
void example1(){
    auto p = sieve(15).first;
    print_vector(p); // [2, 3, 5, 7, 11, 13]
    std::cout << std::endl;
}
void example2(){
    auto lf = sieve(8).second;
    print_vector(lf); // [0, 1, 2, 3, 2, 5, 2, 7, 2]
    std::cout << std::endl;
}
void example3(){
    //static assertion faliure
    // auto p = sieve<double>(15).first;
}
int main(){
    example1();
    example2();
    example3();
}