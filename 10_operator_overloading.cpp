//
// Created by Varsha on 21-03-2023.
//
#include <iostream>
#include <cstring>
using namespace std;

class data{
    char str[100];
public:
    void init(){
        cout<<"Enter the string:"<<endl;
        cin>>str;
    }
    data operator + (data ob){
        data temp;
        strcat(str,ob.str);
        strcpy(temp.str,str);
        return temp;
    }
    void operator -(){
        strcpy(str,strrev(str));
    }
    void display(){
        cout<<str<<endl;
    }
};

int main(){
    data s1,s2,s3;
    s1.init();
    s2.init();
    s3 = s1 + s2;
    s3.display();
    -s3;
    s3.display();
    return 0;
}