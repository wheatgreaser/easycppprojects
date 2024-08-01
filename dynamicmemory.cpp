#include <iostream>

int main(){
    int *ptr = new int;
    *ptr = 7;
    std::cout << *ptr << std::endl;
    delete ptr;
    ptr = nullptr;
    return 0;
}