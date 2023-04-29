//
// Created by cleme on 25/04/2023.
//

#include "Date.h"

Date::Date(int jour, int mois,int annee) : jour(jour), mois(mois), annee(annee) {

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

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << "jour: " << date.jour << " mois: " << date.mois << " annee: " << date.annee;
    return os;
}

void Date::reporter_decaler(int decalage) {
    jour+=decalage;

    int nbJours = 0;
    switch (mois) {
        case 1: // Janvier
        case 3: // Mars
        case 5: // Mai
        case 7: // Juillet
        case 8: // Août
        case 10: // Octobre
        case 12: // Décembre
            nbJours = 31;
            break;
        case 4: // Avril
        case 6: // Juin
        case 9: // Septembre
        case 11: // Novembre
            nbJours = 30;
            break;
        case 2: // Février
            if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0) {
                // Année bissextile
                nbJours = 29;
            } else {
                nbJours = 28;
            }
            break;

    }

    if (jour > nbJours) {
        // Ajouter une année et conserver le reste
        int reste = jour % nbJours;
        mois += jour / nbJours;
        jour = reste;
    }

    if(jour<1){
        int reste = jour %nbJours;
        mois = jour / nbJours;
        jour = reste;
    }
    // Si le mois est invalide
    if (mois > 12) {
        // Ajouter une année et conserver le reste
        int reste = mois % 12;
        annee += mois / 12;
        mois = reste;
    }
}




