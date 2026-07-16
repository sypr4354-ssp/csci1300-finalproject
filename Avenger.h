#ifndef AVENGER_H
#define AVENGER_H
#include "Character.h"
#include <string>

class Avenger : public Character {
private:
    std::string specialty;
    int powerLevel;
public:
    Avenger(std::string n, int h, std::string spec, int pLevel);
    std::string getSpecialty() const;
    int getPowerLevel() const;
    bool calculateMissionSuccess(int threatDifficulty); 
};
#endif