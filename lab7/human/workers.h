#ifndef TEMPLATES_WORKERS_H
#define TEMPLATES_WORKERS_H
#include <iostream>
#include <string.h>

using namespace std;

class Personnel {
protected:
    int hours;
    char * name;

public:
    Personnel(): name(nullptr), hours(0) {add(this);}
    Personnel(char * name_, int h){
        name = new char[strlen(name_) + 1];
        strcpy(name, name_);
        hours = h;
        add(this);
    }

    virtual ~Personnel()  = 0;
    static Personnel** begin; // динамический массив
    static int n;
    static void add(Personnel* el);
    static void print();
    virtual void show() = 0;

};


class Admin: public Personnel{
    int days;
public:
    Admin(): Personnel(), days(0){}
    Admin(char*n, int h, int d): Personnel(n,h), days(d){}
    //~Admin() {delete[] name;}
    virtual void show(){
        cout<<'\n' << "Name: "<< name<<endl;
        cout <<"Hours: "<< hours<<endl;
        cout<<"Days: "<< days<<'\n'<<endl;
    }
};

class Worker: public Personnel{
    int salary;
public:
    friend class Engineer;
    Worker(): Personnel(), salary(0){}
    Worker(char*n, int h, int s): Personnel(n,h), salary(s){}
    //~Worker() {delete[] name;}
    virtual void show(){
        cout<<'\n' << "Name: "<< name<<endl;
        cout <<"Hours: "<< hours<<endl;
        cout<<"Salary: "<< salary<<'\n'<<endl;
    }
};

class Engineer: public Worker{
    int details;
public:
    Engineer(): Worker(), details(0){}
    Engineer(char*n, int h, int s, int det): Worker(n,h,s), details(det){}
    //~Engineer() {delete[] name;}
    virtual void show(){
        cout<<'\n' << "Name: "<< name<<endl;
        cout <<"Hours: "<< hours<<endl;
        cout<<"Salary: "<< salary<<endl;
        cout<<"Details: "<< details<<'\n'<<endl;
    }
};
#endif //TEMPLATES_WORKERS_H
