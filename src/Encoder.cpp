#include "Encoder.h"
#include<fstream>
#include <utility>

Encoder::Encoder(const std::string& s, std::string out):Coder(s), outname(std::move(out)){};

void Encoder::work(){
    std::ofstream out;
    out.open("output/"+outname+".enc", std::ios_base::binary);    //std::ios::binary

    char currentChar;
    fread.get(currentChar);

    // initialize word with the first character
    std::string characters {currentChar};

    refillDictionary();

    while(fread.get(currentChar)){
        if(existsInDictionary(characters + currentChar)){
            characters += currentChar;
        }
        else{
//            out << getDictionaryValue(characters);
            out.write(reinterpret_cast<char*>(getDictionaryValue(characters)), sizeof(CodeType));
            addToDictionary(characters + currentChar);
            characters = std::string{currentChar};
        }

        handleFullDictionary();

    }
    out << currentChar;

    out.close();
}

void Encoder::refillDictionary() {
    dictionary.clear();
    for(CodeType i=0; i < 256; ++i){
        dictionary.insert(DictionaryElementType (std::string{static_cast<char>(i)}, i));
    }
}

bool Encoder::existsInDictionary(const std::string& key) {
    return dictionary.find(key) != dictionary.end();
}

void Encoder::addToDictionary(const std::string& key) {
    dictionary.insert(DictionaryElementType(key, static_cast<CodeType>(dictionary.size())));
}

CodeType* Encoder::getDictionaryValue(const std::string &key) {
    auto element = dictionary.find(key);
    if(element != dictionary.end()){
        return &dictionary.find(key)->second;
    }
    else{
        throw std::runtime_error("Attempted dictionary read of a key that does not exists.");
    }
}

void Encoder::handleFullDictionary() {
    if(dictionary.size() == std::numeric_limits<CodeType>::max()){
        refillDictionary();
    }
}
