#include <iostream>
#include <cmath>
using namespace std;

class rectangular;
class polar{
    float angle,radius;
public:
    void init(){
        cout<<"Enter angle and radius:"<<endl;
        cin>>angle>>radius;
        angle = angle*(3.14/180);
    }
    friend class rectangular;
};

class rectangular{
    float x,y;
public:
    rectangular(){
        x=y=0;
    }
    rectangular(polar p){
        x = p.radius*cos(p.angle);
        y = p.radius*sin(p.angle);
    }
    void display(){
        cout<<"x = "<<x<<endl;
        cout<<"y ="<<y<<endl;
    }
};

int main(){
    polar p;
    p.init();
    rectangular r;
    r=p;
    r.display();
    return 0;
}