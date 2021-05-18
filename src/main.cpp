#include<iostream>
#include<string>
#include "Encoder.h"
#include "Decoder.h"

int main()
{
    std::string s;
    std::cout<<"Podaj sciezke do pliku: ";
    std::cin>>s;
    try
    {    
        Encoder enc(s);
        enc.work();
        Decoder dec("output/"+s+".enc");
        dec.work();
        std::cout<<"pliki wyjsciowe znajduja sie w katalogu output"<<std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
}