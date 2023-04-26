//
// Created by cleme on 25/04/2023.
//

#include "Heure.h"

Heure::Heure(int _heure, int _minutes, int _seconde) {
    if (_seconde>=60){
        _minutes= _seconde/60;
        _seconde%=60;
    }
    if (_minutes>=60){
        _heure = _minutes/60;
        _minutes%=60;
    }
    if (_heure>=24){
        _heure %= 24;

    }
    heure = _heure;
    minutes = _minutes;
    seconde = _seconde;
}

std::ostream &operator<<(std::ostream &os, const Heure &heure) {
    os << "heure: " << heure.heure << " minutes: " << heure.minutes << " seconde: " << heure.seconde;
    return os;
}

bool Heure::operator<(const Heure &rhs) const {
    if (heure < rhs.heure)
        return true;
    if (rhs.heure < heure)
        return false;
    if (minutes < rhs.minutes)
        return true;
    if (rhs.minutes < minutes)
        return false;
    return seconde < rhs.seconde;
}

bool Heure::operator>(const Heure &rhs) const {
    return rhs < *this;
}

bool Heure::operator<=(const Heure &rhs) const {
    return !(rhs < *this);
}

bool Heure::operator>=(const Heure &rhs) const {
    return !(*this < rhs);
}


