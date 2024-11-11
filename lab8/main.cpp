#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <vector>
#include <list>
#include <map>
#include <iterator>

using namespace std;

void number_1(){
    string word_1, word_2, word_3;
    cin>>word_1;
    cin>> word_2;
    cin>> word_3;
    string res;
    res += word_1[0];
    res += word_2[0];
    res += word_3[0];
    cout <<res<<endl;
}

void number_2(){
    string txt;
    getline(cin, txt);
    int ind = txt.find(' ');
    string mes = txt.substr(ind+1,txt.find('.') - ind-1);
    cout<<mes<<endl;
}

void number_3(){
    string line;
    string digit = "0123456789";
    ifstream f1("111.txt");
    ofstream f2("C:\\Users\\dassa\\CLionProjects\\templates\\lab8\\222.txt");

    if ((f1.is_open()) and (f2.is_open())){
        while (getline(f1,line)){
            if (digit.find(line[0])!= string::npos){
                f2 <<line<<endl;
            }
        }
    }

    f1.close();
    f2.close();
}

void pr_v(vector<double> v){
    cout<<"v = ";
    for (int i = 0;i<v.size();i++ ){
        cout << v[i] << " ";
    }
    cout<<endl;
}

void number_4(){
    random_device rd; // Источник энтропии для seed
    mt19937 gen(rd()); // Инициализация генератора Mersenne Twister
    uniform_real_distribution<double> dis(-50.0, 50.0);
    vector<double> v1(10);
    vector<double> v2;
    double sum;
    for (int i = 0;i<10;i++){
         double a = dis(gen);
         v1[i] = a;
         sum+=a;
    }
    pr_v(v1);
    sum /= 10;
    for (int i = 0;i<10;i++){
       if (v1[i] > sum){
           v2.push_back(v1[i]);
       };
    }
    pr_v(v2);
    auto iter = v1.cbegin();
    v1.erase(iter + 7);
    pr_v(v1);
}

class Box {
    double a;  // ширина
    double b;  // высота
    double c;  // длина
public:
    Box() : a(0), b(0), c(0) {}
    Box(double a, double b, double c) : a(a), b(b), c(c) {}

    bool operator<(Box & box){
        double v1 = this->a*this->b*this->c;
        double v2 = box.a*box.b*box.c;
        return v1<v2;
    }

    bool operator==(Box & box){
        return ((this->a == box.a) and (this->b == box.b) and (this->a == box.b));
    }

    double geta(){
        return this->a;
    }

    double getb(){
        return this->b;
    }
    double getc(){
        return this->c;
    }
};

void pr_box(vector<Box> v){
    for (int i = 0;i<v.size();i++){
        cout << "Box: " << v[i].geta() << " x "<< v[i].getb()<<" x "<< v[i].getc()<< endl;
    }
}

void number_5(){
    vector<Box> v {Box(1, 2, 63), Box(14, 57, 19), Box(7, 32, 20), Box(5, 13, 23), Box(10, 19, 45), Box(19, 9, 59)};
    pr_box(v);
    int ind = -1;
    double max_v = -10;
    for (int i = 0; i<v.size();i++){
        if (v[i].geta()*v[i].getb()*v[i].getc()>max_v){
            ind = i;
        }
    }
    cout <<"max size: "<< v[ind].geta()<<" x "<< v[ind].getb()<<" x "<< v[ind].getc()<<endl;
}

void pr_list(list<double> l){
    cout<<"l = ";
    for (auto k = l.begin(); k != l.end(); k++) {
        cout << (*k) << " ";
    }
    cout<<endl;
}

void number_6(){
    random_device rd; // Источник энтропии для seed
    mt19937 gen(rd()); // Инициализация генератора Mersenne Twister
    uniform_real_distribution<double> dis(-50.0, 50.0);
    list<double> l1;
    list<double> l2;
    double sum;
    for (int i = 0;i<10;i++){
        double a = dis(gen);
        l1.push_back(a);
        sum+=a;
    }
    pr_list(l1);
    sum /= 10;
    int ind = 0;
    for (auto k = l1.begin(); k != l1.end(); k++) {
        ind++;
        if ((*k) > sum){
            l2.push_back(*k);
        }
        if (ind == 8){
            l1.erase(k);
        }

    }
    pr_list(l2);
    pr_list(l1);
}


class Graduate {
    string name;    // фамилия
    double rating;  // рейтинг
public:
    Graduate() {
        name = "";
        rating = 0;
    }
    Graduate(string Name, double Rating) {
        name = Name;
        rating = Rating;
    }

    bool operator<(Graduate & gr){
        return this->rating<gr.rating;
    }

    bool operator==(Graduate & gr){
        return ((this->name == gr.name) and (this->rating == gr.rating));
    }
    string getn(){
        return this->name;
    }

    double getr(){
        return this->rating;
    }

    void setr(double a){
        this->rating = a;
    }

};

void pr_gr(list<Graduate> gr){
    for (auto k = gr.begin();k!=gr.end();k++){
        cout << "Graduate: " << (*k).getn() << " "<< (*k).getr()<< endl;
    }
}

void number_7(){
    list<Graduate> l {Graduate("Иванов", 99), Graduate("Петров", 430), Graduate("Семенов", 70), Graduate("Котов", 540), Graduate("Белых",230), Graduate("Черных", 350)};
    pr_gr(l);
    double max_r = -1000;
    Graduate t;
    for (auto k = l.begin();k!=l.end();k++){
        if (t<(*k)){
            t = *k;
        }
    }
    cout << "max: "<< t.getn()<<" "<< t.getr()<<endl;
    double n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    for (auto k = l.begin();k!=l.end();k++){
        (*k).setr((*k).getr()+n);
    }
    pr_gr(l);

}

void number_8(){
    map<string,string> m {{"russia","moscow"}, {"italy","roma"},{"germany","berlin"},{"usa","vashington"},{"japan","tokyo"}};
    string str;
    string stol;
    cout<<"enter the country"<<endl;
    cin>>str;
    bool flag = false;
    for (auto i = m.begin(); i != m.end(); i++) {
        if (str == i->first){
            cout << i->second << endl;
            flag = true;
        }
    }
    if (not(flag)){
        cout<<"enter the capital"<<endl;
        cin >> stol;
        m[str] = stol;
    }
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->first << " -> " << i->second << endl;
    }
}


void pr_m(map<string,int> m){
    for (auto i = m.begin(); i != m.end(); i++) {
        cout<<"name: "<< i->first << " details: "<< i->second << endl;
    }
}

void number_9(){
    map<string,int> m {{"Иванов",123}, {"Петров", 89}, {"Сидоров", 108}, {"Краснов", 132}, {"Демин", 99}, {"Черепанов", 111}};
    int sum = 0;
    for (auto i = m.begin(); i != m.end(); i++) {
        sum+=i->second;
    }
    cout << "sum : "<< sum<<endl;
    pr_m(m);
}


int main() {
    setlocale(LC_ALL, "Russian");
    number_1();
    number_2();
    number_3();
    number_4();
    number_5();
    number_6();
    number_7();
    number_8();
    number_9();
    return 0;
}
