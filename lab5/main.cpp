#include <iostream>
#include <cstring>
#include "set/myvector.h"
#include "set/myset.h"

using namespace std;


ostream &operator<<(ostream &out, MySet<int> &s){
    out<<"{";
    for (int i = 0; i < s.size; i++){
        out << *(s.pdata[i])<< " ";
    }
    out<<"}"<<endl;
    return out;
}


ostream &operator<<(ostream &out, MySet<char*> &s){
    out<<"{";
    for (int i = 0; i < s.size; i++){

        out << *(s.pdata[i])<<" ";
    }
    out<<"}"<<endl;
    return out;
}

ostream &operator<<(ostream &out, MyVector<int> &v){
    out<<"{";
    for (int i = 0; i < v.size; i++){
        out << *(v.pdata[i])<<" ";

    }
    out<<"}"<<endl;
    return out;
}

ostream &operator<<(ostream &out, MyVector<char*> &v){
    out<<"{";
    for (int i = 0; i < v.size; i++){
        out << *(v.pdata[i])<<" ";
    }
    out <<"}"<<endl;
    return out;
}


int main() {
    setlocale(LC_ALL, "Russian");
    char*mes1= "Hello!";
    char* mes2 = "Privet!";
    /*MyVector<char*> v(&mes1);
    v.add_element(&mes2);
    v.add_element(&mes2);
    v.add_element(&mes2);
    v.add_element(&mes2);
    v.add_element(&mes2);
    std::cout << "vector v: " << v << std::endl;
    v.add_element(&mes2);
    v.add_element(&mes2);
    v.add_element(&mes2);
    std::cout << "vector v: " << v << std::endl;
    MyVector v1 = v;
    std::cout << "vector v1: " << v1 << std::endl;
    for (int i = 0; i < MAX_SIZE; i++)
        v1.delete_element(0);
    std::cout << "vector1 v1: " << v1 << std::endl;*/
    char*mes3 = "Yes";
    char * mes4 = "No";
    char*mes5 = "Cat";
    MySet<char*> s(&mes3), s1;
    s.add_element_s(&mes2);
    s.add_element_s(&mes4);
    s.add_element_s(&mes1);
    std::cout << "set s: " << s << std::endl;
    s1.add_element_s(&mes5);
    s1.add_element_s(&mes4);
    s1.add_element_s(&mes2);
    std::cout << "set1 s1: " << s1 << std::endl;
    MySet<char*> s2 = s1 - s;
    std::cout << "set2 s2=s1-s: " << s2 << std::endl;
    std::cout << "set1 s1: " << s1 << std::endl;
    std::cout << "set2 s: " << s << std::endl;
    MySet<char*> s3 = s - s1;
    std::cout << "set3 s3=s-s1: " << s3 << std::endl;
    std::cout << "set1 s1: " << s1 << std::endl;
    std::cout << "set s: " << s << std::endl;
    MySet<char*> s4 = s1 + s;
    std::cout << "set4 s4=s1+s: " << s4 << std::endl;
    std::cout << "set1 s1: " << s1 << std::endl;
    std::cout << "set s: " << s << std::endl;
    MySet<char*> s5 = s1 * s;
    std::cout << "set5 s5=s1*s: " << s5 << std::endl;
    std::cout << "set1 s1: " << s1 << std::endl;
    std::cout << "set s: " << s << std::endl;
    MySet<char*> s6 = s2;
    std::cout << "set6 s6=s2: " << s6 << std::endl;
    if (s3 == s2)
        std::cout << "s3=s2\n";
    else
        std::cout << "s3!=s2\n";
    if (s3 == s1)
        std::cout << "s3=s1\n";
    else
        std::cout << "s3!=s1\n";
    if (s1 == s3)
        std::cout << "s1=s3\n";
    else
        std::cout << "s1!=s3\n";
    if (s6 == s2)
        std::cout << "s6=s2\n";
    else
        std::cout << "s6!=s2\n";
    return 0;

    /*MyVector<int> v;
    int a = 5;
    v.add_element(&a);
    cout << v << endl;
    int a1 = 3;
    v.add_element(&a1);
    cout << v << endl;
    int a2 = 2;
    v.add_element(&a2);
    cout << v << endl;

    MySet<char*> s;
    char * t = "asd";
    s.add_element_s(&t);
    char * t1 = "abb";
    s.add_element_s(&t1);
    cout<<s<<endl;

    MySet<char*> s1;
    char * t2 = "asd";
    s1.add_element_s(&t2);
    char * t3 = "bl";
    s1.add_element_s(&t3);
    cout<<s1<<endl;

    if (s == s1){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
    int s1 = 1;
    s.add_element_s(&s1);
    int s2 = 4;
    s.add_element_s(&s2);
    int s3 = 5;
    s.add_element_s(&s3);
    int s4 = 6;
    s.add_element_s(&s4);
    cout << s<<endl;

    MySet<int> sn;
    int s5 = 1;
    sn.add_element_s(&s5);
    int s6 = 2;
    sn.add_element_s(&s6);
    int s7 = 3;
    sn.add_element_s(&s7);
    int s8 = 4;
    sn.add_element_s(&s8);
    cout << sn <<endl;

    MySet<int> st = s+sn;
    cout<< st << endl;

    MySet<int> st1 = s-sn;
    cout<< st1 << endl;

    MySet<int> st2 = s*sn;
    cout<< st2 << endl;

    //s*=sn;
    //cout<<s<<endl;
    //s-=sn;
    //cout<<s<<endl;
    //s+=sn;
    //cout<<s<<endl;

    if (s == sn){
        cout<<"1"<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
    //s.delete_element_s(&s2);
    //cout << s <<endl;

    //bool res = s.is_element(&s1);
    //cout<<res<<endl;
    //v.delete_element(2);
    //cout << v << endl;
    //int b = v.find(&a1);
    //cout<<b<<endl;
    //print_debug(v);
    //MyVector<int> v1;
    //v1 = v;
    //cout <<v1[0] << endl;
    //cout << v1 << endl;
    //MyVector<int> v2(v1);
    //cout << v2 << endl;
*/
    return 0;

}
