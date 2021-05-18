#include<string>
#include<fstream>
#pragma once

class Coder{
    protected:
    std::ifstream fread;

    public:
    Coder(std::string);
};