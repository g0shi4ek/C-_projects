#include <iostream>
#include <cstring>
#include "planeta.h"
#include <fstream>

using namespace std;
using namespace pl;

ofstream &operator<<(ofstream &out, Planet& el) {
    out << el.getName() << "\t\t" << el.getDiam() << "\t" << el.getLife() <<  "\t" << el.getDiam() <<"\n";
    return out;
}

ifstream &operator>>(ifstream &in, Planet& current) {
    char name1[100];
    int diam1;
    int life1;
    int sput1;

    in >> name1 >> diam1 >> life1 >> sput1;


    char* name_ = new char[strlen(name1) + 1];
    current.setName(name_);
    current.setDiam(diam1);
    current.setLife(life1);
    current.setSput(sput1);

    return in;
}

void Planet::read_db(char * filename, Planet **  arr, int &n){
    ifstream fin(filename, ios::in | ios::binary);
    if (!fin) {
        cout << "you have no file " << filename << endl;
        return;
    }
    fin >> n;

    if ((*arr) == nullptr){
        if (n != 0) {
            (*arr) = new Planet[n];
        }
    }

    for (int i = 0; i < n; i++) {
        Planet* current = &((*arr)[i]);

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

        current->setDiam(diam1);
        current->setLife(life1);
        current->setSput(sput1);

    }
    fin.close();
}

void Planet::print_db(Planet *arr, int n) {
    cout << " YOUR PLANETS " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i].getName() <<"\t\t"<< arr[i].getDiam() << "\t"<< arr[i].getLife() << "\t"<< arr[i].getSput() << endl;
}

void Planet::add_db(Planet **arr, int & n) {
    n+=1;
    Planet ** temp = new Planet *[n];
    // Копируем указатели в новый массив
    for (int i = 0; i < n - 1; i++) {
        temp[i] = arr[i];
    }

    Planet* current = &((*arr)[n-1]);
    cout << "Enter planet name: ";
    char nameInput[100];
    cin.getline(nameInput, 100);

    // Динамическое выделение памяти
    current->name_ = new char[strlen(nameInput) + 1];
    strcpy(current->name_, nameInput);
    cout << "Enter planet diameter: ";
    cin >> current->diam;
    cout << "Enter the planet's life: ";
    cin >> current->life;
    cout << "Enter number of satellites: ";
    cin >> current->sput;
}

int Planet::write_db(char *filename, Planet * arr, int n) {
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

int Planet::find_ind(Planet* arr, int n){
    cout << "Enter planet name: ";
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

void Planet::del_db(Planet** arr, int& n) {
    int ind = Planet::find_ind(*arr,n);
    if (ind != -1) {
        for (int j = ind; j < n - 1; j++) {
            (*arr)[j] = (*arr)[j + 1];
        }
        n--;
        cout << "planet was deleted successfully" << endl;

    } else {
        cout << "planet not found in the list" << endl;
    }

}

void Planet::edit_db(Planet **arr, int n) {
    int ind = Planet::find_ind(*arr,n);
    if (ind != -1) {
        Planet *current = &((*arr)[ind]);
        cout << "Enter new planet name: ";
        char nameInput[100];
        cin.getline(nameInput, 100);

        // Динамическое выделение памяти
        current->name_ = new char[strlen(nameInput) + 1];
        strcpy(current->name_, nameInput);
        cout << "Enter planet diameter: ";
        cin >> current->diam;
        cout << "Enter the planet's life: ";
        cin >> current->life;
        cout << "Enter number of satellites: ";
        cin >> current->sput;
        cout << "planet was changed successfully" << endl;
    }
    else{
        cout << "planet not found in the list" << endl;
    }
}




void Planet::sort_db(Planet ** arr, int  n) {
    bool flag;
    do {
        flag = true;
        for (int i = 0; i < n-1; i++) {
            if ((*arr)[i] > (*arr)[i + 1]){
                char*name = (*arr)[i].name_;
                int diam = (*arr)[i].diam;
                int life = (*arr)[i].life;
                int sput = (*arr)[i].sput;
                (*arr)[i] = (*arr)[i + 1];
                (*arr)[i + 1].setName(name);
                (*arr)[i + 1].setDiam(diam);
                (*arr)[i + 1].setLife(life);
                (*arr)[i + 1].setSput(sput);
                flag = false;
            }
        }
    }while (!flag);
    cout<< "your list was sorted"<<endl;
}




