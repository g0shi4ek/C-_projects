#ifndef LAB3_FRACTION_H
#define LAB3_FRACTION_H
#include <string>
#include <math.h>
using namespace std;


class Fraction {
    int num;
    int den;
public:
    Fraction(){
        this->num = 0;
        this->den = 0;
    }

    Fraction(Fraction const &fr){
        this->num = fr.num;
        this->den = fr.den;
    }

    Fraction(string * dr) {
        int znak = 1;
        int i = 0;
        int n = dr->length();
        char ch;
        int del = dr->find("/");
        int wh = 0;
        string num_s;
        string den_s;
        string wh_s = "0";
        if (dr->find("-") != string::npos){
            znak = -1;
            i = 1;
        }
        if (dr->find(" ") == string::npos){
            for (i; i<del; i++){
                num_s+=(*dr)[i]; // dr - pointer
            }
            for (int i = del+1; i<n; i++){
                den_s+=(*dr)[i];
            }
        }
        else {
            wh_s = "";
            int gap = dr->find(" ");
            for (i; i < gap; i++){
                wh_s +=(*dr)[i];
            }
            for (int i = gap+1; i<del; i++){
                num_s+=(*dr)[i]; // dr - pointer
            }
            for (int i = del+1; i<n; i++){
                den_s+=(*dr)[i];
            }
        }
        int den = stoi(den_s);
        wh = stoi(wh_s);
        int num = (stoi(num_s) + wh*den) * znak;
        this->num = num;
        this->den = den;
    }

    Fraction(int num, int den){
        this->num = num;
        this->den = den;
    }

    Fraction (double a){
        int i,count = 0;
        string dr = to_string(a);
        int p = dr.find(",");
        int n = dr.length();
        if (dr.find("-") != string::npos){
            i = 1;
        }
        for (i = p+1;i<n;i++){
            count +=1;
        }
        int den = pow(10,count);
        int num = a * den;

        this->num = num;
        this->den = den;
    }


    int setNum(int num){
        this->num = num;
        return 0;
    };

    int setDen(int den){
        this->den = den;
        return 0;
    };

    int getNum(){
        return this->num;
    }

    int getDen(){
        return this->den;
    }

    static string view(Fraction fr);
    static int gcd(int num, int den);

    friend Fraction operator+(const Fraction&,const Fraction&);
    friend Fraction operator+(const Fraction&,int);
    friend Fraction operator+(int,const Fraction&);
    friend Fraction operator+(const Fraction&, double a);
    friend Fraction operator+(double a,const Fraction&);


    Fraction operator+=(const Fraction& x) {
        int zn = this->den; // чтобы числитель правильно считался
        this->den = x.den * zn;
        this->num = x.num*zn+ this->num * x.den;
        return *this;
    }

    Fraction operator+=(int a) {
        this->num = a*this->den + this->num;
        return  *this;
    }

    Fraction operator+=(double a) {
        int N_DEC = 4;
        int n = pow(10,N_DEC);
        a = round(a*n)/n;
        Fraction y(a);
        int nod1 = Fraction::gcd(this->num,this->den);
        int x_del = this->num/nod1;
        int x_zn = this->den/nod1;
        int nod2 = Fraction::gcd(y.num,y.den);
        int y_del = y.num/nod2;
        int y_zn = y.den/nod2;
        this->den = x_zn* y_zn;
        this->num = x_del*y_zn + y_del * x_zn;
        return  *this;
    }

};



#endif
