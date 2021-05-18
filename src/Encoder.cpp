#include "Encoder.h"
#include<fstream>

Encoder::Encoder(std::string s):Coder(s){};

void Encoder::work(){
    std::ofstream out;
    out.open("output/"+path+".enc");    //std::ios::binary
    out<<"nothing";    
    out.close(); 
    //TODO
}