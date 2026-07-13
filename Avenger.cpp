#include "Avenger.h"
#include <iostream>

Avenger::Avenger(std::string n, int h, std::string spec, int pLevel) : Character(n, h) {
    specialty = spec;
    powerLevel = pLevel;
}

std::string Avenger::getSpecialty() const { return specialty; }
int Avenger::getPowerLevel() const { return powerLevel; }

// Fleshed out core logic method
bool Avenger::calculateMissionSuccess(int threatDifficulty) {
    std::cout << name << " is calculating tactical trajectory using: " << specialty << "..." << std::endl;
    if (powerLevel >= threatDifficulty) {
        return true;
    }
    return false;
}