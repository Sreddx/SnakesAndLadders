#include "Board.h"

Board::Board() {
    numCase= 30;
    numLadders = 3;
    numSnakes = 3;
    reward_=3;
    penalty_=3;
    createBoard();
}
Board::Board(int C, int L, int S, int R, int P) {
    numCase = C;
    numLadders = L;
    numSnakes = S;
    reward_ = R;
    penalty_ = P;
    createBoard();
}
void Board::createBoard(){
    srand(time(0));
    int *arr = new int[numSnakes];
    int *arr2 = new int[numLadders];
    int Num;


    for (int i=0; i<numSnakes; i++){
        Num=rand() % numCase+1;
        while (esta(arr,i,Num)==1){
            Num=rand() % numCase + 1;
        }
        arr[i]=Num;
    }


    for (int i=0; i<numLadders; i++){
        Num=rand() % numCase+1;
        while (esta(arr2,i,Num)==1 && esta(arr,numSnakes,Num)==1){
            Num=rand() % numCase + 1;
        }
        arr2[i]=Num;
    }

    for (int i=0; i<numCase; i++){
        if(esta(arr,numSnakes,i)==1){
            board.push_back(new Snake(i+1,penalty_));
        }
        else if (esta(arr2,numLadders,i)==1){
            board.push_back(new Ladder(i+1,reward_));
        }
        else{
            board.push_back(new Case(i+1));
        }

    }
}
void Board::printBoard() {
    int contador=0;
    for(int i=0; i<board.size();i++){
        cout<<" "<<board[i]-> getCaseType()<<" ";
        contador+=1;
        if (contador==6){
            cout<<endl;
            contador=0;
        }
    }
}

int Board::esta(int*a,int size,int numb){
    for(int i=0;i<size;i++) {
        if (a[i] == numb) {
            return 1;
        }
    }
    return -1;
}



int Board::getCasePos(int i) {
    if( i>=0 && i<numCase) {
        return board[i]->getCaseNumb();
    }
    else{
        return -1;
    }
}

char Board::getCaseType(int i) {
    if( i>=0 && i<numCase){
        return board[i]->getCaseType();
    }
    else{
        return 'X';
    }
}

int Board::getCaseSpecial(int i) {
    if(i>=0 && i<numCase){
        return board[i]->getSpecial();
    }
    else{
        return 'X';
    }
}


