//
// Created by paolo on 13/07/2025.
//


#include "Activity.h"

#include<stdexcept>
#include<iostream>
#include "isValidString.h"
#include "isValidTime.h"

//costruttore
Activity::Activity(const std::string &n, const std::string &descr, const std::string &sT, const std::string &eT) {
    if (isValidString(n))
        name = n;
    else
        throw std::invalid_argument("Nome non valido");
    if (isValidString(descr))
        description = descr;
    else
        throw std::invalid_argument("Descriziopne non valida");

    if (isValidTime(sT))
        startingTime = sT;
    else
        throw std::invalid_argument("Orario non valido");

    if (isValidTime(eT)) {
        int sHour = std::stoi(sT.substr(0, 2));
        int eHour = std::stoi(eT.substr(0, 2));
        int sMin = std::stoi(sT.substr(3, 2));
        int eMin = std::stoi(eT.substr(3, 2));

        /*//controllo che la fine non sia precedente all'inizio
        if (eHour < sHour || (eHour == sHour && eMin <= sMin))
            throw std::invalid_argument("L'inizio deve essere precedente alla fine");
        endingTime = eT;*/
        if (eT<=startingTime)
            throw std::invalid_argument("L'inizio deve essere precedente alla fine");

        endingTime = eT;

        //trovo i minuti totali della durata
        int durationMinutes = (eHour * 60 + eMin) - (sHour * 60 + sMin);

        //la divido in ore e minuti
        int durHours = durationMinutes / 60;
        int durMinutes = durationMinutes % 60;

        //CONVERSIONE IN STRINGA CON FORMATO 00:00
        //aggiungo ore con zero davanti se necessario
        if (durHours < 10)
            duration += "0";
        duration += std::to_string(durHours);

        duration += ":";

        //aggiungo minuti con zero davanti se necessario
        if (durMinutes < 10)
            duration += "0";
        duration += std::to_string(durMinutes);

    }else
        throw std::invalid_argument("Orario non valido");
}

//getters
std::string Activity::getName()const {
    return name;
}
std::string Activity::getDescription() const{
    return description;
}
std::string Activity::getDuration() const {
    return duration;
}
std::string Activity::getStartingTime() const {
    return startingTime;
}
std::string Activity::getEndingTime() const {
    return endingTime;
}
