#ifndef LAB5_MYVECTOR_H
#define LAB5_MYVECTOR_H

#include <iostream>
#include <typeinfo>
#include <string.h>

//#define MAX_SIZE 5

using namespace std;

const int MAX_SIZE = 5;

template<typename T>
class MyVector {
protected:
    int max_size;
    int size;

    T ** pdata;
public:
    MyVector() : size(0), max_size(MAX_SIZE), pdata(nullptr) {
    }

    MyVector(T *el, int max_size1 = MAX_SIZE) {
        size = 1;
        max_size = max_size1;
        pdata = new T *[max_size]{el};
    };

    MyVector(MyVector &v){
        size = v.size;
        max_size = v.max_size;
        T ** temp = new T*[max_size];
        for (int i = 0; i < size; i++) {
            temp[i] = v.pdata[i];
        }
        pdata = temp;
    };

    ~MyVector() {
        if (this->pdata != nullptr) {
            delete[] this->pdata;
        }
    }

    void resize(int old_size) {
        if (this->size >= this->max_size) {
            this->max_size *= 2;
        } else if (this->size <= this->max_size / 4) {
            this->max_size /= 2;
        }
        T **temp = new T *[this->max_size];
        for (int i = 0; i < old_size; i++) {
            temp[i] = this->pdata[i];
        }
        if (this->pdata != nullptr) {
            delete[] this->pdata;
        }
        this->pdata = temp;
    };

    void add_element(T *el) {
        this->resize(this->size++);
        this->pdata[this->size - 1] = el;
        this->sort();
    };

    bool delete_element(int i){
        if (i >= this->size) {
            return false;
        }
        for (int j=i; j < this->size-1; j++) {
            this->pdata[j] = this->pdata[j + 1];
        }
        this->resize(this->size--);
        return true;

    };


    void sort(){
        bool flag = true;
        while (flag){
            flag = false;
            for (int i = 0;i<this->size-1;i++){
                if ((*this->pdata[i]) > (*this->pdata[i + 1])) {
                    T *temp = this->pdata[i];
                    this->pdata[i] = this->pdata[i + 1];
                    this->pdata[i + 1] = temp;
                    flag = true;
                }
            }
        }
    };


    int find(T * el){
        int low = 0;
        int high = this->size - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (*this->pdata[mid] == *el) {
                return mid;
            }
            else if (*this->pdata[mid] < *el) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    };

    int get_size() { return size; }

    int get_max_size() { return max_size; }

    T operator[](int i){
        return *this->pdata[i];
    };

    MyVector& operator=(MyVector &v){
        this->size = v.size;
        this->max_size = v.max_size ;
        T ** temp = new T*[max_size];
        for (int i = 0; i < this->size; i++) {
            temp[i] = v.pdata[i];
        }
        this->pdata = temp;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, MyVector &v);

};
template <>
void MyVector<char*>::sort() {
    bool flag = true;
    while (flag){
        flag = false;
        for (int i = 0;i<this->size-1;i++){
            if (strcmp((*this->pdata[i]), (*this->pdata[i + 1]))>0) {
                char **temp = this->pdata[i];
                this->pdata[i] = this->pdata[i + 1];
                this->pdata[i + 1] = temp;
                flag = true;
            }
        }
    }
}

template <>
int MyVector<char*>::find(char ** el) {
    int low = 0;
    int high = this->size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (strcmp(*this->pdata[mid], *el) ==0) {
            return mid;
        }
        else if (strcmp(*this->pdata[mid], *el)<0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}


#endif //LAB5_MYVECTOR_H
