#include<string>
#include "Coder.h"
#pragma once

class Encoder: Coder{
private:
    const std::string outname;
public:
    void work();
    Encoder(std::string, std::string);
};