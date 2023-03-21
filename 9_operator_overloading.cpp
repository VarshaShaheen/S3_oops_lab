//
// Created by Varsha on 21-03-2023.
//
//distance is measured in feet and inches. Overload the operator -- for decrementing the distance, - for subtracting two distances

#include <iostream>
using namespace std;

class dist{
private:
    int feet;
    int inches;
public:
    void init(){
        cout<<"Enter the feet and inches: ";
        cin>>feet>>inches;
    }
    void operator --(){
        inches += feet*12;
        inches--;
        feet = inches/12;
        inches = inches%12;
    }
    dist operator-(dist d2){
        dist temp;
        inches += feet*12;
        d2.inches += d2.feet*12;
        temp.inches = inches - d2.inches;
        temp.feet = temp.inches/12;
        temp.inches = temp.inches%12;
        return temp;
    }
    void display(){
        cout<< "Feet: "<< feet<< endl;
        cout<< "Inches: "<< inches<< endl;
    }
};

int main(){
    dist d1,d2,d3;
    d1.init();
    d2.init();
    --d1;
    d1.display();
    d3 = d1-d2;
    d3.display();
    return 0;
}