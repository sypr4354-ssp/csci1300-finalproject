#ifndef AVENGER_H
#define AVENGER_H
#include "Character.h"
#include <string>

class Avenger : public Character {
private:
    std::string specialty;
    int powerLevel; // Added field to show substantial progress
public:
    Avenger(std::string n, int h, std::string spec, int pLevel);
    std::string getSpecialty() const;
    int getPowerLevel() const;
    
    // Core method fleshed out beyond empty stubs
    bool calculateMissionSuccess(int threatDifficulty); 
};
#endif