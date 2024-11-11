#include <iostream>
#include "mymath/mymath.h"
#include "mymath2/mymath2.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout <<  "zaceni 1+1=";
    std::cout << mymath::sum(1, 1) << std::endl;
    std::cout << "zaceni 6:2=";
    std::cout << mymath2::del(6, 2) << std::endl;
    return 0;
}
