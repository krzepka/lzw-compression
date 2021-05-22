#include "Coder.h"
#include <exception>

Coder::Coder(const std::string& p):path(p), fread(p, std::ios::binary) {
    if(!fread.is_open())
        throw std::invalid_argument("File failed to open");
}

Coder::~Coder(){
    fread.close();
}
