//
// Created by salvatore on 04/07/18.
//

#ifndef FILEDIRECTORY_DIRECTORY_H
#define FILEDIRECTORY_DIRECTORY_H


#include <string>
#include "Data.h"
#include "File.h"
#include <list>

class Directory {

private:

    std::string name;
    Data dataModificaDir;
    Data dataUltimoAccDir;

    std::list<File*> files;
    std::list<Directory*> dir;

public:

    Directory(const Directory& obj){
        copy(obj);
    }

private: void copy(const Directory& obj){
        name=obj.name;
        dataModificaDir=obj.dataModificaDir;
        dataUltimoAccDir=obj.dataUltimoAccDir;
        files=obj.files;
        dir=obj.dir;
    }

public:
    Directory operator=(const Directory& dr){
        if(this != &dr) {
            copy(dr);
        }
        return *this;
    }

    Directory(std::string name, int day, int month, int year, int ora, int min, int sec){
        this->name = name;

        Data dataCreazioneDir;
        dataCreazioneDir.setDay(day);
        dataCreazioneDir.setMonth(month);
        dataCreazioneDir.setYear(year);
        dataCreazioneDir.setOra(ora);
        dataCreazioneDir.setMin(min);
        dataCreazioneDir.setSec(sec);

        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "*** Nuova directory creata ***" << std::endl;
        std::cout << std::endl;
        std::cout << "Directory name: " << this->name << std::endl;
        std::cout << "Data creazione: " << dataCreazioneDir.getDay() << "/" << dataCreazioneDir.getMonth() << "/"
                  << dataCreazioneDir.getYear() << std::endl;
        std::cout << "Ora creazione: " << dataCreazioneDir.getOra() << ":" << dataCreazioneDir.getMin() << ":"
                  << dataCreazioneDir.getSec() << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }


    void modUltimoAccesso(int day, int month, int year, int ora, int min, int sec) {
        dataUltimoAccDir.setDay(day);
        dataUltimoAccDir.setMonth(month);
        dataUltimoAccDir.setYear(year);
        dataUltimoAccDir.setOra(ora);
        dataUltimoAccDir.setMin(min);
        dataUltimoAccDir.setSec(sec);
    }


    void modUltimaModifica(int day, int month, int year, int ora, int min, int sec) {
        dataModificaDir.setDay(day);
        dataModificaDir.setMonth(month);
        dataModificaDir.setYear(year);
        dataModificaDir.setOra(ora);
        dataModificaDir.setMin(min);
        dataModificaDir.setSec(sec);
    }


    void printUltimoAccesso() {
        std::cout << std::endl;
        std::cout << "ULTIMO ACCESSO DIRECTORY " << this->name << std::endl;
        std::cout << "Data ultimo accesso: " << dataUltimoAccDir.getDay() << "/" << dataUltimoAccDir.getMonth() << "/"
                  << dataUltimoAccDir.getYear() << std::endl;
        std::cout << "Ora ultimo accesso: " << dataUltimoAccDir.getOra() << ":" << dataUltimoAccDir.getMin() << ":"
                  << dataUltimoAccDir.getSec() << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void printUltimaModifica() {
        std::cout << std::endl;
        std::cout << "ULTIMA MODIFICA DIRECTORY " << this->name << std::endl;
        std::cout << "Data ultima modifica: " << dataModificaDir.getDay() << "/" << dataModificaDir.getMonth() << "/"
                  << dataModificaDir.getYear() << std::endl;
        std::cout << "Ora ultima modifica: " << dataModificaDir.getOra() << ":" << dataModificaDir.getMin() << ":"
                  << dataModificaDir.getSec() << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void addFile(File* f){
        files.push_back(f);
    }

    void removeFile(File* f){
        files.remove(f);
    }

    void addDirectory(Directory* d){
        dir.push_back(d);
    }

    void removeDirectory(Directory* d){
        dir.remove(d);
    }


    void printListFile(){
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Lista file: " << std::endl;
        for(auto itr:files){
            itr->display();
        }
    }

    void printListDirectory(){
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Lista directory: " << std::endl;
        for(auto itr:dir){
            itr->display();
        }
    }

    void display(){
        std::cout << "     -" << name <<  std::endl;
    }

};


#endif //FILEDIRECTORY_DIRECTORY_H
