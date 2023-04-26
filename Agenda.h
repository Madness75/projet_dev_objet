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
    std::map<Date, std::map<Heure, std::string>> rendezVous;
public:
    explicit Agenda(const std::map<Date, std::map<Heure, std::string>> &rendezVous);

    Agenda ajouterRendezVous(std::map<Date, std::map<Heure, std::string>> rendezVousAjoute) ;

};


#endif //PROJETFINAL_AGENDA_H
