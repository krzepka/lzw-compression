#include<string>
#include <map>
#include "Coder.h"
#pragma once

typedef unsigned short CodeType;
typedef std::map<std::string, CodeType> DictionaryType;

class Decoder: Coder{
    DictionaryType dictionary;
public:
    void work();
    explicit Decoder(const std::string&);

    void throw_cannot_decode(CodeType character);
};