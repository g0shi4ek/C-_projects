#include <iostream>
#include <cstring>
#include "dom.h"
#include <fstream>

using namespace std;
using namespace dm;

ofstream &operator<<(ofstream &out, Dom& el) {
    out << el.getName() << "\t\t" << el.getLen() << "\t" << el.getLife() <<  "\t" << el.getFl() <<"\n";
    return out;
}

void Dom::read_db(char * filename, Dom **  arr, int &n){
    ifstream fin(filename, ios::in | ios::binary);
    if (!fin) {
        cout << "you have no file " << filename << endl;
        return;
    }
    fin >> n;

    if ((*arr) == nullptr){
        if (n != 0) {
            (*arr) = new Dom[n];
        }
    }

    for (int i = 0; i < n; i++) {
        Dom* current = &((*arr)[i]);

        char name1[100];
        int diam1;
        int life1;
        int sput1;

        fin >> name1 >> diam1 >> life1 >> sput1;


        current->name_ = new char[strlen(name1) + 1];
        strcpy(current->name_, name1);
////        char* checkName = current->getName();
////        cout<< checkName<< endl;
////        delete [] checkName;
////        current->diam = diam1;
////        current->life = life1;
////        current->sput = sput1;

        current->setLen(diam1);
        current->setLife(life1);
        current->setFl(sput1);

    }
    fin.close();
}

void Dom::print_db(Dom *arr, int n) {
    cout << " YOUR HOUSES " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i].getName() <<"\t\t"<< arr[i].getLen() << "\t"<< arr[i].getLife() << "\t"<< arr[i].getFl() << endl;
}

void Dom::add_db(Dom **arr, int & n) {
    n+=1;
    Dom ** temp = new Dom *[n];
    // Копируем указатели в новый массив
    for (int i = 0; i < n - 1; i++) {
        temp[i] = arr[i];
    }

    Dom* current = &((*arr)[n-1]);
    cout << "Enter name: ";
    char nameInput[100];
    cin.getline(nameInput, 100);

    // Динамическое выделение памяти
    current->name_ = new char[strlen(nameInput) + 1];
    strcpy(current->name_, nameInput);
    cout << "Enter length: ";
    cin >> current->len;
    cout << "Enter the amount of people: ";
    cin >> current->life;
    cout << "Enter number of floors: ";
    cin >> current->fl;
}

int Dom::write_db(char *filename, Dom * arr, int n) {
    ofstream file1(filename, ios::out | ios::binary);
    if (!file1) {
        cout << "smt went wrong" << endl;
        return 1;
    }
    file1 << n;
    for (int i = 0; i < n; i++)
        file1 << arr[i];

    file1.close();
    cout<<"file was written successfully"<< endl;
    return 0;
}

int Dom::find_ind(Dom* arr, int n){
    cout << "Enter name: ";
    char nameInput[100];
    cin.getline(nameInput, 100);

    int ind = -1;
    for (int i = 0;i<n; i++){
        if (strcmp(nameInput, arr[i].name_) == 0){
            ind = i;
            break;
        }
    }
    return ind;
}

void Dom::del_db(Dom** arr, int& n) {
    int ind = Dom::find_ind(*arr,n);
    if (ind != -1) {
        for (int j = ind; j < n - 1; j++) {
            (*arr)[j] = (*arr)[j + 1];
        }
        n--;
        cout << "house was deleted successfully" << endl;

    } else {
        cout << "house not found in the list" << endl;
    }

}

void Dom::edit_db(Dom **arr, int n) {
    int ind = Dom::find_ind(*arr,n);
    if (ind != -1) {
        Dom *current = &((*arr)[ind]);
        cout << "Enter new name: ";
        char nameInput[100];
        cin.getline(nameInput, 100);

        // Динамическое выделение памяти
        current->name_ = new char[strlen(nameInput) + 1];
        strcpy(current->name_, nameInput);
        cout << "Enter new length: ";
        cin >> current->len;
        cout << "Enter the amount of people: ";
        cin >> current->life;
        cout << "Enter number of floors: ";
        cin >> current->fl;
        cout << "house was changed successfully" << endl;
    }
    else{
        cout << "house not found in the list" << endl;
    }
}


void Dom::sort_db(Dom ** arr, int  n) {
    bool flag;
    do {
        flag = true;
        for (int i = 0; i < n-1; i++) {
            if ((*arr)[i] > (*arr)[i + 1]){
                char*name = (*arr)[i].name_;
                int len = (*arr)[i].len;
                int life = (*arr)[i].life;
                int fl = (*arr)[i].fl;
                (*arr)[i] = (*arr)[i + 1];
                (*arr)[i + 1].setName(name);
                (*arr)[i + 1].setLen(len);
                (*arr)[i + 1].setLife(life);
                (*arr)[i + 1].setFl(fl);
                flag = false;
            }
        }
    }while (!flag);
    cout<< "your list was sorted"<<endl;
}




