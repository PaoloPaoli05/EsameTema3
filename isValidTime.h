//
// Created by paolo on 15/07/2025.
//

#ifndef ISVALIDTIME_H
#define ISVALIDTIME_H
#include <string>
//controllo per i tempi
bool isValidTime(const std::string &t) {
    bool valid = true;
    if (t.size() != 5 || t[2] != ':')
        valid = false;
    else if (!isdigit(t[0]) || !isdigit(t[1]) || !isdigit(t[3]) || !isdigit(t[4]))
        valid = false;
    else {
        int hours = std::stoi(t.substr(0, 2));
        int minutes = std::stoi(t.substr(3, 2));
        valid = (hours >= 0 && hours <= 23) && (minutes >= 0 && minutes <= 59);
    }
    return valid;
}
#endif //ISVALIDTIME_H
