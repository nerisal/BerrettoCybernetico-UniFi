#include <vector>
#include <iostream>

#include "CompressionManager.h"

int main() {
    CompressionManager manager = CompressionManager();

    // Creating some dummy files
    std::vector<std::pair<std::string, std::string>> files;
    files.emplace_back("MySuperFile.docx", "Hello World: This is my awesome file content.");
    files.emplace_back("MyNewFile.xls", "Bonjour le monde, voici mon fichier génial.");
    files.emplace_back("IlMioFile.txt", "tre tigri contro tre tigri");

    for (int i = 0; i < files.size(); ++i) {
        std::cout << "Comprimo " << files[i].first << "\ncontenuto: " << files[i].second <<  std::endl;
        std::cout << manager.compressFile(files[i].first, files[i].second) <<std::endl;

        std::cout << "Decomprimo " << files[i].first << std::endl;
        std::cout << manager.decompressFile(files[i].first, files[i].second) << std::endl << std::endl;
    }

}
