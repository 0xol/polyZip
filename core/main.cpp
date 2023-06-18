#include <iostream>
#include <fs.hpp>

int main(int argc, char *argv[]) {
    
    std::cout << "Does polyZip.exe exist: " << fs.exists("polyZip.exe") << std::endl;

    std::cout << "Is polyZip.exe a file: " << fs.isFile("polyZip.exe") << std::endl;

    std::cout << "Is polyZip.exe a folder: " << fs.isFolder("polyZip.exe") << std::endl;
    
    for (const auto file : fs.listDir(".")) {
        std::cout << file << std::endl;
    }

    for (const auto file : fs.listFilesInDirByFileExtension(".", ".exe")) {
        std::cout << "Searching for .exe files: FOUND " << file << std::endl;
    }

    for (const auto file : fs.listFilesInDir(".")) {
        std::cout << "Found file: " << file << std::endl;
    }
    
    for (const auto folder : fs.listFoldersInDir(".")) {
        std::cout << "Found folder: " << folder << std::endl;
    }

    return 0;
}