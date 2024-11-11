#ifndef LAB2_PLANETA_H
#define LAB2_PLANETA_H

namespace pl{
    class Planet {
        char * name_;
        int diam;
        int life;
        int sput;
    public:

        bool operator==(const Planet& some){
            return (strcmp(this->name_, some.name_)==0);

        }

        Planet &operator=(const Planet& some){
            this->name_ = some.name_;
            this->diam = some.diam;
            this->life = some.life;
            this->sput = some.sput;
            return *this;
        }

        int operator>(const Planet& some) {
            return (strcmp(this->name_, some.name_));
        }


        Planet (const char* name, int diam, int life, int sput) { // конструктор
            name_  = new char[strlen(name) + 1];
            strcpy(name_, name);
            this->name_ = setName(name_);
            this->diam = setDiam(diam);
            this->life = setLife(life);
            this->sput = setSput(sput);
            }


        Planet () { // конструктор
            const char* a = "undefined";
            this->name_ = new char[strlen(a)+1];
            strcpy(this->name_, a);
            this->diam = 0;
            this->life = 0;
            this->sput = 0;
            std::cout << "create ID" << std::endl;
        }
        ~Planet(){
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

        int getDiam() {
            return this->diam;
        }
        int setDiam(int diam){
            this->diam = diam;
            return 0;
        }

        int getLife(){
            return this->life;
        }
        int setLife(int life){
            this->life = life;
            return 0;
        }

        int getSput(){
            return this->sput;
        }
        int setSput(int sput){
            this->sput = sput;
            return 0;
        }

        static void read_db(char * filename, Planet **  arr, int &n);
        static void print_db(Planet *arr, int n);
        static void add_db(Planet **arr, int&n);
        static int write_db(char *filename, Planet * arr, int n);
        static int find_ind(Planet *arr, int n);
        static void del_db(Planet **arr, int& n);
        static void edit_db(Planet **arr, int n);
        static void sort_db(Planet **arr, int n);

    };

}
#endif //LAB2_PLANETA_H
