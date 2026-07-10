#include "Avenger.h"
#include <iostream>

Avenger::Avenger(std::string n, int h, std::string spec) : Character(n, h) {
    specialty = spec;
}
std::string Avenger::getSpecialty() const { return specialty; }
void Avenger::useSpecialAbility() {
    std::cout << name << " uses " << specialty << "!" << std::endl;
}