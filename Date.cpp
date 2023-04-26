//
// Created by cleme on 25/04/2023.
//

#include "Date.h"

Date::Date(const int& jour, const int& mois,const int& annee) : jour(jour), mois(mois), annee(annee) {

}

bool Date::valid() const {
    if (annee <0) return false;
    if (mois >12 || mois <1) return false;
    if (jour > 31 || jour < 1) { return false; }
    if ((jour ==31 &&
         ( mois ==2 || mois ==4 || mois ==6 || mois ==9 || mois ==11) ) )
        return false;
    if ( jour ==30 && mois ==2) return false;
    if ( annee <2000){
        if ((jour ==29 && mois ==2) && !((annee -1900)%4==0)) return false;
    };
    if ( annee >2000){
        if ((jour ==29 && mois ==2) && !((annee -2000)%4==0)) return false;
    };
    return true;

}

int Date::getJour() const {
    return jour;
}

void Date::setJour(int jour) {
    Date::jour = jour;
}

int Date::getMois() const {
    return mois;
}

void Date::setMois(int mois) {
    Date::mois = mois;
}

int Date::getAnnee() const {
    return annee;
}

void Date::setAnnee(int annee) {
    Date::annee = annee;
}

bool Date::operator==(const Date & date) const {
    if (!valid() || !date.valid()) {
        return false;
    }

    return jour == date.jour && mois == date.mois && annee == date.annee;
}

bool Date::operator!=(const Date & date) const {
    return !(*this == date);
}

bool Date::operator<(const Date& date) const {
    if (annee < date.annee) {
        return true;
    } else if (annee == date.annee && mois < date.mois) {
        return true;
    } else if (annee == date.annee && mois == date.mois && jour < date.jour) {
        return true;
    } else {
        return false;
    }
}

bool Date::operator>(const Date & date) const {
    if (*this == date) return false;
    if (!(*this<date)) return false;
    return true;
}

bool Date::operator <= (const Date& date) const{
    if (*this == date) return true;
    return *this <date;
}

bool Date::operator>=(const Date & date) const {
    if (*this == date) return true;
    return *this > date;
}




