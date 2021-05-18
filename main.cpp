#include<iostream>
#include<string>
#include "Encoder.h"
#include "Decoder.h"

int main()
{
    std::string s;
    std::cout<<"Podaj sciezke do pliku:";
    std::cin>>s;
    Encoder enc(s);
    enc.work();
    std::cout<<"Nothing happens because nothing is implemented lol rekt"<<std::endl;
}