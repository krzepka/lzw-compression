#include "Encoder.h"
#include<fstream>

Encoder::Encoder(std::string s, std::string out):Coder(s), outname(out){};

void Encoder::work(){
    std::ofstream out;
    out.open("output/"+outname+".enc");    //std::ios::binary
    out<<"nothing";    
    out.close(); 
    //TODO
}