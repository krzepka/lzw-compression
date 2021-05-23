#include "Decoder.h"

Decoder::Decoder(const std::string &s) : Coder(s) {};

void Decoder::work() {
    std::ofstream out;
    std::string decoded = path;

    int previousIndex;
    char firstChar;

    char currentChar;

    std::string S;

    while (fread.get(currentChar)) {
        throw_cannot_decode(currentChar);


    }
    out << currentChar;

    out.close();
}

void Decoder::throw_cannot_decode(char character) {
    if (static_cast<int>(character) > dictionary.size()) {
        throw std::runtime_error("Cannot decode, character: " + std::to_string(static_cast<int>(character)) +
                                 ", dict size: " + std::to_string(dictionary.size()));
    }

}
