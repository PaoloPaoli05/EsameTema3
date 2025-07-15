//
// Created by paolo on 13/07/2025.
//

#ifndef VIEW_H
#define VIEW_H

#include <ncurses.h>
#include "Day.h"

class View {
public:
    View ();
    int showMenu(); //menù iniziale
    Activity addActivityFinder();//aggiungoi attività
    std::string removeActivityFinder();//rimuovi attività
    void showActivities(const Day& day);//mostra attività
    bool keepGoingOrExit();
private:
    WINDOW *window;
};

#endif

