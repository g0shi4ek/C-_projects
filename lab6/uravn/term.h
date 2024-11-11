#ifndef LAB6_TERM_H
#define LAB6_TERM_H
#include <iostream>
#include <string.h>

class Polynom;

using namespace std;

class Term {
private:
    int coef;
    int degr;
    friend class Polynom;
public:
    Term(){
        this->coef = 0;
        this->degr = 0;
    }
    Term(int coef_ , int degr_ ){
        this->coef = coef_;
        this->degr = degr_;
    }

    Term(char* str){
        int ind_x = -1;
        int ind_d = -1;
        for (int i = 0; i< strlen(str); i++){
            if (str[i] == 'x'){
                ind_x = i;
            }
            if (str[i] == '^'){
                ind_d = i;

            }
        }
        char * c = new char[ind_x+1];
        char * d = new char[strlen(str) - ind_d+1];
        if (ind_x != -1){
            for (int i = 0; i<ind_x; i++){
                c[i] = str[i];
            }
            c[ind_x] = '\0';
            this->coef = atoi(c);
            if ((ind_x == 0) or (ind_x == 1 and (str[0] == '+' or str[0] == '-'))){
                this->coef = 1;
                if (str[0] == '-'){
                    this->coef = -1;
                }
                if (str[0] == '+'){
                    this->coef = 1;
                }

            }
            if (ind_d != -1){
                int ind = 0;
                for (int j = ind_d+1;j<strlen(str);j++){
                    d[ind]=str[j];
                    ind++;
                }
                d[ind] = '\0';
                this->degr = atoi(d);
            }
            else{
                this->degr = 1;
            }
        }
        else{
            this->coef = atoi(str);
            this->degr= 0;
        }
    }

    void setCoef(int coef){
        this->coef = coef;
    };

    void setDegr(int degr){
        this->degr = degr;
    };

    int getCoef(){
        return this->coef;
    }

    int getDegr(){
        return this->degr;
    }

    Term &operator=(Term& t)= default;


    friend Term& operator+(const Term& t1, const Term& t2) {
        if (t1.degr == t2.degr) {
            Term* res = new Term(t1.coef + t2.coef, t1.degr);
            return *res;
        } else {
            std::cout << "Error" << std::endl;
        }
    }


    friend std::istream& operator >> (std::istream& in, Term& t);
    friend std::ostream &operator<<(std::ostream &out, Term &t);

};


#endif //LAB6_TERM_H
