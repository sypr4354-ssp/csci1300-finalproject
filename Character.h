#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character {
protected:
    std::string name;
    int health;
public:
    Character(std::string n, int h);
    virtual ~Character() {}
    std::string getName() const;
    int getHealth() const;
};
#endif