//
// Created by paolo on 13/07/2025.
//

#ifndef DAY_H
#define DAY_H
#include <vector>
#include "Activity.h"

class Day {
    std::vector<Activity> dayActivities;//attività del giorno
public:
    //getter
    std::vector<Activity> getDayActivities()const;

    //aggiunta attività
    void addActivity(const Activity &act);

    //rimuovi attività
    void removeActivity(std::string name);

};



#endif //DAY_H
