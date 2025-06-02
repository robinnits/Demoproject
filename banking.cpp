#include<iostream>
#include<iomanip>
#include<limits>
using namespace std;

double deposit(double current_balance, double deposit);
double withdraw(double current_balance, double withdraw);

int  main() {
    double current_balance, deposit1, withdraw1;
    int choice;
    string option;
    current_balance= 10000;
    do {
    cout<< "1. Show balance\n2. Menu\n3. EXIT!\n";
    cin>> choice;

    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize> ::max(), '\n');
        cout<< "Invalid Input!\n";
        continue;
    }

    switch(choice) {
        case 1:cout<<"Your current balance is: $" << setprecision(2) << fixed << current_balance <<endl;
        break;
        case 2: cout<<"You want to deposit or withdraw?"<<endl;
        cin>> option;
        if (option == "deposit") {
            cout<<"Amount: "<<endl;
            cin>> deposit1;
            current_balance = deposit(current_balance, deposit1);
        } else if ( option == "withdraw") {
            do {
                cout<<"Amount? (Must be less than current balance): "<<endl;
                cin>> withdraw1;
            }while(withdraw1 > current_balance);
            current_balance = withdraw(current_balance, withdraw1);
        } else {
            cout<< "Please enter the valid option.\n";
        }
        break;
        case 3: cout<<"Thank you for using this system!\n";
        break;
        default: cout<< "Invalid Input!\n";
        break;
        }
    } while (choice != 3);
    
    cout<<"Your current balance is: $" << current_balance<<endl;
    return 0;
}

double deposit(double current_balance, double deposit) {
    return current_balance + deposit;
}

double withdraw(double current_balance, double withdraw) {
return current_balance - withdraw;
}