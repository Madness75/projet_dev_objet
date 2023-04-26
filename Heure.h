//
// Created by cleme on 25/04/2023.
//

#ifndef PROJETFINAL_HEURE_H
#define PROJETFINAL_HEURE_H


#include <ostream>

class Heure {
protected:
    int heure;
    int minutes;
    int seconde;
public:
    Heure(int heure, int minute, int seconde);



    friend std::ostream &operator<<(std::ostream &os, const Heure &heure);
};


#endif //PROJETFINAL_HEURE_H
