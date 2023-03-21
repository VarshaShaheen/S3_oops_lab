//
// Created by Varsha on 21-03-2023.
//
#include <iostream>
using namespace std;

class array{
private:
    static int arr[100],n;
    int i,sum=0;
public:
    void init(){
        cout<<"Enter the number of elements in the array:";
        cin>>n;
        cout<<"Enter the elements of the array:";
        for(i=0;i<n;i++){
            cin>>arr[i];
        }
    }
    void average(){
        for(i=0;i<n;i++){
            sum+=arr[i];
        }
        cout<<"The average of the array is: "<<sum/n<<endl;
    }
    void multiply(){
        int multiplier;
        cout<<"Enter the multiplier:";
        cin>>multiplier;
        for(i=0;i<n;i++){
            arr[i]*=multiplier;
        }
        cout<<"The array is: ";
    }
    void sort(){
        int temp;
        for(i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        cout<<"The array after sorting is: ";
    }
    void display(){
        for(i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int array::arr[100]={0};
int array::n=0;

int main(){
    array a1,a2,a3,a4;
    a1.init();
    a2.average();
    a3.multiply();
    a3.display();
    a4.sort();
    a4.display();
    return 0;
}
