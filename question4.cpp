/*Create a class ‘shape’. Derive three classes from it: Circle, Triangle and Rectangle. 
Include the relevant data members and functions in all the classes. 
Find the area of each shape and display it*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class shape{
    protected:
        float area;
    public:
        void get(){
            cout<<area<<endl;
        }
};

class circle:private shape{
    float radius;
    public:
        circle(float r){
            cout<<"Constructor of circle called-----"<<endl;
            radius=r;
        }
        void cal(){
            area=3.14*radius*radius;
        }
        void get(){
            cout<<"Area of circle: ";
            shape::get();
        }
};

class trinagle:private shape{
    float s1;
    float s2;
    float s3;
    public:
        trinagle(float sd1,float sd2,float sd3){
            cout<<"Constructor of triangle called-----"<<endl;
            s1=sd1;
            s2=sd2;
            s3=sd3;
        }
        void cal(){
            float sp=(s1+s2+s3)/2.0;
            area=sqrt((sp*(sp-s1)*(sp-s2)*(sp-s3)));
        }
        void get(){
            cout<<"Area of triangle: ";
            shape::get();
        }
};

class rectangle:private shape{
    int l;
    int b;
    public:
        rectangle(int ln,int bh){
            cout<<"Constructor of rectangle called-----"<<endl;
            l=ln;
            b=bh;
        }
        void cal(){
            area=l*b;
        }
        void get(){
            cout<<"Area of rectangle: ";
            shape::get();
        }
};

int main(){
    circle c(2.5);
    trinagle t(2.5,3.5,4.5);
    rectangle r(20,30);
    c.cal();
    c.get();
    t.cal();
    t.get();
    r.cal();
    r.get();
    return 0;
}