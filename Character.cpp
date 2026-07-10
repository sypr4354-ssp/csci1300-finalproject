#include "Character.h"

Character::Character(std::string n, int h) {
    name = n;
    health = h;
}
std::string Character::getName() const { return name; }
int Character::getHealth() const { return health; }