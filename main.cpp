#include <iostream>
#include <map>

#include "Heure.h"
#include "Date.h"
#include "Agenda.h"

int main() {

    Date date1 = Date(26,04,2023);
    Heure h1 = Heure(0,0,82800);
    std::cout<<h1<<std::endl;
    std::cout<<date1<<std::endl;


    std::map<Date, std::map<Heure, std::string>> rendezVousTest;


}
