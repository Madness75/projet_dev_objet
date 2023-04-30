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


    //agenda.affichageRendezVous();

    //printMap(agenda.listeTriee());
    std::map<int, std::map<Date, std::map<Heure, std::string>>> map_trie = agenda.listeTriee();

    //agenda.changeDateRendezVous(d1, h1, "Reunion", 10);



    Heure nouvelle_Heure_test(12,15,15);
    //agenda.changeHeureRendezVous(d1,h1,nouvelle_Heure_test,"Reunion");


    //agenda.affichageRendezVous();



    ////////////////////interface
    int choix;

    while(true){

        std::cout<<"Agenda"<<std::endl;

        std::cout<<"1. Ajoute un rendez-vous"<<std::endl;
        std::cout<<"2. Lister tout les rendez-vous "<<std::endl;
        std::cout<<"3. Afficher un rendez vous dans liste par son numéro"<<std::endl;
        std::cout<<"4. reporter/avancer un rendez-vous en entrant le nombre de jours"<<std::endl;
        std::cout<<"5. modifier lheure dun rendez-vous"<<std::endl;
        std::cout<<"6. supprimer un rendez-vous"<<std::endl;
        std::cout<<"7. enregistrer lagenda dans le fichier texte agenda.txt "<<std::endl;
        std::cout<<"8. charger l’agenda a partir du fichier texte agenda.txt"<<std::endl;

        std::cout<<"9. Quitter"<<std::endl;

        std::cin>>choix;


        switch (choix) {
            case 9:
                return 0;
            case 1:
                int jour,mois,annee;
                std::cout<<"Entrez une date sous forme jj/mm/annee : ";
                char delim_date = '/';
                std::cin>>jour>>delim_date>>mois>>delim_date>>annee;


                std::cout<<"Entrez une Heure sous forme 12:00 : ";
                int heure,minutes,secondes =0;
                char delim_heure=':';
                std::cin>>heure>>delim_heure>>minutes;

                std::cout<<"Entrez une note : ";
                std::string note;
                std::cin>>note;


                agenda.ajouterRendezVous(Date(jour,mois,annee),Heure(heure,minutes,secondes),note);
                agenda.affichageRendezVous();
                continue;

        }

    }


}
