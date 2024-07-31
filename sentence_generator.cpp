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
    int a_a, a_b, a_c, a_d;
    
    int p_apple[100];
    int p_ball[100];
    int p_cat[100];
    int p_dog[100];

    int j = 0;
    while(std::getline(iss, token, ' ')){ //getline takes string from the input stream
        tokenarray[j] = token;
        j++;
    } 

    for(int i =0; i < sizeof(words); i++){
        current_word = words[i];
        for(int k = 0; k < sizeof(tokenarray); k++){
            if(current_word == tokenarray[k]){
                if(tokenarray[k+1] == "apple" && i==0){
                    a_a += 1;
                }
                if(tokenarray[k+1] == "apple" && i==1){
                    a_b += 1;
                } 
                if(tokenarray[k+1] == "apple" && i==2){
                    a_c += 1;
                }
                if(tokenarray[k+1] == "apple" && i==3){
                    a_d += 1;
                }
            }
        } 
    }
    
    
    return 0;
}