#include <iostream>

class funClass{
    public:
        int x = 3;
};

int main(){
    int p = 56;
    int * q = &p;
    std::cout << *q << std::endl;

    int * a_ptr; //pointer to array
    int a[] = {1, 2, 3, 4, 5};
    a_ptr = a;
    std::cout << *(a_ptr+1);
    
    funClass obj;
    funClass *c_ptr = &obj; // object pointer 

}