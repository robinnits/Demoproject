#include<iostream>
#include<ctime>
using namespace std;

void drawboard(char *space);
void playermove(char *space, char player);
void computermove(char *space, char computer);
bool checkwinner(char *space, char player, char computer);
bool checktie(char *space);

int main() {
    srand(time(NULL));
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool running = true;
    char player = 'X', computer = 'O';
    drawboard(spaces);
    while(running) {
        
        playermove(spaces, player);
        drawboard(spaces);
        if(checkwinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if(checktie(spaces)) {
            running = false;
            break;
        }
        computermove(spaces, computer);
        drawboard(spaces);
        if(checkwinner(spaces, player, computer)) {
            running = false;
            break;
        }
        else if(checktie(spaces)) {
            running = false;
            break;
        }

    }
    cout<<"THANKS FOR PLAYING!\n";
    return 0;
}

void drawboard(char *space) {
    cout<<"     |     |     \n";
    cout<<"  "<<space[0]<<"  |  "<<space[1]<<"  |  "<<space[2]<<"  \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<space[3]<<"  |  "<<space[4]<<"  |  "<<space[5]<<"  \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<space[6]<<"  |  "<<space[7]<<"  |  "<<space[8]<<"  \n";
    cout<<"     |     |     \n";
}

void playermove(char *space, char player) {
    int i = -1;
    while(true) {
        cout<<"Enter the position(1-9): \n";
        cin>>i;
        if(i>=1 && i<= 9 && space[i-1]==' ') {
            space[i-1] = player;
            break;
        }
    }
}

void computermove(char *space, char computer) {
    while(true) {
        int i = rand()%9;
        if(space[i]==' ') {
            space[i] = computer;
            break;
        }
    }
}

bool checkwinner(char *space, char player, char computer) {
    if(space[0]!=' ' && space[0]==space[1] && space[1]==space[2]) {
        space[0] == player ? cout<<"YOU WON!\n" : cout<<"YOU LOSE!\n";
    } else if(space[3]!=' ' && space[3]==space[4] && space[4]==space[5]) {
        space[3] == player ? cout<<"YOU WON!\n" : cout<<"YOU LOSE!\n";
    } else if(space[6]!=' ' && space[6]==space[7] && space[7]==space[8]) {
        space[6] == player ? cout<<"YOU WON!\n" : cout<<"YOU LOSE!\n";
    } else if(space[0]!=' ' && space[0]==space[3] && space[3]==space[6]) {
        space[0] == player ? cout<<"YOU WON!\n" : cout<<"YOU LOSE!\n";
    } else if(space[1]!=' ' && space[1]==space[4] && space[4]==space[7]) {
        space[1] == player ? cout<<"YOU WON!\n" : cout<<"YOU LOSE!\n";
    } else if(space[2]!=' ' && space[2]==space[5] && space[5]==space[8]) {
        space[2] == player ? cout<<"YOU WON!\n" : cout<<"YOU LOSE!\n";
    } else if(space[0]!=' ' && space[0]==space[4] && space[4]==space[8]) {
        space[0] == player ? cout<<"YOU WON!\n" : cout<<"YOU LOSE!\n";
    } else if(space[2]!=' ' && space[2]==space[4] && space[4]==space[6]) {
        space[2] == player ? cout<<"YOU WON!\n" : cout<<"YOU LOSE!\n";
    }
    else {
        return false;
    }
    return true;
}

bool checktie(char *space) {
    for(int i =0; i<9; i++) {
        if(space[i]==' ') {
            return false;
        }
    }
    cout<<"IT'S A TIE\n";
    return true;
}