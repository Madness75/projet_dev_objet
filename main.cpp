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

    Agenda agenda(1,"Mon 1er Agenda",rendezVousTest);

    agenda.affichageRendezVous();

    agenda.ajouterRendezVous(d2,h1,"Dentiste");


    agenda.affichageRendezVous();



}
