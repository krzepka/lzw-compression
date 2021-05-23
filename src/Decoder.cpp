#include "Decoder.h"

Decoder::Decoder(const std::string &s) : Coder(s) {};

void Decoder::work() {
    std::ofstream out;
    std::string decoded = path;
    out.open(decoded.erase(decoded.size()-4, 4), std::ios::binary);    //std::ios::binary

    CodeType currentCode;
    std::string characters;

    refillDictionary();

    while (fread.get(reinterpret_cast<char*>(&currentCode), 2)) {
        throw_cannot_decode(currentCode);
        handleFullDictionary();

        if(currentCode == dictionary.size()){
            appendToDictionary(characters + characters[0]);
        }
        else if(!characters.empty()){
            appendToDictionary(characters + dictionary[currentCode][0]);
        }

        out << dictionary[currentCode];
        characters = dictionary[currentCode];

    }

    out.close();
}

void Decoder::throw_cannot_decode(CodeType character) {
    if (static_cast<int>(character) > dictionary.size()) {
        throw std::runtime_error("Cannot decode, character: " + std::to_string(static_cast<int>(character)) +
                                 ", dict size: " + std::to_string(dictionary.size()));
    }

}

void Decoder::appendToDictionary(const std::string& value) {
    dictionary.push_back(value);
}

void Decoder::handleFullDictionary() {
    if(dictionary.size() == std::numeric_limits<CodeType>::max()){
        refillDictionary();
    }
}

void Decoder::refillDictionary() {
    dictionary.clear();
    for(CodeType i=0; i < 256; ++i){
        dictionary.push_back(std::string{static_cast<char>(i)});
    }

}

