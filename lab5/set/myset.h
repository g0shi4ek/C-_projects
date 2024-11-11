#ifndef LAB5_MYSET_H
#define LAB5_MYSET_H


#include "myvector.h"
template<typename  T>
class MySet : public MyVector<T> {
public:
    MySet() : MyVector<T>(){};

    MySet(T *el, int max_size1 = MAX_SIZE) : MyVector<T>(el,MAX_SIZE){};

    bool operator==(MySet &s){
        if (this->size == s.size){
            bool flag = true;
            for (int i = 0; i<this->size; i++){
                if (*(this->pdata[i]) != *s.pdata[i]){
                    flag = false;
                }
            }
            if (flag){
                return true;
            }
        }
        return false;
    };


    MySet &operator+=(MySet &s){
        for (int i = 0; i < s.size; i++) {
            this->add_element_s(s.pdata[i]);
        }
        return *this;
    };

    MySet &operator-=(MySet &s){
        for (int i = 0;i < s.size; i++){
            this->delete_element_s(s.pdata[i]);
        }
        return *this;
    };

    MySet &operator*=(MySet &s){
        for (int i = 0;i < s.size; i++){
            if (not(s.is_element(this->pdata[i]))){
                cout<<*this->pdata[i]<<endl;
                this->delete_element_s(this->pdata[i]);
            };
        }
        return *this;
    };

    void add_element_s(T *el){
        if (this->size != 0){
            if (this->find(el)== -1)  {
                this->add_element(el);
            }
        }
        else{
            this->add_element(el);
        }
    };


    void delete_element_s(T *el){
        if (this->find(el)!= -1) {
            int i = this->find(el);
            this->delete_element(i);
        }
    };

    bool is_element(T *el){
        if (this->find(el)!= -1) {
            return true;
        }
        else{
            return false;
        }
    };

    MySet& operator=(MySet &s){
        this->size = s.size;
        this->max_size = s.max_size ;
        T ** temp = new T*[this->max_size];
        for (int i = 0; i < this->size; i++) {
            temp[i] = s.pdata[i];
        }
        this->pdata = temp;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, MySet &s);

    friend MySet operator+(MySet &s1, MySet &s2){
        MySet<T> sn;
        for (int i = 0; i<s1.size; i++){
            sn.add_element_s(s1.pdata[i]);
        }
        for (int i = 0; i<s2.size; i++){
            sn.add_element_s(s2.pdata[i]);
        }
        return sn;
    };

    friend MySet operator-(MySet &s1, MySet &s2){
        MySet<T> sn;
        for (int i = 0; i<s1.size; i++){
            if (not(s2.is_element(s1.pdata[i]))) {
                sn.add_element_s(s1.pdata[i]);
            }
        }
        return sn;
    };

    friend MySet operator*(MySet &s1, MySet &s2){
        MySet<T> sn;
        for (int i = 0; i<s1.size; i++){
            if (s2.is_element(s1.pdata[i])) {
                sn.add_element_s(s1.pdata[i]);
            }
        }
        return sn;
    };
};

template<>
void MySet<char*>::add_element_s(char **el) {
    if (this->size != 0){
        if (this->find(el)== -1)  {
            this->add_element(el);
        }
    }
    else{
        this->add_element(el);
    }
};

template<>
void MySet<char*>::delete_element_s(char **el) {
    if (this->find(el)!= -1) {
        int i = this->find(el);
        this->delete_element(i);
    }
};

template<>
bool MySet<char*>::is_element(char **el) {
    if (this->find(el)!= -1) {
        return true;
    }
    else{
        return false;
    }
};

template<>
bool MySet<char*>::operator==(MySet<char *> &s) {
    if (this->size == s.size){
        bool flag = true;
        for (int i = 0; i<this->size; i++){
            if (strcmp(*(this->pdata[i]), *s.pdata[i])!=0){
                flag = false;
            }
        }
        if (flag){
            return true;
        }
    }
    return false;
}
#endif //LAB5_MYSET_H
