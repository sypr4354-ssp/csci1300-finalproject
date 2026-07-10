#ifndef AVENGER_H
#define AVENGER_H
#include "Character.h"
#include <string>

class Avenger : public Character {
private:
    std::string specialty;
public:
    Avenger(std::string n, int h, std::string spec);
    std::string getSpecialty() const;
    void useSpecialAbility();
};
#endif