#include <iostream>
#include <string>
#include "Encoder.h"
#include "Decoder.h"

int main(int argc, char* argv[])
{
    std::string input, outname;
    if(argc == 1)
    {
        std::cout<<"Podaj sciezke do pliku: ";
        std::cin>>input;
        std::cout<<"Podaj nazwę pliku wyjściowego: ";
        std::cin>>outname;
    }
    else if (argc == 3)
    {
        input = argv[1];
        outname = argv[2];
    }
    else
    {
        std::cout<<"Niewłaściwa liczba argumentów!"<<std::endl;
        return -1;
    }
    try
    {
        {
            Encoder enc(input, outname);
            enc.work();
        }
        Decoder dec("output/"+outname+".enc");
        dec.work();
        //std::cout<<"pliki wyjsciowe znajduja sie w katalogu output"<<std::endl;
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }
}