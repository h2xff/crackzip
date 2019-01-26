#include "crack.h"

int main(int argc, char *argv[])
{
    std::string filename = std::string(argv[1]);
    std::string dict_file = std::string(argv[2]);
    crackzip crack(filename, dict_file);
    crack.crackpw();
    return 0;
}
