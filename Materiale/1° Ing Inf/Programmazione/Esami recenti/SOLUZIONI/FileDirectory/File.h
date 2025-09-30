//
// Created by salvatore on 04/07/18.
//

#ifndef FILEDIRECTORY_FILE_H
#define FILEDIRECTORY_FILE_H


#include <string>
#include <iostream>
#include "Data.h"

class File {


private:

    std::string name;
    std::string estensione;
    Data dataUltimoAccesso;
    Data dataModifica;

public:

    File(const File& fl){
        copy(fl);
    }

    void copy(const File& fl){
        name=fl.name;
        estensione=fl.estensione;
        dataUltimoAccesso=fl.dataUltimoAccesso;
        dataModifica=fl.dataModifica;
    }

    File operator=(const File& fl){
        copy(fl);
    }



    File(std::string name, std::string est, int day, int month, int year, int ora, int min, int sec) {
        this->name = name;
        this->estensione = est;

        Data dataCreazione;
        dataCreazione.setDay(day);
        dataCreazione.setMonth(month);
        dataCreazione.setYear(year);
        dataCreazione.setOra(ora);
        dataCreazione.setMin(min);
        dataCreazione.setSec(sec);


        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "*** Nuovo file creato ***" << std::endl;
        std::cout << std::endl;
        std::cout << "File name: " << this->name << std::endl;
        std::cout << "Estensione: " << this->estensione << std::endl;
        std::cout << "Data creazione: " << dataCreazione.getDay() << "/" << dataCreazione.getMonth() << "/"
                  << dataCreazione.getYear() << std::endl;
        std::cout << "Ora creazione: " << dataCreazione.getOra() << ":" << dataCreazione.getMin() << ":"
                  << dataCreazione.getSec() << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

    }


    void modUltimoAccesso(int day, int month, int year, int ora, int min, int sec) {
        dataUltimoAccesso.setDay(day);
        dataUltimoAccesso.setMonth(month);
        dataUltimoAccesso.setYear(year);
        dataUltimoAccesso.setOra(ora);
        dataUltimoAccesso.setMin(min);
        dataUltimoAccesso.setSec(sec);
    }


    void modUltimaModifica(int day, int month, int year, int ora, int min, int sec) {
        dataModifica.setDay(day);
        dataModifica.setMonth(month);
        dataModifica.setYear(year);
        dataModifica.setOra(ora);
        dataModifica.setMin(min);
        dataModifica.setSec(sec);
    }



    void printUltimoAccesso() {
        std::cout << std::endl;
        std::cout << "ULTIMO ACCESSO FILE " << this->name << this->estensione << std::endl;
        std::cout << "Data ultimo accesso: " << dataUltimoAccesso.getDay() << "/" << dataUltimoAccesso.getMonth() << "/"
                  << dataUltimoAccesso.getYear() << std::endl;
        std::cout << "Ora ultimo accesso: " << dataUltimoAccesso.getOra() << ":" << dataUltimoAccesso.getMin() << ":"
                  << dataUltimoAccesso.getSec() << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void printUltimaModifica() {
        std::cout << std::endl;
        std::cout << "ULTIMA MODIFICA FILE " << this->name << this->estensione << std::endl;
        std::cout << "Data ultima modifica: " << dataModifica.getDay() << "/" << dataModifica.getMonth() << "/"
                  << dataModifica.getYear() << std::endl;
        std::cout << "Ora ultima modifica: " << dataModifica.getOra() << ":" << dataModifica.getMin() << ":"
                  << dataModifica.getSec() << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void display(){
        std::cout << "     -" << name << estensione <<  std::endl;
    }

};


#endif //FILEDIRECTORY_FILE_H
