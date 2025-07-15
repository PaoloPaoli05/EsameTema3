//
// Created by paolo on 13/07/2025.
//

#ifndef ISVALIDSTRING_H
#define ISVALIDSTRING_H

#include <string>
#include <cctype>

inline bool isValidString(const std::string& str) {
    for (char c : str) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            return true;
        }
    }
    return false;
}
#endif //ISVALIDSTRING_H
