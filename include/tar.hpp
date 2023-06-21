#pragma once

#include <string>
#include <stdint.h>

typedef struct posixTarHeader {
    int8_t name[100];
    int8_t mode[8];
    int8_t uid[8];
    int8_t gid[8];
    int8_t size[12];
    int8_t mtime[12];
    int8_t chksum[8];
    int8_t typeflag;
    int8_t linkname[100];
    int8_t magic[6];
    int8_t version[2];
    int8_t uname[32];
    int8_t gname[32];
    int8_t devmajor[8];
    int8_t devminor[8];
    int8_t prefix[155];
}posixTarHeader;

typedef struct tarFile {
    posixTarHeader header;
}tarFile;

class tarClass{
    public:
        tarFile openTar(std::string path);
};
extern tarClass tar;