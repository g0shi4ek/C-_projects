#ifndef LAB2_DOM_H
#define LAB2_DOM_H

namespace dm{
    class Dom {
        char * name_;
        int len;
        int life;
        int fl;
    public:
        Dom &operator=(const Dom& some){
            this->name_ = some.name_;
            this->len = some.len;
            this->life = some.life;
            this->fl = some.fl;
            return *this;
        }

        bool operator>(const Dom& some) {
            if (strcmp(this->name_, some.name_) > 0) {
                return true;
            }
            return false;
        }

        Dom(const char* name, int len, int life, int fl) { // конструктор
            name_  = new char[strlen(name) + 1];
            strcpy(name_, name);
            this->name_ = setName(name_);
            this->len = setLen(len);
            this->life = setLife(life);
            this->fl = setFl(fl);
        }


        Dom () { // конструктор
            const char* a = "undefined";
            this->name_ = new char[strlen(a)+1];
            strcpy(this->name_, a);
            this->len = 0;
            this->life = 0;
            this->fl = 0;
            std::cout << "create ID" << std::endl;
        }
        ~Dom(){
            delete[] name_;
            name_ = nullptr;
            std::cout << "delete ID" << std::endl;
        }
        char* getName(){
            char* name = new char[strlen(this->name_) + 1];
            strcpy(name, this->name_);
            return name;
        }

        char * setName(char* name){
            this->name_ = name;
            return 0;
        }

        int getLen() {
            return this->len;
        }
        int setLen(int len){
            this->len = len;
            return 0;
        }

        int getLife(){
            return this->life;
        }
        int setLife(int life){
            this->life = life;
            return 0;
        }

        int getFl(){
            return this->fl;
        }
        int setFl(int fl){
            this->fl = fl;
            return 0;
        }


        static void read_db(char * filename, Dom **  arr, int &n);
        static void print_db(Dom *arr, int n);
        static void add_db(Dom **arr, int&n);
        static int write_db(char *filename, Dom * arr, int n);
        static int find_ind(Dom *arr, int n);
        static void del_db(Dom **arr, int& n);
        static void edit_db(Dom **arr, int n);
        static void sort_db(Dom **arr, int n);

    };

}
#endif //LAB2_DOM_H
