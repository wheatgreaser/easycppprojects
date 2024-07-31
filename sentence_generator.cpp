#include <iostream>
#include <string>
#include <sstream>

using String = std::string;

int main(){
    String words[4] = {"apple", "ball", "cat", "dog"};
    String current_word;
    String sentence = "dog apple ball cat apple dog apple cat cat cat dog apple cat cat cat cat dog apple cat dog apple cat cat apple apple dog cat";
    String tokenarray[100];
    std::istringstream iss(sentence); //input stream
    String token;
    int a_a = 0, a_b = 0, a_c = 0, a_d = 0, b_a = 0, b_b = 0, b_c = 0, b_d = 0, c_a = 0, c_b = 0, c_c = 0, c_d = 0, d_a = 0, d_b = 0, d_c = 0, d_d = 0;
    
    int p_apple[10];
    int p_ball[10];
    int p_cat[10];
    int p_dog[10];

    int j = 0;
    while(std::getline(iss, token, ' ')){ //getline takes string from the input stream
        tokenarray[j] = token;
        j++;
    } 
    for(int i = 0; i < 4; i++){
        current_word = words[i];
        for(int k = 0; k <= j; k++){
            if(current_word == tokenarray[k]){
                if(tokenarray[k+1] == "apple" && i == 0){
                    a_a += 1;
                }
                if(tokenarray[k+1] == "ball" && i == 0){
                    a_b += 1;
                } 
                if(tokenarray[k+1] == "cat" && i == 0){
                    a_c += 1;
                }
                if(tokenarray[k+1] == "dog" && i == 0){
                    a_d += 1;
                }
                if(tokenarray[k+1] == "apple" && i == 1){
                    b_a += 1;
                }
                if(tokenarray[k+1] == "ball" && i == 1){
                    b_b += 1;
                } 
                if(tokenarray[k+1] == "cat" && i == 1){
                    b_c += 1;
                }
                if(tokenarray[k+1] == "dog" && i == 1){
                    b_d += 1;
                }
                if(tokenarray[k+1] == "apple" && i == 2){
                    c_a += 1;
                }
                if(tokenarray[k+1] == "ball" && i == 2){
                    c_b += 1;
                } 
                if(tokenarray[k+1] == "cat" && i == 2){
                    c_c += 1;
                }
                if(tokenarray[k+1] == "dog" && i == 2){
                    c_d += 1;
                }
                if(tokenarray[k+1] == "apple" && i == 3){
                    d_a += 1;
                }
                if(tokenarray[k+1] == "ball" && i == 3){
                    d_b += 1;
                } 
                if(tokenarray[k+1] == "cat" && i == 3){
                    d_c += 1;
                }
                if(tokenarray[k+1] == "dog" && i == 3){
                    d_d += 1;
                }
            }
    }
    }
    
    std::cout << a_a << std::endl; 
    std::cout << a_b << std::endl;
    std::cout << a_c << std::endl;
    std::cout << a_d << std::endl;
    
    
    return 0;
}