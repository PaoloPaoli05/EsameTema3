//
// Created by paolo on 13/07/2025.
//

#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <string>


class Activity {
    std::string name, description, duration, startingTime, endingTime;
public:
    Activity(const std::string &n, const std::string &descr, const std::string &sT, const std::string &eT);
    //getters
    std::string getName()const ;
    std::string getDescription()const;
    std::string getDuration()const;
    std::string getStartingTime()const;
    std::string getEndingTime()const;
};



#endif //ACTIVITY_H
