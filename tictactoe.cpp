#include <iostream>

int checkWin(char board[3][3]){
     // horizontal check
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][1] == board[i][2] && board[i][1] == 'X'){
            return 1;
            
        }
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][1] == board[i][2] && board[i][1] == 'O'){
            return 2;
        }
    }
    for(int j = 0; j < 3; j++){ //vertical check
        if(board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[1][j] == board[2][j] && board[1][j] == 'X'){
            return 1;
        }
        if(board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[1][j] == board[2][j] && board[1][j] == 'O'){
            return 2;
        }

    }
    int flag = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                flag = 0;
                break;
            }
        }
    }
    if(flag == 1){
        return 3;
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] == board[2][2] && board[1][1] == 'X'){
        return 1;
    }
    else if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] == board[2][2] && board[1][1] == 'O'){
        return 2;
    }
    else{
        return 0;
    }
    
    
    

}
void Xmove(char board[3][3]){
    int x;
    int y;

    std::cout << "X move: enter x coordinate" << '\n';
    std::cin >> x;

    std::cout << "X move: enter y coordinate" << '\n';
    std::cin >> y;

    board[x][y] = 'X';
    
}
void Omove(char board[3][3]){
    int x;
    int y;

    std::cout << "O move: enter x coordinate" << '\n';
    std::cin >> x;

    std::cout << "O move: enter y coordinate" << '\n';
    std::cin >> y;

    board[x][y] = 'O';
    
}
void boardDisplay(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << board[i][j] << " ";
        }
        std::cout << '\n';
    }
}
int main(){
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' ' }, {' ', ' ', ' '}};

    while(checkWin(board) == 0){
        Xmove(board);
        boardDisplay(board);
        if(checkWin(board) != 0){
            break;
        }
        Omove(board);
        boardDisplay(board);
        if(checkWin(board) != 0){
            break;
        }
    }
    if (checkWin(board) == 1){
        std::cout << "X wins" << '\n';
    }
    else if(checkWin(board) == 2){
        std::cout << "Y wins" << '\n';
    }
    else if(checkWin(board) == 3){
        std::cout << "It's a draw" << '\n';
    }
    return 0;
}