//
// Created by cleme on 25/04/2023.
//

#include "Agenda.h"
#include <iostream>
#include <map>


Agenda::Agenda(int numero, const std::string &nom, const std::map<Date, std::map<Heure, std::string>> &rendezVous)
        : numero(numero), nom(nom), rendezVous(rendezVous) {}

std::map<Date, std::map<Heure, std::string>> Agenda::ajouterRendezVous(Date date, Heure heure, std::string note) {
    rendezVous[date][heure] = note;
    return rendezVous;
}

std::string Agenda::affichageRendezVous() {
    for (auto& date : rendezVous) {
        std::cout << "Rendez-vous pour la date " << date.first << ":" << std::endl;
        for (auto& heure : date.second) {
            std::cout << "\tHeure " << heure.first << ": " << heure.second << std::endl;
        }
    }
}




