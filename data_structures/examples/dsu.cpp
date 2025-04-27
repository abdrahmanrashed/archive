#include <iostream>
#include "../dsu.hpp"

template<class T>
void print_dsu(const dsu<T>& d){
    std::vector<std::vector<T>> v(d.size());
    for(int i = 0; i < d.size(); ++i){
        v[d.find(i)].push_back(i);
    }
    std::cout << '{';
    for(auto& i : v){
        if(i.empty()) continue;
        std::cout << '{';
        for(int j = 0; j < i.size(); ++j){
            std::cout << i[j] << (j + 1 == i.size() ? "}": ", ");
        }
    }
    std::cout << '}';
}
void example1(){
    dsu d;  //{}
    d.insert();    //{{0}}
    d.insert();    //{{0}{1}}
    d.merge(1, 2);  //{{0, 1}}
    d.insert(2);    //{{0, 1}{2}{3}}
    print_dsu(d);
    std::cout << std::endl;
}
void example2(){
    dsu_rb<long> d(4);  //{{0}{1}{2}{3}}
    d.merge(1, 2);  //{{0}{1, 2}{3}}
    d.merge(0, 3);  //{{0, 3}{1, 2}}
    std::cout << "before roll back: ";
    print_dsu(d);
    std::cout << std::endl;
    d.roll_back();  //{{0}{1, 2}{3}}
    std::cout << "after roll back: ";
    print_dsu(d);
    std::cout << std::endl;
}
int main(){
    example1();
    example2();
}