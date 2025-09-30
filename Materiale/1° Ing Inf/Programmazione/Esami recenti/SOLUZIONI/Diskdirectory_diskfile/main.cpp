#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Disksdirectory {
private:

    string name;
    map<string, Disksdirectory *> directory;
public:
    virtual ~Disksdirectory() {}


    Disksdirectory(const string name) : name(name) {};

    map<string, Disksdirectory *>::iterator findDirectory(const string &_nome) {
        auto itr = directory.find(_nome);
        return itr;
    }

    virtual void print() {
        for (auto itr = directory.begin(); itr != directory.end(); ++itr) {
            itr->second->print_info();

        }

    }


    void add_directory(string nome, Disksdirectory *d) {

        directory.insert(make_pair(nome, d));

    }

    void remove_directory(string nome) {
        auto it = findDirectory(nome);
        directory.erase(it);
    }

    virtual void list() {
        cout << "LISTA FILE E CARTELLE:" << endl;
        for (auto itr = directory.begin(); itr != directory.end(); ++itr) {
            cout << itr->first;
            cout << endl;

        }

    }

    virtual string nome() {
        return name;

    }

    virtual void print_info() {
        cout << endl << "CARTELLE:" << endl;
        cout << name << endl;


    }

};

class Diskfile : public Disksdirectory {
private:
    string nome;
    int dim;
    bool scrivibile;
public:
    virtual ~Diskfile() {}

    Diskfile(const string &nom, int dim, bool scrivibile = 0) : Disksdirectory(nom), nome(nom), dim(dim),
                                                                scrivibile(scrivibile) {}


    virtual void print_info() override {

        cout << endl << "FILE:" << endl;
        cout << nome << endl;
        cout << "è di dimensione: " << dim << " mega" << endl;
        if (scrivibile) {
            cout << "Il file e' scrivibile";
        } else
            cout << "il file non è scrivibile";
        cout << endl;
    }


    string get_nome() {
        return nome;
    }


};


int main() {
    Disksdirectory D("Directory");

    Disksdirectory F("Directory_1");
    Diskfile C("FILE_1", 2);
    Diskfile R("FIle_2", 3, 1);
    D.add_directory(F.nome(), &F);
    D.add_directory(C.get_nome(), &C);
    D.add_directory(R.get_nome(), &R);
    D.list();
    D.print();
    D.remove_directory("FILE_1");
    cout << endl;
    D.list();
    Disksdirectory D_2("Directory_2");
    D_2.add_directory(C.get_nome(), &C);
    cout << endl;
    D_2.list();

}