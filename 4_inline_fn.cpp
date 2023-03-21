//
// Created by Varsha on 21-03-2023.
//
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class triangle{
    int x1,x2,x3,y1,y2,y3,l1,l2,l3;
public:
    void init(){
        cout<<"Enter the x coordinates:";
        cin>>x1>>x2>>x3;
        cout<<"Enter the y coordinates:";
        cin>>y1>>y2>>y3;
    }

    void length(){
        l1 = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        l2 = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
        l3 = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
    }

    int check_validity(){
        if(l1+l2>l3 && l2+l3>l1 && l3+l1>l2){
            return 1;
        }
        else{
            cout<<"Invalid triangle"<<endl;
            return 0;
        }
    }

    inline void shortest_side(){
        cout<<"The shortest side is: "<<min(l1,min(l2,l3))<<endl;
    }
};

int main(){
    triangle t1;
    t1.init();
    t1.length();
    if(t1.check_validity()){
        t1.shortest_side();
    }
    return 0;
}