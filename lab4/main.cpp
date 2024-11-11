#include <iostream>
#include <cstring>
#include "stack/stack.h"


void Multipliers(int n, MyStack<int> &stack) {
    int i = 2;
    while (i <= n) {
        if (n % i == 0) {
            n /= i;
            stack.push(i);
        } else {
            i++;
        }
    }
}


int main() {
    setlocale(LC_ALL, "Russian");

    MyStack<int> stack1;
    MyStack<int> stack2;
    int n;
    std::cin>>n;
    Multipliers(n,stack1);

    std::cout<<n<< " = ";
    while (!stack1.empty()) {
        std::cout << stack1.top_inf()<<" " ;
        stack2.push(stack1.top_inf());
        stack1.pop();
    }

    std::cout<<"\n"<<n<< " = ";
    while (!stack2.empty()) {
        std::cout << stack2.top_inf()<<" " ;
        stack2.pop();
    }

    std::cout<<"\n"<<n<< " = ";
    MyStack<int> stack3(stack2);
    while (!stack3.empty()) {
        std::cout << stack3.top_inf()<<" " ;
        stack3.pop();
    }
    return 0;
}
