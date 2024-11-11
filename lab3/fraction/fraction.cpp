#include <iostream>
#include <cstring>
#include "fraction.h"


Fraction operator+(const Fraction& x, const Fraction& y)
{
    int den_wh = x.den * y.den;
    int num_wh = x.num*y.den + y.num * x.den;
    Fraction p(num_wh,den_wh);
    return p;
}

Fraction operator+(const Fraction& x,int a)
{
    int den_wh = x.den;
    int num_wh = x.num + a * x.den;
    Fraction p(num_wh,den_wh);
    return p;
}

Fraction operator+(int a,const Fraction& x)
{
    int den_wh = x.den;
    int num_wh = x.num + a * x.den;
    Fraction p(num_wh,den_wh);
    return p;
}

Fraction operator+(const Fraction& x, double a)
{
    int N_DEC = 4;
    int n = pow(10,N_DEC);
    a = round(a*n)/n;
    Fraction y(a);
    int nod1 = Fraction::gcd(x.num,x.den);
    int x_del = x.num/nod1;
    int x_zn = x.den/nod1;
    int nod2 = Fraction::gcd(y.num,y.den);
    int y_del = y.num/nod2;
    int y_zn = y.den/nod2;
    int den_wh = y_zn*x_zn;
    int num_wh = x_del*y_zn + y_del * x_zn;
    Fraction p(num_wh,den_wh);
    return p;
}

Fraction operator+(double a, const Fraction& x)
{
    int N_DEC = 4;
    int n = pow(10,N_DEC);
    a = round(a*n)/n;
    Fraction y(a);
    int nod1 = Fraction::gcd(x.num,x.den);
    int x_del = x.num/nod1;
    int x_zn = x.den/nod1;
    int nod2 = Fraction::gcd(y.num,y.den);
    int y_del = y.num/nod2;
    int y_zn = y.den/nod2;
    int den_wh = y_zn*x_zn;
    int num_wh = x_del*y_zn + y_del * x_zn;
    Fraction p(num_wh,den_wh);
    return p;
}


int Fraction::gcd(int num, int den){
    num = abs(num);
    den = abs(den);
    while (num % den){
        swap(num %= den, den);
    }
    return den;
}

string Fraction:: view(Fraction fr){
    int num = fr.getNum();
    int den = fr.getDen();
    int wh = 0;
    string res;

    if (num == 0){
        return "0";
    }
    if (den == 0){
        return "wrong input";
    }

    if (den != 0) {
        if (abs(num)>den) {
            wh = num / den;
            num =abs(num% den);
            res.append(to_string(wh));
            res +=" ";
            if (num == 0){
                return res;
            }

        }
        int nod = gcd(num,den);
        num/=nod;
        den/=nod;

        if (abs(num) == den) {
            if (num > 0) {
                return "1";
            } else { return "-1"; }
        }

        res.append(to_string(num));
        res+="/";
        res.append(to_string(den));
        return res;
    }
    else { return "0";}

}






