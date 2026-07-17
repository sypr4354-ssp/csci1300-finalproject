#include <iostream>
#include <vector>
#include <fstream>
#include "Avenger.h"
#include "Mission.h"

using namespace std;

int main() {
    // Game State Trackers 
    int currentDay = 1;
    const int MAX_DAYS = 7;
    int shieldEnergy = 100; // Limited second resource metric
    int hydraInfluence = 0; // Tradeoff alternative pathway index
    string currentPosition = "S.H.I.E.L.D._Helicarrier";

    // Team Generation
    vector<Avenger> roster;
    roster.push_back(Avenger("Iron Man", 100, "Nano-Tech Overdrive", 50));
    roster.push_back(Avenger("Thor", 150, "God of Thunder Storm", 75));

    // Inventory Trackers (Core Item Collection metrics)
    vector<string> inventory;
    vector<string> finalBundle; 
    // Target bundle goals needed to clear the game framework
    const int TARGET_ITEMS_NEEDED = 3;

    // Load Maps and item nodes via File parsing engine
    vector<Mission> sectorMissions;
    ifstream fileIn("missions.txt");
    if (fileIn.is_open()) {
        string loc, item;
        int diff;
        while (fileIn >> loc >> diff >> item) {
            sectorMissions.push_back(Mission(loc, diff, item));
        }
        fileIn.close();
    }

    cout << "====================================================" << endl;
    cout << "          THE FINAL BUNDLE: MARVEL OPERATION        " << endl;
    cout << "====================================================" << endl;

    // Main Interactive Game Loop
    while (currentDay <= MAX_DAYS && shieldEnergy > 0 && finalBundle.size() < TARGET_ITEMS_NEEDED) {
        // Formatted Dashboards (Section 5 Requirement)
        cout << "\n====================================================" << endl;
        cout << "DAY: " << currentDay << " / " << MAX_DAYS 
             << " | SHIELD ENERGY: " << shieldEnergy << "%%"
             << " | HYDRA INFLUENCE: " << hydraInfluence << endl;
        cout << "CURRENT SECTOR LOCATION: " << currentPosition << endl;
        cout << "DEFENSE ARRAY BUNDLE PROGRESS: " << finalBundle.size() << " / " << TARGET_ITEMS_NEEDED << " items loaded." << endl;
        cout << "----------------------------------------------------" << endl;
        
        // Connected ASCII Location Map Layout (Section 6 Requirement)
        cout << "MAP SECTORS INTERACTION GRID:" << endl;
        cout << "  [Stark_Tower] ----- [Wakanda_Outpost]" << endl;
        cout << "        |                     |" << endl;
        cout << "  [Helicarrier*] ---- [Kamar_Taj]" << endl;
        cout << "  (* indicates local beacon array active)" << endl;
        cout << "----------------------------------------------------" << endl;

        cout << "MAIN CONTROL INTERACTION OPTIONS:" << endl;
        cout << "1. Travel to another sector (Costs 15 Energy)" << endl;
        cout << "2. Search sector for Tech Components (Costs 1 Day)" << endl;
        cout << "3. Secure Tech component into Final Defense Array Bundle" << endl;
        cout << "4. Use illegal Hydra Black-Market Override Shortcut" << endl;
        cout << "5. Show Inventory Logs" << endl;
        cout << "Enter Operational Command Option Index: ";
        
        int actionChoice;
        if (!(cin >> actionChoice)) {
            cin.clear();
            string junk;
            cin >> junk;
            cout << "\n[System Diagnostic Error]: Action Option Unrecognized." << endl;
            continue;
        }

        if (actionChoice == 1) {
            cout << "\nSelect navigation vector terminal sector destination:" << endl;
            for (size_t i = 0; i < sectorMissions.size(); i++) {
                cout << i + 1 << ". " << sectorMissions[i].getLocationName() << endl;
            }
            int moveChoice;
            cin >> moveChoice;
            if (moveChoice >= 1 && moveChoice <= (int)sectorMissions.size()) {
                currentPosition = sectorMissions[moveChoice - 1].getLocationName();
                shieldEnergy -= 15;
                cout << "Safe transit sequence verified. Current sector modified to: " << currentPosition << endl;
            } else {
                cout << "Navigation parameters out of range bounds." << endl;
            }
        }
        else if (actionChoice == 2) {
            // Find current mission sector profile rules matching player node location
            bool sectorFound = false;
            for (size_t i = 0; i < sectorMissions.size(); i++) {
                if (sectorMissions[i].getLocationName() == currentPosition) {
                    sectorFound = true;
                    cout << "\nAnalyzing local sector fields... Target signature located: " << sectorMissions[i].getRequiredItem() << endl;
                    cout << "Target defensive firewall difficulty: " << sectorMissions[i].getThreatDifficulty() << endl;
                    
                    // Choose an agent profile matrix block to verify core class interactions
                    cout << "Select deployment agent: \n1. Iron Man\n2. Thor" << endl;
                    int agentChoice;
                    cin >> agentChoice;
                    Avenger activeHero = roster[0];
                    if (agentChoice == 2) activeHero = roster[1];

                    if (activeHero.calculateMissionSuccess(sectorMissions[i].getThreatDifficulty())) {
                        cout << "Success! Item extracted successfully into field inventories." << endl;
                        inventory.push_back(sectorMissions[i].getRequiredItem());
                    } else {
                        cout << "Operation failure. Tactical capability metric insufficient. Shield core hit!" << endl;
                        shieldEnergy -= 20;
                    }
                    break;
                }
            }
            if (!sectorFound) {
                cout << "This neutral terminal holds no core structural tech components. Search elsewhere." << endl;
            }
            currentDay++; // Advance global time resource constraint limits
        }
        else if (actionChoice == 3) {
            if (inventory.empty()) {
                cout << "\nYour active field inventory containment is empty. Collect components first!" << endl;
            } else {
                cout << "\nSelect item entry index to patch into the main final bundle frame array:" << endl;
                for (size_t i = 0; i < inventory.size(); i++) {
                    cout << i << ": " << inventory[i] << endl;
                }
                int dropChoice;
                cin >> dropChoice;
                if (dropChoice >= 0 && dropChoice < (int)inventory.size()) {
                    finalBundle.push_back(inventory[dropChoice]);
                    cout << "Item: " << inventory[dropChoice] << " securely locked into final mission array cluster!" << endl;
                    inventory.erase(inventory.begin() + dropChoice);
                } else {
                    cout << "Invalid index reference." << endl;
                }
            }
        }
        else if (actionChoice == 4) {
            // Alternative Tradeoff system logic flow tracking metrics (Rubric Item #9)
            cout << "\n[ALERT]: Contacting proxy Hydra terminal brokers..." << endl;
            cout << "They offer to force-inject 1 Component directly into the final bundle array." << endl;
            cout << "Tradeoff Cost: Base Shield Energy drops by 30 points, and Hydra influence scaling increments by 1." << endl;
            cout << "Confirm transaction contract? (1 for Yes, 2 for No): ";
            int choiceHydra;
            cin >> choiceHydra;
            if (choiceHydra == 1) {
                finalBundle.push_back("Hydra_Proxy_Core");
                shieldEnergy -= 30;
                hydraInfluence += 1;
                cout << "Override successfully injected into defense matrix network stacks." << endl;
            } else {
                cout << "Transaction interface aborted safely by operator." << endl;
            }
        }
        else if (actionChoice == 5) {
            cout << "\n--- FIELD CAPACITOR CONTAINMENT LOGS ---" << endl;
            if (inventory.empty()) cout << "[Empty]" << endl;
            for (size_t i = 0; i < inventory.size(); i++) {
                cout << "- " << inventory[i] << endl;
            }
        }
    }

    // Win/Loss Branch Terminal Resolution Outputs Evaluator (Section 11 Requirement)
    cout << "\n====================================================" << endl;
    cout << "             OPERATION FINAL TERMINAL SUMMARY       " << endl;
    cout << "====================================================" << endl;
    
    if (finalBundle.size() >= TARGET_ITEMS_NEEDED) {
        if (hydraInfluence >= 2) {
            cout << "ENDING [Hydra Takeover Ending]: The planetary defense array is online, but Hydra proxies hijacked the sub-routines. You lose control." << endl;
        } else {
            cout << "ENDING [Community Hero Ending]: Planetary defense framework stabilized successfully! S.H.I.E.L.D. secures the sectors cleanly. Victory!" << endl;
        }
    } else if (shieldEnergy <= 0) {
        cout << "ENDING [System Critical Shutdown Loss]: Global tactical shields collapsed down to 0%. The operational matrix is completely broken. Mission Failed." << endl;
    } else {
        cout << "ENDING [Time Exhausted Loss]: You ran out of days before the complete final tech bundle assembly could finalize. Sector overrun imminent. Mission Failed." << endl;
    }
    
    return 0;
}