#include <iostream>
#include <cassert>
#include "../sqrti.hpp"

void example1(){
    auto x = sqrti(25); // 5
    std::cout << x << std::endl;
}
void example2(){
    auto x = sqrti(30ll); // 5
    std::cout << x << std::endl;
}
void example3(){
    auto x = sqrti(25.0); // 5
    std::cout << x << std::endl;
}
void example4(){
    auto x = sqrti(30.5f); // 5
    std::cout << x << std::endl;
}
int main(){
    example1();
    example2();
    example3();
    example4();
}