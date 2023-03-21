#include <iostream>
using namespace std;

class date{
    int day, month, year;
    int max_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    void init(){
        cout<<"Enter the date in the format DD-MM-YYYY:";
        cin>>day>>month>>year;
    }
    void operator+(int n){
        int i;
        for(i=0;i<n;i++){
            if(day != max_days[month]){
                day++;
            }
            else{
                day = 1;
                if(month != 12){
                    month++;
                }
                else{
                    month = 1;
                    year++;
                }
            }
        }

    }
    void display(int n){
        cout<<"The date after adding "<<n<<" days is: "<<day<<"-"<<month<<"-"<<year<<endl;
    }
};

int main(){
    date d1;
    int add;
    d1.init();
    cout<<"Enter the number of days to be added:";
    cin>>add;
    d1 + add;
    d1.display(add);
    return 0;
}