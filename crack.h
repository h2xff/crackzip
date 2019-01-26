#ifndef CRACK_H
#define CRACK_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <string.h>
#include <cstdint>

#include "crc32.h"

using namespace std;

//predefined value
#define FILE_SIZE 12
#define ZIPID 0x04034b50UL
#define CRC 12
#define K0 0x12345678UL;
#define K1 0x23456789UL;
#define K2 0x34567890UL;

//crackzip class
class crackzip
{
 public:
    crackzip(std::string filename,std::string dict_file);

public:
    void loadzip(std::string filename);
    void open_dict(std::string dict_file);
    void crackpw();

protected:
    uint32_t fget_16(FILE *f);
    uint32_t fget_32(FILE *f);
    bool get_next_pw();
    bool check_pw();

 private:
    std::string filename;
    std::ifstream dict_f;
    std::string pw;
    char zip_name[40];

    uint32_t id;
    uint16_t version;
    uint16_t flags;
    uint16_t compression_method;
    uint16_t lastmodtime;
    uint16_t lastmoddate;
    uint32_t crc32;
    uint32_t compr_size;
    uint32_t uncompr_size;
    uint16_t name_len;
    uint16_t extra_field_len;
    uint8_t file[20];
    uint16_t truecrc;
};

#endif
