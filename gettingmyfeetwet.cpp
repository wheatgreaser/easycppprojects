#include <iostream>
#include <vector>
namespace balls{
    int x = 1;
}

typedef int int_t;
// typedef std::string text_t;
using text_t = std::string;
class coolClass{
    public:
        std::string name;
        std::string company;
        int age;
        coolClass(std::string nameinput, std::string companyinput, int ageinput){
            name = nameinput;
            company = companyinput;
            age = ageinput;
        }
    void coolMethod(){
        std::cout << name <<std::endl;
        std::cout << company<< std::endl;
        std::cout << age<< std::endl; 
    }
    void ageGetter(int x){
        std::cout << "you are " << x << " years old"<< std::endl;  
    }
};
int main(){
    std::vector<int> x;
    x.push_back(0);
    x.push_back(5);
    x.push_back(6);
    std::cout << x.at(1) << std::endl;
    std::string username;
    std::getline(std::cin, username);
    coolClass obj1(username, "walmart", 56); 
    obj1.coolMethod();
    obj1.ageGetter(10);

    for (int i = 0; i < 10; i++){
        x.push_back(i);
    }
    int i = 0;
    while(i < x.size()){
        std::cout << x.at(i);
        i++;
    }
    
   return 0;

}