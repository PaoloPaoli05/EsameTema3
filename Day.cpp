//
// Created by paolo on 13/07/2025.
//


#include "Day.h"

#include <iostream>

//getter
std::vector<Activity> Day::getDayActivities()const {
    return dayActivities;
}

//add activity
void Day::addActivity(const Activity &act) {
    dayActivities.push_back(act);
}
//remove activity
void Day::removeActivity(std::string name) {
    bool found = false;
    for (int i = 0; i < dayActivities.size(); i++) {
        if (dayActivities[i].getName() == name) {
            found = true;
            dayActivities.erase(dayActivities.begin() + i);
            return;
        }
    }
    if (!found)
        throw std::invalid_argument("Attività non esistente");
}