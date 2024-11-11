#ifndef LAB6_POLYNOM_H
#define LAB6_POLYNOM_H
#include <iostream>
#include "term.h"

class Polynom {
private:
    friend class Term;
    Term * poly;
    int degree;
    int n;
public:
    Polynom(): poly(nullptr), degree(0), n(0){}
    Polynom(int coef):  degree(0), n(1) {
        Term ** temp = new Term*[1];
        temp[0] = new Term(coef,0);
    }
    Polynom(Term t): degree(t.getDegr()), n(1) {

        Term ** temp = new Term*[1];
        temp[0] = new Term(t.getCoef(),t.getDegr());
    }
    Polynom(Polynom &p){
        this->n = p.n;
        this->degree = p.degree;
        Term * temp = new Term[this->n];
        for (int i = 0; i < this->n; i++) {
            temp[i] = p.poly[i];
        }
        this->poly = temp;
    }

    void add_t(Term & t){
        bool added = false;
        for (int i = 0; i < this->n; i++){
            if (t.getDegr() == this->poly[i].degr){
                this->poly[i] = this->poly[i] + t;
                added = true;
                break;
            }
        }
        if (!added){
            Term * temp = new Term[this->n+1];
            for (int i = 0; i < this->n; i++){
                temp[i] = this->poly[i];
            }
            temp[this->n] = t;
            delete[] this->poly; // Освобождение памяти
            this->n++;
            this->poly = temp;
        }
    }

    void sort_p(){
        bool flag = true;
        while (flag){
            flag = false;
            for (int i = 0;i<this->n-1;i++){
                if ((this->poly[i].getDegr()) < (this->poly[i + 1].getDegr())) {
                    Term temp = this->poly[i];
                    this->poly[i] = this->poly[i + 1];
                    this->poly[i + 1] = temp;
                    flag = true;
                }
            }
        }
    }

    void setn(int n){
        this->n = n;
    };

    void setDegree(int degree){
        this->degree = degree;
    };

    int getn(){
        return this->n;
    }

    int getDegree(){
        return this->degree;
    }


    Polynom& operator+=(Polynom& p){
        for (int i = 0;i<p.n;i++){
            this->add_t(p.poly[i]);
        }
        return *this;
    }

    Polynom& operator*=(Polynom& p){
        Polynom * res = new Polynom;
        for (int i = 0;i<this->n;i++) {
            for (int j = 0; j < p.n; j++) {
                int c = (this->poly[i]).coef * (p.poly[j]).coef;
                int d = (this->poly[i]).degr + (p.poly[j]).degr;
                Term *el = new Term(c, d);
                res->add_t(*el);
            }
        }
        *this = *res;
        return *this;
    }

    friend Polynom& operator+( Polynom& p1, const Polynom& p2){
        Polynom * res;
        res = &p1;
        for (int i = 0;i<p2.n;i++){
            res->add_t(p2.poly[i]);
        }
        return *res;
    }

    friend Polynom& operator*( Polynom& p1, const Polynom& p2){
        Polynom * res = new Polynom;
        for (int i = 0;i<p1.n;i++) {
            for (int j = 0; j < p2.n; j++) {
                int c = (p1.poly[i]).coef * (p2.poly[j]).coef;
                int d = (p1.poly[i]).degr + (p2.poly[j]).degr;
                Term *el = new Term(c, d);
                res->add_t(*el);
            }
        }
        return *res;
    }

    friend std::istream& operator>>(std::istream& in, Polynom& p);
    friend std::ostream &operator<<(std::ostream &out, Polynom& p);

};


#endif //LAB6_POLYNOM_H
