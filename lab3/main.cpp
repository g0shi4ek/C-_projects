#include <iostream>
#include <cstring>
#include <string.h>
#include "fraction/fraction.h"
#include <stdbool.h>

using namespace std;

std::ostream& operator << (std::ostream &os, const Fraction& fr)
{
    string res = Fraction::view(fr);
    return os << res;
}

std::istream& operator >> (std::istream& in, Fraction& z)
{
    string a;
    getline(cin,a);
    if (a == "0"){
        z.setNum(0);
        z.setDen(1);
    }
    else if ((a.find("/") == string::npos)) {
        int b = stoi(a);
        z.setNum(b);
        z.setDen(1);
    }
    else {
        Fraction fr(&a);
        z.setNum(fr.getNum());
        z.setDen(fr.getDen());
    }
    return in;
}

int interactive(){
    cout<<"Enter your fraction"<<endl;
    Fraction z;
    cin>>z;
    std::cout << "z = " << z << std::endl;
    // проверка конструкторов
    Fraction fr1(10, 14), fr2;
    std::cout << "fr2 = " << fr2 << std::endl;
    std::cout << "fr1 = " << fr1 << std::endl;
    string fr_s = "-1 4/8";
    Fraction fr(&fr_s); //
    std::cout << "fr = " << fr << std::endl;
    Fraction x(z), y;
    std::cout << "x = " << x << std::endl;
    double dbl = -1.25;
    Fraction f = dbl;
    cout << "f = " << f<< std::endl;
    // проверка перегруженной операции "+"
    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;
    std::cout << "y=" << y << std::endl;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;
    return 0;
}

int demo(){
    cout<<"Your fraction = 1/2"<<endl;
    string a = "1/2";
    Fraction z(&a);
    std::cout << "z = " << z << std::endl;
    // проверка конструкторов
    Fraction fr1(10, 14), fr2;
    std::cout << "fr2 = " << fr2 << std::endl;
    std::cout << "fr1 = " << fr1 << std::endl;
    string fr_s = "-1 4/8";
    Fraction fr(&fr_s); //
    std::cout << "fr = " << fr << std::endl;
    Fraction x(z), y;
    std::cout << "x = " << x << std::endl;
    double dbl = -1.25;
    Fraction f = dbl;
    cout << "f = " << f<< std::endl;
    // проверка перегруженной операции "+"
    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;
    return 0;
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");
    bool isInteractive = false;    // по умолчанию демо-режим.

    // Если i передается в качестве аргумента, то программу
    // необходимо запустить в интерактивном режиме
    if ((argc == 2) && strcmp(argv[1], "i") == 0) {
        isInteractive = true;
    }
    isInteractive = true;

    if (isInteractive) {
        return interactive();

    } else {
        return demo();
    }
}
