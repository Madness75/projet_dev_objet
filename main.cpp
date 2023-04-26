#include <iostream>
#include <map>

#include "Heure.h"
#include "Date.h"
#include "Agenda.h"

int main() {

    Date d1(26, 4, 2023);
    Date d2(27, 4, 2023);
    Heure h1(10, 0,0);
    Heure h2(14, 30,0);
    std::map<Date, std::map<Heure, std::string>> rendezVousTest;

    rendezVousTest[d1][h1] = "Reunion";
    rendezVousTest[d1][h2] = "Dejeuner d'affaires";
    rendezVousTest[d2][h1] = "Rendez-vous chez le dentiste";


    for (auto& date : rendezVousTest) {
        std::cout << "Rendez-vous pour la date " << date.first << ":" << std::endl;
        for (auto& heure : date.second) {
            std::cout << "\tHeure " << heure.first << ": " << heure.second << std::endl;
        }
    }




}
