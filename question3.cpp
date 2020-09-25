/*Extend the program 2 to include a class sports, which stores the marks in sports activity. 
Derive the result class from the classes ‘test’ and ‘Activities’. 
Calculate the total marks and percentage of a student.*/
#include<iostream>
#include<string.h>
using namespace std;

class student{
    char *name;
    int roll;
    int age;
    public:
        student(char *n,int r,int a){
            cout<<"Constructor of student called-----"<<endl;
            name=new char[strlen(n)];
            strcpy(name,n);
            roll=r;
            age=a;
        }
        void get(){
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Roll Number: "<<roll<<endl;
            cout<<"Age: "<<age<<endl;
        }
        ~student(){
            delete(name);
        }
};

class test:virtual public student{
    protected:
        int marks[3];
    public:
        test(char *n,int r,int a,int *m):student(n,r,a){
            cout<<"Constructor of test called-----"<<endl;
            for(int i=0;i<3;i++){
                marks[i]=m[i];
            }
        }
        void get(){
            student::get();
            cout<<"Marks of student are: "<<endl;
            for(int i=0;i<3;i++){
                cout<<"Marks of subject "<<i+1<<": "<<marks[i]<<endl;
            }
        }
};

class sport:virtual public student{
    protected:
        int marks_sport[2];
    public:
        sport(char *n,int r,int a,int *m):student(n,r,a){
            cout<<"Constructor of sport called-----"<<endl;
            for(int i=0;i<2;i++){
                marks_sport[i]=m[i];
            }
        }
        void get(){
            cout<<"Marks of student in sports activity are: "<<endl;
            for(int i=0;i<2;i++){
                cout<<"Marks of sport "<<i+1<<": "<<marks_sport[i]<<endl;
            }
        }
};

class result:public test,public sport{
    int total;
    float percentage;
    public:
        result(char *n,int r,int a,int *m,int *ms):test(n,r,a,m),sport(n,r,a,ms),student(n,r,a){
            cout<<"Constructor of result called-----"<<endl;
            total=0;
            percentage=0.0;
        }
        void cal(){
            for(int i=0;i<3;i++){
                total=total+marks[i];
            }
            for(int i=0;i<2;i++){
                total=total+marks_sport[i];
            }
            percentage=total/5.0;
        }
        void get(){
            test::get();
            sport::get();
            cout<<"Total: "<<total<<endl;
            cout<<"Percentage: "<<percentage<<endl;
        }
};

int main(){
    //cout<<"Enter the Number of student data you want to enter:";
    //int n;
    //cin>>n;
    char *name = new char[50];
    int roll;
    int age;
    int marks[3];
    int marks_sport[3];
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"Enter Details of students:"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"Enter Details of "<<"st students:"<<endl;
    cout<<"Enter name: ";
    cin.getline(name,50); 
    cout<<"Enter Roll Number: ";
    cin>>roll;
    cout<<"Enter Age: ";
    cin>>age;
    cout<<"Enter Marks of student in subjects : "<<endl;
    for(int j=0;j<3;j++){
        cout<<"Enter Marks of subject "<<": ";
        cin>>marks[j];
    }
    cout<<"Enter Marks of student in sports : "<<endl;
    for(int j=0;j<2;j++){
        cout<<"Enter Marks of sport "<<": ";
        cin>>marks_sport[j];
    }
    result t(name,roll,age,marks,marks_sport);
    t.cal();
    t.get();
    return 0;
}