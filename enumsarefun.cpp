#include <iostream>
#include <cstdlib>
#include <time.h>

namespace Colors{
    enum Color{
        red,
        blue,
        green,
};
}

namespace MonsterTypes{
    enum MonsterType{
        golbin,
        elf,
        human,
        ghoul,
        troll,
    };
}

int main(){
    Colors::Color apple = Colors::blue;
    if (apple == Colors::blue){
        std::cout << "great success" << std::endl;
    }
    srand(time(0));
    int roll =  rand() / 10000;
    if(roll == 3){
        std::cout << "yer a " << MonsterTypes::golbin << " Harry" << std::endl;
        MonsterTypes::MonsterType monster = MonsterTypes::golbin;

    }
   
    //std::cout << apple;
    return 0;
}