//
// Created by cleme on 25/04/2023.
//

#ifndef PROJETFINAL_AGENDA_H
#define PROJETFINAL_AGENDA_H

#include <iostream>
#include <map>

#include "Date.h"
#include "Heure.h"

class Agenda {
protected:
    int numero;
    std::string nom;
    std::map<Date, std::map<Heure, std::string>> rendezVous;
public:
    Agenda(int numero, const std::string &nom, const std::map<Date, std::map<Heure, std::string>> &rendezVous);

    std::map<Date, std::map<Heure, std::string>> ajouterRendezVous(Date date, Heure heure, std::string note);

    void affichageRendezVous();

    std::map<int, std::map<Date, std::map<Heure, std::string>>> listeTriee();

    void supprimerRendezVous(Date date, Heure heure);

    void changeDateRendezVous(Date date_a_chercher, Heure heure, std::string note, int decalage);

    void changeHeureRendezVous(Date date_a_chercher, Heure heure_a_chercher, Heure nouvelle_heure, std::string note);



};


#endif //PROJETFINAL_AGENDA_H
