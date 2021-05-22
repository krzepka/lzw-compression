#include<string>
#include<fstream>
#pragma once

class Coder{
protected:
    std::ifstream fread;
    const std::string path;

public:
    explicit Coder(const std::string&);
    ~Coder();
};