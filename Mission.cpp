#include "Mission.h"

Mission::Mission(std::string loc, int diff, std::string item) {
    locationName = loc;
    threatDifficulty = diff;
    requiredItem = item;
}
std::string Mission::getLocationName() const { return locationName; }
int Mission::getThreatDifficulty() const { return threatDifficulty; }
std::string Mission::getRequiredItem() const { return requiredItem; }