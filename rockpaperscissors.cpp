#include<iostream>
#include<ctime>
using namespace std;

char userChoice();
char computerChoice();
void choice(char choice);
void winner(char userchoice, char computerchoice);

int main () {
    cout<< "******** Rock-Paper-Scissors Game ********\n\n";
    char userchoice = userChoice();
    cout<< "Your choice is ";
    choice(userchoice);
    char computerchoice = computerChoice();
    cout<< "Computer choice is ";
    choice(computerchoice);
    winner(userchoice, computerchoice);
    cout<< "******************************************\n";
    return 0;
}

char userChoice() {
    char option;
    do {
    cout<< "Enter Rock(r), Paper(p) or Scissors(s): ";
    cin>> option;
    cout<<'\n';
    }while ( option != 'r' && option != 's' && option != 'p');
    return option;
}
char computerChoice() {
    srand(time(NULL));
    int choice = rand()%3+1;

    switch (choice) {
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
    }
    return 'r'; 
    }
void choice(char choice) {
    switch(choice) {
        case 'r': cout<< "Rock\n";
            break;
        case 'p': cout<< "Paper\n";
            break;
        case 's': cout<< "Scissors\n";
            break;
    }
}
void winner(char userchoice, char computerchoice) {
    switch (userchoice) {
        case 'r': if (computerchoice == 'r') {
                    cout<< "That's a tied!\n";
                } else if (computerchoice == 's') {
                    cout<< "You won!\n";
                } else {
                    cout<< "You lose!\n";
                }
        break;
        case 's': if (computerchoice == 'r') {
                    cout<< "You lose!\n";
                } else if (computerchoice == 's') {
                    cout<< "That's a tied!\n";
                } else {
                    cout<< "You won!\n";
                }
        break;
        case 'p': if (computerchoice == 'r') {
                    cout<< "You won!\n";
                } else if (computerchoice == 's') {
                    cout<< "You lose!\n";
                } else {
                    cout<< "That's a tied!\n";
                }
        break;
    }
}