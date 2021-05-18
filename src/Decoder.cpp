#include "Decoder.h"

Decoder::Decoder(std::string s):Coder(s){};

void Decoder::work(){
    std::ofstream out;
    std::string decoded = path;
    out.open(decoded.erase(decoded.size()-4, 4));    //std::ios::binary
    out<<"nothing";   
    out.close(); 
    //TODO
}