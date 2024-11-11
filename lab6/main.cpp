#include <iostream>
#include <cstring>
#include "uravn/term.h"
#include "uravn/polynom.h"
#include <vector>

using namespace std;

std::istream& operator>>(std::istream& in, Polynom& p)
{
    char* a = new char[10];
    int n = 10;
    int len = 0;
    vector<int> zn;
    char c;


    while (in.get(c) && c != '\n') {
        if (c!= ' ') {
            if (len == n - 1) {
                n *= 2; // Удваиваем размер
                char *new_a = new char[n];
                memcpy(new_a, a, len);
                delete[] a;
                a = new_a;
            }

            a[len] = c;
            len++;
        }
    }
    a[len] = '\0';
    for (int i = 0;i<len;i++){
        if (a[i] == '-'){
            zn.push_back(i);
        }
        if (a[i] == '+'){
            zn.push_back(i);
        }
    }
    zn.push_back(len);

    int j = 0;
    if (zn[0] == 0){
        j = 1;
    }
    int k = 0;
    for (j; j < zn.size(); j++) {
        char* token = new char[zn[j] -k  + 1];
        int ind = 0;
        for (k; k < zn[j]; k++) {
            token[ind] = a[k];
            ind++;
        }
        token[ind] = '\0';

        Term t(token);
        p.add_t(t);

        delete[] token;
    }
    return in;
}



std::ostream &operator<<(std::ostream &out, Polynom &p){
    p.sort_p();
    int flag = 0;
    if ((p.poly[0]).getCoef()!= 0){
        out<<p.poly[0];
        flag = 1;
    }

    for (int i = 1;i<p.getn();i++){
        if ((p.poly[i]).getCoef()!= 0) {
            if (((p.poly[i]).getCoef() > 0)  and (flag != 0)){
                out << "+" << p.poly[i];
            } else {
                out << p.poly[i];
            }
        }
    }

    return out;
}

std::istream &operator>>(std::istream &in, Term&t){
    int c = 0;
    int d = 0;
    in>>c>>d;
    t.setCoef(c);
    t.setDegr(d);
    return in;
}

std::ostream &operator<<(std::ostream &out, Term &t) {
    if (((t.coef != 1) and (t.coef != -1)) or (t.degr== 0)) {
        out << t.coef;
    }
    if ((t.coef == -1) and t.degr>0 ){
        out << "-";
    }
    if (t.degr >= 1){
        out<<"x";
    }
    if (t.degr > 1) {
        out << "^" << t.degr;
    }
    return out;
}




int main()
{
    setlocale(LC_ALL, "Russian");
    Polynom polyn1;
    cin >> polyn1;
    cout << polyn1<<endl;
    Polynom polyn2;
    cin >> polyn2;
    cout << polyn2<<endl;
    polyn1*=polyn2;
    cout<<polyn1<<endl;
    polyn2+=polyn1;
    cout<<polyn2<<endl;
    Polynom polyn4 = polyn1 * polyn2;
    cout << polyn4<<endl;
    Polynom polyn3 = polyn1 + polyn2;
    cout << polyn3<<endl;
    return 0;
}

