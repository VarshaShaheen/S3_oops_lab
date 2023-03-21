/* Define a class date that contains details like year, month and date. Write a C++ program
 * to check the validity of date you have entered and display the next day*/

#include <iostream>
using namespace std;

class date {
private:
    int year;
    int month;
    int day;
    int max_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int validity = 1;
public:
    void init() {
        cout<<"Enter the date in the format DD-MM-YYYY:";
        cin>>day>>month>>year;
    }

    void display() {
        cout<<"The next day is: "<<day<<"-"<<month<<"-"<<year<<endl;
    }

    void is_leap() {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            max_days[2] = 29;
        }
    }

    void valid() {
        is_leap();
        if (year <= 0 || month < 1 || month > 12 || day < 1 || day > max_days[month]) {
            validity = 0;
        }
    }

    void next_day() {
        valid();
        if (!validity) {
            cout << "Invalid date" << endl;
            return;
        }
        if (day < max_days[month]) {
            day++;
        } else {
            day = 1;
            if (month < 12) {
                month++;
            } else {
                month = 1;
                year++;
            }
        }
        display();
    }
};

int main() {
    date d1;
    d1.init();
    d1.next_day();
    return 0;
}