#ifndef MISSION_H
#define MISSION_H
#include <string>

class Mission {
private:
    std::string locationName;
    int threatDifficulty;
    std::string requiredItem;
public:
    Mission(std::string loc, int diff, std::string item);
    std::string getLocationName() const;
    int getThreatDifficulty() const;
    std::string getRequiredItem() const;
};
#endif