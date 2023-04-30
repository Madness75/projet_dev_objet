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

std::string Agenda::affichageRendezVous() {
    for (auto& date : rendezVous) {
        std::cout << "Rendez-vous pour la date : " << date.first << ":" << std::endl;
        for (auto& heure : date.second) {
            std::cout << "\tHoraire du rendez-vous -> " << heure.first << " Note : " << heure.second << std::endl;
        }
    }
}

std::map<int, std::map<Date, std::map<Heure, std::string>>> Agenda::listeTriee() {
    std::map<int, std::map<Date, std::map<Heure, std::string>>> map_finale;

    int i=0;
    for(auto it1 = rendezVous.begin();it1 != rendezVous.end();++it1){
        for (auto  it2 = it1->second.begin();it2!= it1->second.end();++it2){
            map_finale[i][it1->first][it2->first]=it2->second;
            i++;
        }
    }

    return map_finale;
}





