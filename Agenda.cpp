//
// Created by cleme on 25/04/2023.
//

#include "Agenda.h"
#include <iostream>
#include <map>

Agenda::Agenda(const std::map<Date, std::map<Heure, std::string>> &rendezVous) : rendezVous(rendezVous) {}

Agenda Agenda::ajouterRendezVous(std::map<Date, std::map<Heure, std::string>> rendezVousAjoute) {
    for (auto& rdv : rendezVousAjoute) {
        Date date = rdv.first;
        std::map<Heure, std::string> rdvHeure = rdv.second;
        for (auto& rdvH : rdvHeure) {
            Heure heure = rdvH.first;
            std::string note = rdvH.second;
            rendezVous[date][heure] = note;
        }
    }
    return *this;
}
