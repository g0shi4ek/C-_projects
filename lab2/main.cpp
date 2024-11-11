#include <iostream>
#include <cstring>
#include <fstream>
#include "planeta/planeta.h"
#include "dom/dom.h"

using namespace std;

int menu(){
    cout << " ============== MENU ========================\n";
    cout << "1 - ADD ELEMENT \t 4 - PRINT LIST" << endl;
    cout << "2 - WRITE TO FILE \t 5 - SORT LIST " << endl;
    cout << "3 - EDIT LIST \t\t 6 -DELETE ELEMENT " << endl;
    cout << "\t\t 7 - END " << endl;
    cout << " ENTER NUMBER FROM 1 TO 7" << endl;
    int resp;
    cin >> resp;
    cin.clear();
    cin.ignore(10, '\n');
    return resp;
}




int main() {
    // new book => b->name ,?????????? ????? ??????? ???? ????????? ??????????? ??????????? => ??? ??????? ????????? ? ????????? ??????
//// ? ???????????? this->book ????????????? ??????? ?????????? ?????????? ?? ?? ???? ?????????? ??? ???? ?? ??????????
    int flag = 0;
    cout<< "Enter 1 if you want to edit planets list, else enter 0\n"<<endl;
    cin>>flag;
    if (flag == 1) {
        pl::Planet * arr = nullptr;
        char *filename = "C:\\Users\\dassa\\CLionProjects\\templates\\lab2\\dbase.txt";
        int n = 0;
        int ind;
        pl::Planet::read_db(filename, &arr, n);
        cout<<n<<endl;
        pl::Planet::print_db(arr, n);
        while (true) {
            switch (menu()) {
                case 1:
                    pl::Planet::add_db(&arr, n);
                    pl::Planet::print_db(arr, n);
                    break;
                case 2:
                    pl::Planet::write_db(filename, arr, n);
                    break;
                case 3:
                    pl::Planet::edit_db(&arr, n);
                    break;
                case 4:
                    pl::Planet::print_db(arr, n);
                    break;

                case 6:
                    pl::Planet::del_db(&arr, n);
                    pl::Planet::print_db(arr, n);
                    break;

                case 5:
                    pl::Planet::sort_db(&arr, n);
                    break;

                case 7:
                    delete[] arr;
                    arr = nullptr;
                    return 0;

                default:
                    cout << "you can enter numbers only from 1 to 7" << endl;
                    break;
            }
        }
    }
    else{
        dm::Dom * arr = nullptr;
        char *filename = "C:\\Users\\dassa\\CLionProjects\\templates\\lab2\\dbase2.txt";
        int n = 0;
        int ind;
        dm::Dom::read_db(filename, &arr, n);
        cout<<n<<endl;
        dm::Dom::print_db(arr, n);
        while (true) {
            switch (menu()) {
                case 1:
                    dm::Dom::add_db(&arr, n);
                    dm::Dom::print_db(arr, n);
                    break;
                case 2:
                    dm::Dom::write_db(filename, arr, n);
                    break;
                case 3:
                    dm::Dom::edit_db(&arr,n);
                    break;
                case 4:
                    dm::Dom::print_db(arr, n);
                    break;

                case 6:
                    dm::Dom::del_db(&arr,n);
                    dm::Dom::print_db(arr, n);
                    break;

                case 5:
                    dm::Dom::sort_db(&arr, n);
                    break;

                case 7:
                    delete[] arr;
                    return 0;

                default:
                    cout << "you can enter numbers only from 1 to 7" << endl;
                    break;
            }
        }
    }
    return 0;
}
