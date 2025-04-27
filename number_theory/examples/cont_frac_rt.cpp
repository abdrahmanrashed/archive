#include <iostream>
#include <cassert>
#include "../cont_frac_rt.hpp"

template<class T>
void print_cont_frac_rt(const std::vector<T>& v){
    assert(v.size());
    std::cout << '[' << v[0];
    if(v.size() > 1) std::cout << ";(";
    for(int i = 1; i < v.size(); ++i){
        std::cout << v[i] << (i + 1 == v.size() ? ")" : ", ");
    }
    std::cout << ']';
}
void example1(){
    auto v = cont_frac_rt(793);
    print_cont_frac_rt(v); // [28;(6, 4, 6, 56)]
    std::cout << std::endl;
}
void example2(){
    auto v = cont_frac_rt(25);
    print_cont_frac_rt(v); // [5]
    std::cout << std::endl;
}
int main(){
    example1();
    example2();
}