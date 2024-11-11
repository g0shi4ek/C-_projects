#include "workers.h"

Personnel ** Personnel::begin = nullptr;
int Personnel::n = 0;

void Personnel::add(Personnel* el){
    Personnel ** temp = new Personnel * [Personnel::n+1];
    for (int i = 0; i < Personnel::n; i++){
        temp[i] = Personnel::begin[i];
    }
    temp[Personnel::n] = el;
    delete[] Personnel::begin; // Освобождение памяти
    Personnel::n++;
    Personnel::begin = temp;
}

void Personnel::print() {
    for (int i = 0; i < Personnel::n; i++) {
        Personnel::begin[i]->show();
    }
}


Personnel::~Personnel() {delete[] name;};
