#include <stdexcept>
#include <iostream>


#include "View.h"
#include "Day.h"
#include "Activity.h"

int main() {
    bool finish = false; //true qunado l'utente vuole uscire
    View view; //oggetto view utile per usare la view
    Day day;//oggetto day ovvero la giornata in questione
    getch();//necessario per non prendere come primo input l'invio a capo
    while (!finish) {
        try{
            int choice = view.showMenu();
            switch (choice) {
                case 1: {
                    auto act = view.addActivityFinder();
                    day.addActivity(act);
                    finish = !view.keepGoingOrExit();
                    break;
                }
                case 2: {
                    auto act = view.removeActivityFinder();
                    day.removeActivity(act);
                    finish = !view.keepGoingOrExit();
                    break;
                }
                case 3: {
                    view.showActivities(day);
                    finish = !view.keepGoingOrExit();
                    break;
                }
                case 0: {
                    finish = true;
                }
                default:
                    break;
            }

        }catch (const std::exception& e) {
            erase();
            std::string errore = std::string("ERRORE: ") + e.what() + "\nPremi un tasto per continuare";
            printw("%s", errore.c_str());
            refresh();
            getch();
        }
    }
    endwin();
    return 0;
}


