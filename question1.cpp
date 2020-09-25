#include<iostream>
#include<string.h>
using namespace std;

class student
{
    char *name;
    int roll;
    int age;
    public:
    student(char *n,int r,int a)
    { 
        name=new char[strlen(n)];
        strcpy(name,n);
        roll=r;
        age=a;
        cout<<"Constructor is created\n";
    }

     void display()
    {
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Roll Number: "<<roll<<endl;
        cout<<"Age: "<<age<<endl;
    }
    ~student()
    {
        delete(name);
        cout<<"Destructor is destroyed\n";
    }
};   


class test:public student
{
    int marks[5];
    public:
    test (char *n,int r,int a,int *m) :student (n,r,a)
    {
        for(int i=0;i<5;i++)
        {
            marks[i]=m[i];
        }
        cout<<"constructor is created\n";
            
    }
    void  display()
        {
            cout<<"Marks of student are: "<<endl;
            for(int i=0;i<5;i++)
            {
                cout<<"Marks of subject "<<i+1<<": "<<marks[i]<<endl;
            }
        }
        ~test()
        {
            delete(marks);
            cout<<"Destructor is destroyed\n";
        }
};
    
int main()
{
    cout<<"Enter the Number of student data you want to enter:";
    int n;
    test **t=new test*[n];
    cin>>n;
    char *na = new char[50];
    int rol;
    int ag;
    int mark[5];
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"Enter Details of students:"<<endl;
    for(int i=0;i<n;i++)
    {
       cout<<"--------------------------------------------------------"<<endl;
       cout<<"Enter Details of "<<i+1<<"st students:"<<endl;
       cout<<"Enter name: ";
       cin.ignore();
       cin.getline(na,50); 
       cout<<"Enter Roll Number: ";
       cin>>rol;
       cout<<"Enter Age: ";
       cin>>ag;
       cout<<"Enter Marks of student : "<<endl;
        for(int j=0;j<5;j++)
        {
            cout<<"Enter Marks of subject "<<j+1<<": ";
            cin>>mark[j];
        }
    
    }
    test t(na,rol,ag,mark);
    for(int i=0;i<n;i++)
    {
        t[i]->student :: display();
        t[i]->display();
    }
    return 0;
}