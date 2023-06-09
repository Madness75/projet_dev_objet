#include <iostream>
#include <map>

#include "Heure.h"
#include "Date.h"
#include "Agenda.h"

void printMap(const std::map<int, std::map<Date, std::map<Heure, std::string>>> &myMap) {
    for (const auto &outerPair: myMap) {
        std::cout << "Index " << outerPair.first << ":\n";
        for (const auto &middlePair: outerPair.second) {
            std::cout << "\tDate " << middlePair.first << ":\n";
            for (const auto &innerPair: middlePair.second) {
                std::cout << "\t\tHeure " << innerPair.first << ": " << innerPair.second << "\n";
            }
        }
    }
}

void printAtIndex(const std::map<int, std::map<Date, std::map<Heure, std::string>>> &myMap, int index) {
    for (const auto &outerPair: myMap) {
        if (outerPair.first == index) {
            std::cout << "Index " << outerPair.first << ":\n";
            for (const auto &middlePair: outerPair.second) {
                std::cout << "\tDate " << middlePair.first << ":\n";
                for (const auto &innerPair: middlePair.second) {
                    std::cout << "\t\tHeure " << innerPair.first << ": " << innerPair.second << "\n";
                }
            }
        }
    }
}


int main() {

    //Agenda de base

    Date d1(26, 4, 2023);
    Date d2(27, 4, 2023);
    Date d3(24, 1, 2022);
    Heure h1(10, 0, 0);
    Heure h2(14, 30, 0);
    std::map<Date, std::map<Heure, std::string>> rendezVousTest;

    rendezVousTest[d1][h1] = "Reunion";
    rendezVousTest[d1][h2] = "Dejeuner d'affaires";

    Agenda agenda(1, "Mon 1er Agenda", rendezVousTest);

    //agenda.affichageRendezVous();

    agenda.ajouterRendezVous(d2, h1, "Dentiste");
    agenda.ajouterRendezVous(d3, h1, "Test");

    ////////////////////interface
    int choix;

    while (true) {

        std::cout << "Agenda" << std::endl;

        std::cout << "1. Ajoute un rendez-vous" << std::endl;
        std::cout << "2. Lister tout les rendez-vous " << std::endl;
        std::cout << "3. Afficher un rendez vous dans liste par son numéro" << std::endl;
        std::cout << "4. reporter/avancer un rendez-vous en entrant le nombre de jours" << std::endl;
        std::cout << "5. modifier lheure dun rendez-vous" << std::endl;
        std::cout << "6. supprimer un rendez-vous" << std::endl;
        std::cout << "7. enregistrer lagenda dans le fichier texte agenda.txt " << std::endl;
        std::cout << "8. charger l’agenda a partir du fichier texte agenda.txt" << std::endl;

        std::cout << "9. Quitter" << std::endl;

        std::cin >> choix;

        int jour, mois, annee;
        int heure, minutes, secondes = 0;
        int heure_cherche,minutes_cherche = 0;
        char delim_heure = ':';
        char delim_date = '/';
        int index;
        int decalage = 0;

        std::map<int, std::map<Date, std::map<Heure, std::string>>> map_trie = agenda.listeTriee();

        std::string note;
        switch (choix) {
            case 1:
                std::cout << "Entrez une date sous forme jj/mm/annee : ";
                std::cin >> jour >> delim_date >> mois >> delim_date >> annee;
                std::cout << "Entrez une Heure sous forme 12:00 : ";
                std::cin >> heure >> delim_heure >> minutes;
                std::cout << "Entrez une note : ";
                std::cin >> note;
                agenda.ajouterRendezVous(Date(jour, mois, annee), Heure(heure, minutes, secondes), note);
                break;
            case 2:
                agenda.affichageRendezVous();
                break;
            case 3:
                printMap(map_trie);
                std::cout << "Entrez le numéro du rendez vous ";
                std::cin >> index;
                printAtIndex(map_trie, index);
                break;
            case 4:
                std::cout << "Entrez la date du rendez-vous sous forme jj/mm/annee : ";
                std::cin >> jour >> delim_date >> mois >> delim_date >> annee;
                std::cout << "Entrez Heure sous forme 12:00 : ";
                std::cin >> heure >> delim_heure >> minutes;
                std::cout << "Entrez la note : ";
                std::cin >> note;

                std::cout<<"Entrez le nombre de jours pour décaler le rendez vous "<<std::endl;
                std::cin>>decalage;
                agenda.changeDateRendezVous(Date(jour, mois, annee),Heure(heure, minutes, 0),note,decalage);
                break;
            case 5:
                std::cout << "Entrez la date du rendez-vous sous forme jj/mm/annee : ";
                std::cin >> jour >> delim_date >> mois >> delim_date >> annee;

                std::cout << "Entrez l'heure a changer sous forme 12:00 : ";
                std::cin >> heure >> delim_heure >> minutes;

                std::cout << "Entrez l'heure a changer sous forme 12:00 : ";
                std::cin >> heure_cherche >> delim_heure >> minutes_cherche;

                std::cout << "Entrez la note : ";
                std::cin >> note;
                agenda.changeHeureRendezVous(Date(jour, mois, annee),Heure(heure, minutes, secondes),Heure(heure_cherche, minutes_cherche, 0),note);
                break;
            case 6:
                std::cout << "Entrez la date du rendez-vous a supprimer sous forme jj/mm/annee : ";
                std::cin >> jour >> delim_date >> mois >> delim_date >> annee;

                std::cout << "Entrez l'heure du rendez-vous 12:00 : ";
                std::cin >> heure >> delim_heure >> minutes;

                agenda.supprimerRendezVous(Date(jour,mois,annee),Heure(heure,minutes,0));
                break;
            case 7:
                agenda.sauvegarder();
                std::cout<<"L agenda a ete sauvegarder dans agenda.txt";
                break;
            case 8:
                std::cout<<"Chargement de agenda a partir de agenda.txt";
                break;
            case 9:
                return 0;


        }

    }


}
