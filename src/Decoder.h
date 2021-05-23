#include <string>
#include <vector>
#include "Coder.h"
#pragma once

typedef unsigned short CodeType;
typedef std::vector<std::string> DecoderDictionaryType;

class Decoder: Coder{
    DecoderDictionaryType dictionary;
public:
    void work();
    explicit Decoder(const std::string&);

    void throw_cannot_decode(CodeType character);

    void appendToDictionary(const std::string& value);

    void handleFullDictionary();

    void refillDictionary();
};