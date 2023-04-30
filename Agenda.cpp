//
// Created by cleme on 25/04/2023.
//

#include "Agenda.h"
#include <iostream>
#include <map>
#include <bits/stdc++.h>


Agenda::Agenda(int numero, const std::string &nom, const std::map<Date, std::map<Heure, std::string>> &rendezVous)
        : numero(numero), nom(nom), rendezVous(rendezVous) {}

std::map<Date, std::map<Heure, std::string>> Agenda::ajouterRendezVous(Date date, Heure heure, std::string note) {
    rendezVous[date][heure] = note;
    return rendezVous;
}

void Agenda::affichageRendezVous() {
    for (auto &date: rendezVous) {
        std::cout << "Rendez-vous pour la date " << date.first << ":" << std::endl;
        for (auto &heure: date.second) {
            std::cout << "\tHeure " << heure.first << ": " << heure.second << std::endl;
        }
    }
}

std::map<int, std::map<Date, std::map<Heure, std::string>>> Agenda::listeTriee() {
    std::map<int, std::map<Date, std::map<Heure, std::string>>> map_finale;

    int i = 0;
    for (auto it1 = rendezVous.begin(); it1 != rendezVous.end(); ++it1) {
        for (auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
            map_finale[i][it1->first][it2->first] = it2->second;
            i++;
        }
    }

    return map_finale;


}

void Agenda::supprimerRendezVous(Date date, Heure heure) {
    auto it1 = rendezVous.find(date);
    if (it1 != rendezVous.end()) { // Vérification si la date est présente
        auto it2 = it1->second.find(heure);
        if (it2 != it1->second.end()) { // Vérification si l'heure est présente
            it1->second.erase(it2); // Suppression de la clé dans la map interne
            if (it1->second.empty()) { // Si la map interne est vide, suppression de la clé dans la première map
                rendezVous.erase(it1);
            }
        }
    }
}

void Agenda::changeDateRendezVous(Date date_a_chercher, Heure heure, std::string note, int decalage) {


    if (rendezVous.find(date_a_chercher) == rendezVous.end()) {
        rendezVous[date_a_chercher][heure] = note;
    } else {
        std::map<Heure, std::string> &it1 = rendezVous.find(date_a_chercher)->second;
        std::string copie_note = it1.begin()->second;
        supprimerRendezVous(date_a_chercher, heure);
        date_a_chercher.reporter_decaler(decalage);
        rendezVous[date_a_chercher][heure] = copie_note;
    }

}







