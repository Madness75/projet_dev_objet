//
// Created by cleme on 25/04/2023.
//

#ifndef PROJETFINAL_Date_H
#define PROJETFINAL_Date_H


#include <ostream>

class Date {
protected:
    int jour;
    int mois;
    int annee;
public:
    Date(const int& jour, const int& mois, const int& annee);
    bool valid() const;

    int getJour() const;

    void setJour(int jour);

    int getMois() const;

    void setMois(int mois);

    int getAnnee() const;

    void setAnnee(int annee);

    bool operator == (const Date&) const;

    bool operator != (const Date&)const;

    bool operator < (const Date&) const;

    bool operator > (const Date&) const;

    bool operator<= (const Date&) const;

    bool operator >= (const Date&) const;

    friend std::ostream &operator<<(std::ostream &os, const Date &date);
};


#endif //PROJETFINAL_Date_H
