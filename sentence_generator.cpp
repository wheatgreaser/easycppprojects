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
    float a_a = 0, a_b = 0, a_c = 0, a_d = 0, b_a = 0, b_b = 0, b_c = 0, b_d = 0, c_a = 0, c_b = 0, c_c = 0, c_d = 0, d_a = 0, d_b = 0, d_c = 0, d_d = 0;
    
    float p_apple[4];
    float p_ball[4];
    float p_cat[4];
    float p_dog[4];

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

    // computing the probabilities
    p_apple[0] = a_a / (a_a + a_b + a_c + a_d);
    p_apple[1] = a_b / (a_a + a_b + a_c + a_d);
    p_apple[2] = a_c / (a_a + a_b + a_c + a_d);
    p_apple[3] = a_d / (a_a + a_b + a_c + a_d);

    p_ball[0] = b_a / (b_a + b_b + b_c + b_d);
    p_ball[1] = b_b / (b_a + b_b + b_c + b_d);
    p_ball[2] = b_c / (b_a + b_b + b_c + b_d);
    p_ball[3] = b_d / (b_a + b_b + b_c + b_d);

    p_cat[0] = c_a / (c_a + c_b + c_c + c_d);
    p_cat[1] = c_b / (c_a + c_b + c_c + c_d);
    p_cat[2] = c_c / (c_a + c_b + c_c + c_d);
    p_cat[3] = c_d / (c_a + c_b + c_c + c_d);

    p_dog[0] = d_a / (d_a + d_b + d_c + d_d);
    p_dog[1] = d_b / (d_a + d_b + d_c + d_d);
    p_dog[2] = d_c / (d_a + d_b + d_c + d_d);
    p_dog[3] = d_d / (d_a + d_b + d_c + d_d);
    
    for(int i = 0; i < 4; i++){
        std::cout << p_ball[i] <<std::endl;
    }

    int max1, max2, max3, max4;
    max1 = p_apple[0];
    max2 = p_ball[0];
    max3 = p_cat[0];
    max4 = p_dog[0];
    int pred_apple_index, pred_ball_index, pred_cat_index, pred_dog_index;

    for(int i = 0; i < 4; i++){   
        if(max1 < p_apple[i]){
            max1 = p_apple[i];
            pred_apple_index = i;
            break;

        }
    }

    for(int i = 0; i < 4; i++){   
        if(max2 < p_ball[i]){
            max2 = p_ball[i];
            pred_ball_index = i;
            break;

        }
    }

    for(int i = 0; i < 4; i++){   
        if(max3 < p_cat[i]){
            max3 = p_cat[i];
            pred_cat_index = i;
            break;

        }
    }

    for(int i = 0; i < 4; i++){   
        if(max4 < p_dog[i]){
            max4 = p_dog[i];
            pred_dog_index = i;
            break;

        }
    }

    
    
    return 0;
}