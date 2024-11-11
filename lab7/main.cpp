#include <iostream>
#include <cstring>
#include "human/workers.h"

int main() {
    setlocale(LC_ALL, "Russian");
    Personnel::begin = nullptr;
    char *name1 = "aaa";
    int h1 = 6;
    int d1 = 7;
    char * name2 = "bbb";
    int h2 = 6;
    int s2 = 7;
    char * name3 = "ccc";
    int h3 = 10;
    int s3 = 9;
    int det3 = 1;
    Admin ad(name1,h1,d1);
    Worker wr(name2, h2,s2);
    Engineer en(name3, h3,s3,det3);
    en.add(&en);
    Personnel::print();
    delete[] Personnel::begin;
    return 0;
}
