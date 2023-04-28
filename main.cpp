#include <iostream>
#include <map>

#include "Heure.h"
#include "Date.h"
#include "Agenda.h"

void printMap(const std::map<int, std::map<Date, std::map<Heure, std::string>>>& myMap) {
    for (const auto& outerPair : myMap) {
        std::cout << "Index " << outerPair.first << ":\n";
        for (const auto& middlePair : outerPair.second) {
            std::cout << "\tDate " << middlePair.first << ":\n";
            for (const auto& innerPair : middlePair.second) {
                std::cout << "\t\tHeure " << innerPair.first << ": " << innerPair.second << "\n";
            }
        }
    }
}

void printAtIndex(const std::map<int, std::map<Date, std::map<Heure, std::string>>>& myMap,int index){
    for (const auto& outerPair: myMap){
        if (outerPair.first == index){
            std::cout << "Index " << outerPair.first << ":\n";
            for (const auto& middlePair : outerPair.second) {
                std::cout << "\tDate " << middlePair.first << ":\n";
                for (const auto& innerPair : middlePair.second) {
                    std::cout << "\t\tHeure " << innerPair.first << ": " << innerPair.second << "\n";
                }
            }
        }
    }
}



int main() {

    Date d1(26, 4, 2023);
    Date d2(27, 4, 2023);
    Date d3(24,1,2022);
    Heure h1(10, 0,0);
    Heure h2(14, 30,0);
    std::map<Date, std::map<Heure, std::string>> rendezVousTest;

    rendezVousTest[d1][h1] = "Reunion";
    rendezVousTest[d1][h2] = "Dejeuner d'affaires";

    Agenda agenda(1,"Mon 1er Agenda",rendezVousTest);

    //agenda.affichageRendezVous();

    agenda.ajouterRendezVous(d2,h1,"Dentiste");
    agenda.ajouterRendezVous(d3,h1,"Test");


    //agenda.affichageRendezVous();

    //printMap(agenda.listeTriee());
    std::map<int, std::map<Date, std::map<Heure, std::string>>> map_trie =agenda.listeTriee();

    printAtIndex(map_trie,1);

    return 0;
}
