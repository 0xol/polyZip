//handles fs calls
#include <fs.hpp>
#include <stdint.h>

#if __cplusplus >= 201703L
#include <filesystem>
bool fsClass::isFile(std::string path) {
    if (path == "") {path = ".";}
    return std::filesystem::is_regular_file(path);
}

bool fsClass::isFolder(std::string path) {
    if (path == "") {path = ".";}
    return std::filesystem::is_directory(path);
}

bool fsClass::exists(std::string path) {
    if (path == "") {path = ".";}
    return std::filesystem::exists(path);
}

std::vector<std::string> fsClass::listDir(std::string path) {
    if (path == "") {path = ".";}

    std::vector<std::string> files;
    for (const auto file : std::filesystem::directory_iterator(path)) {
        files.push_back(file.path().string());
    }
    return files;
}

std::vector<std::string> fsClass::listFilesInDirByFileExtension(std::string path, std::string fileExtension) {
    if (path == "") {path = ".";}

    std::vector<std::string> files;
    std::vector<std::string> newFiles;
    files = listDir(path);

    for (const auto file : files) {
        if (file.substr(file.length() - fileExtension.length()) == fileExtension && isFile(path + "/" + file)) {newFiles.push_back(file);}
    }
    return newFiles;
}

std::vector<std::string> fsClass::listFilesInDir(std::string path) {
    if (path == "") {path = ".";}

    std::vector<std::string> files;
    std::vector<std::string> newFiles;
    files = listDir(path);

    for (const auto file : files) {
        if (isFile(path + "/" + file)) {newFiles.push_back(file);}
    }
    return newFiles;
}

std::vector<std::string> fsClass::listFoldersInDir(std::string path) {
    if (path == "") {path = ".";}

    std::vector<std::string> files;
    std::vector<std::string> newFiles;
    files = listDir(path);

    for (const auto file : files) {
        if (isFolder(path + "/" + file)) {newFiles.push_back(file);}
    }
    return newFiles;
}
#else
#error no suitable fs backend could be compiled, try adding c++17 extensions to the CCFLAGS or porting/creating a new backend
#endif

class fsClass fs;