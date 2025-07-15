//
// Created by paolo on 13/07/2025.
//
#include "View.h"

#include <stdexcept>

View::View() {
    window = initscr();//inizializza
    nocbreak();// torna in “cooked mode”
    echo();// mostra gli input
}


int View::showMenu(){
    clear();
    char choice[3];
    printw("GIORNATA\n"
           "1)Aggiungi attività\n"
           "2)Rimuovi attività\n"
           "3)Mostra tutte le attività\n"
           "0)Esci\n"
           "Inserisci scelta: ");
    refresh();
    getnstr(choice,sizeof(choice));
    clear();
    switch (choice[0]) {
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '0': return 0;
        default:
            throw std::invalid_argument("Inserisci un numero valido");
    }
}
Activity View::addActivityFinder() {
    clear();
    char name[256], descr[256],
    start[256], end[256], dur[256];//necessario per getnstr()
    printw("Aggiungi attività\n");
    printw("\nNome: "); refresh();
    getnstr(name,256);
    printw("\nDescrizione: "); refresh();
    getnstr(descr,256);
    printw("\nOra d'inizio ( Usare formato 00:00 ) :"); refresh();
    getnstr(start,256);
    printw("\nOra di fine ( Usare formato 00:00 ) : "); refresh();
    getnstr(end,256);
    return Activity(std::string(name), std::string(descr),
        std::string(start), std::string(end));
}
std::string View::removeActivityFinder() {
    clear();
    char name[256];
    printw("Rimuovi attività\n\n"
           "Nome: ");
    refresh();
    getnstr(name,256);
    return name;
}
void View::showActivities(const Day& day) {
    clear();
    if (day.getDayActivities().empty()) {
        printw ("Ancora nessuna attività aggiunta.");
        refresh();
    }
    else {
        for (const auto &i : day.getDayActivities()) {
            printw("%s: %s (%s-%s ; %s)\n",
                   i.getName().c_str(),
                   i.getDescription().c_str(),
                   i.getStartingTime().c_str(),
                   i.getEndingTime().c_str(),
                   i.getDuration().c_str());
        }
    }
    printw("\n\nPremi un tasto per continuare: ");
    refresh();
    getch();
}
bool View::keepGoingOrExit() {
    clear();
    char choice[3];
    printw("1)Torna al menù\n"
           "0)Esci\n"
           "Inserisci scelta: ");
    refresh();
    getnstr(choice,sizeof(choice));
    switch (choice[0]) {
        case '0': return false;
        case '1': return true;
        default:
            throw std::invalid_argument("Inserisci il numero di valido");
    }
}
