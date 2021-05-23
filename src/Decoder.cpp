#include "Decoder.h"

Decoder::Decoder(const std::string &s) : Coder(s) {};

void Decoder::work() {
    std::ofstream out;
    std::string decoded = path;

    int previousIndex;
    char firstChar;

    CodeType currentCode;


    std::string S;

    while (fread.get(reinterpret_cast<char*>(&currentCode), 2)) {
        throw_cannot_decode(currentCode);


    }
    out << currentCode;

    out.close();
}

void Decoder::throw_cannot_decode(CodeType character) {
    if (static_cast<int>(character) > dictionary.size()) {
        throw std::runtime_error("Cannot decode, character: " + std::to_string(static_cast<int>(character)) +
                                 ", dict size: " + std::to_string(dictionary.size()));
    }

}
