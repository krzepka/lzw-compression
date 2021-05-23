#include<string>
#include<fstream>
#pragma once

class Coder{
protected:
    const std::string path;
    std::ifstream fread;

public:
    explicit Coder(const std::string&);
    ~Coder();
};