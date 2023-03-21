//
// Created by Varsha on 21-03-2023.
//
#include <iostream>
using namespace std;

class Time{
    int hours, minutes, seconds;
public:
    Time(){
        cout<<"Enter time in the format hh mm ss:";
        cin>>hours>>minutes>>seconds;
    }
    friend void swap(Time &t1, Time &t2);
    void display(){
        cout<<"The time is: "<<hours<<":"<<minutes<<":"<<seconds<<endl;
    }
};

void swap(Time &t1, Time &t2){
    int temp;
    temp = t1.seconds;
    t1.seconds = t2.seconds;
    t2.seconds = temp;
}

int main(){
    Time t1, t2;
    t1.display();
    t2.display();
    swap(t1, t2);
    t1.display();
    t2.display();
    return 0;
}
