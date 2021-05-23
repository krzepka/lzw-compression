#include<string>
#include <map>
#include "Coder.h"
#pragma once

typedef unsigned short CodeType;
typedef std::map<std::string, CodeType> DictionaryType;
typedef std::pair<std::string, CodeType> DictionaryElementType;

class Encoder: Coder{
private:
    DictionaryType dictionary;
    const std::string outname;
    void refillDictionary();
    bool existsInDictionary(const std::string& key);
    void addToDictionary(const std::string& key);
    CodeType* getDictionaryValue(const std::string& key);
    void handleFullDictionary();

public:
    void work();
    Encoder(const std::string&, std::string);

};