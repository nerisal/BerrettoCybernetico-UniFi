#include <iostream>
#include "File.h"
#include "Directory.h"

int main() {

    File file1("Book",".pdf",10,02,2017,15,36,12);

    file1.modUltimoAccesso(26,03,2017,12,39,44);
    file1.printUltimoAccesso();

    file1.modUltimaModifica(23,03,2017,23,11,12);
    file1.printUltimaModifica();

    Directory directory1("Libri",11,12,2015,13,54,22);

    directory1.modUltimoAccesso(23,12,2018,23,11,36);
    directory1.printUltimoAccesso();

    directory1.modUltimaModifica(22,12,2018,13,56,12);
    directory1.printUltimaModifica();

    directory1.addFile(&file1);

    Directory directory2("Musica",11,10,2016,16,25,15);

    directory1.addDirectory(&directory2);

    File file2("Song",".mp3",12,10,2017,20,15,36);

    directory1.addFile(&file2);

    directory1.printListFile();

    directory1.printListDirectory();

    directory1.removeFile(&file1);

    directory1.printListFile();


  ///  File file3(file1);

  ///  file3.printUltimaModifica();

  ///  Directory directory3(directory1);

  ///  directory3.printListFile();

    return 0;
}