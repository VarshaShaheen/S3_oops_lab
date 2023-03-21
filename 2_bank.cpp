//
// Created by Varsha on 21-03-2023.
//
#include <iostream>
#include <string>
using namespace std;

class Bank{
private:
    string name, type;
    int acc_no, balance=0, min_balance = 500;
public:
    void init() {
        cout << "Enter the name of the account holder:";
        cin >> name;
        cout << "Enter the account number:";
        cin >> acc_no;
        cout << "Enter the type of account:";
        cin >> type;
    }
    void deposit(){
        int amount;
        cout << "Enter the amount to be deposited the minimum balance should be 500:"<<endl;
        cin >> amount;
        if (balance + amount < min_balance) {
            cout << "Minimum balance should be 500" << endl;
            return;
        }
        balance += amount;
        cout << "Amount deposited successfully" << endl;
    }
    void withdraw(){
        cout<<"Enter the amount to be withdrawn:"<<endl;
        int amount;
        cin>>amount;
        if (balance - amount < min_balance) {
            cout << "Minimum balance should be 500" << endl;
            return;
        }
        balance -= amount;
        cout << "Amount withdrawn successfully" << endl;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};

int main(){
    Bank b1;
    int choice;
    b1.init();
    cout<<"Enter 1 to deposit and 2 to withdraw and 3 to display balance and 0 to quit:"<<endl;
    cin>>choice;
    do{
        switch(choice){
            case 1:
                b1.deposit();
                break;
            case 2:
                b1.withdraw();
                break;
            case 3:
                b1.display();
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
        cout<<"Enter 1 to deposit and 2 to withdraw and 3 to display balance and 0 to quit:"<<endl;
        cin>>choice;
    }while(choice!=0);

    return 0;
}
