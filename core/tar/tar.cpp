//main file for tar support
#include <tar.hpp>
#include <fs.hpp>
#include <iostream>
#include <fstream>

tarFile tarClass::openTar(std::string path) {
    tarFile temp;

    FILE* file = fopen(path.c_str(), "rb");

    char *tempHeaderChar = (char*)&temp.header;
    fread(tempHeaderChar, 500, 1, file);

    std::cout << "Header name: " << temp.header.name << std::endl;
    std::cout << "Mode: " << temp.header.mode << std::endl;
    std::cout << "UID: " << temp.header.uid << std::endl;
    std::cout << "GID: " << temp.header.gid << std::endl;
    std::cout << "Size: " << temp.header.size << std::endl;
    std::cout << "Mtime: " << temp.header.mtime << std::endl;
    std::cout << "Checksum: " << temp.header.chksum << std::endl;
    std::cout << "Typeflag: " << temp.header.typeflag << std::endl;
    std::cout << "Linkname: " << temp.header.linkname << std::endl;
    std::cout << "Magic: " << temp.header.magic << std::endl;
    std::cout << "Version: " << temp.header.version << std::endl;
    std::cout << "Uname: " << temp.header.uname << std::endl;
    std::cout << "Gname: " << temp.header.gname << std::endl;
    std::cout << "Devmajor: " << temp.header.devmajor << std::endl;
    std::cout << "Devminor: " << temp.header.devminor << std::endl;
    std::cout << "Prefix: " << temp.header.prefix << std::endl;


    return temp;
}
tarClass tar;