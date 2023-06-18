#pragma once

#include <string>
#include <vector>

class fsClass {
    public:
        bool isFile(std::string path);
        bool isFolder(std::string path);
        bool exists(std::string path);
        
        std::vector<std::string> listDir(std::string path);
        std::vector<std::string> listFilesInDirByFileExtension(std::string path, std::string fileExtension);
        std::vector<std::string> listFilesInDir(std::string path);
        std::vector<std::string> listFoldersInDir(std::string path);
};
extern fsClass fs;