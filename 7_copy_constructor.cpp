//
// Created by Varsha on 21-03-2023.
//
#include <iostream>
using namespace std;

class array{
private:
    int a[100],n,i;
public:
    array(){
        cout<<"Enter the number of elements in the array:";
        cin>>n;
        cout<<"Enter the elements of the array:";
        for(i=0;i<n;i++){
            cin>>a[i];
        }
    }
    array(array &a1){
        n=a1.n;
        for(i=0;i<n;i++){
            a[i]=a1.a[i];
        }
    }
    void mode(){
        int max=0,mode=0;
        for(i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(a[i]==a[j]){
                    count++;
                }
            }
            if(count>max){
                max=count;
                mode=a[i];
            }
        }
        cout<<"The mode of the array is: "<<mode<<endl;
        cout<<"The frequency of the mode is: "<<max<<endl;
    }
};

int main(){
    array a1,a2(a1);
    a2.mode();
    return 0;
}