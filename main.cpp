#include <iostream>
#include <vector>
#include <fstream> // Crucial addition for Checkpoint 3 file stream reading
#include "Avenger.h"

using namespace std;

int main() {
    // 1. Core Classes Implemented Beyond Stubs
    vector<Avenger> roster;
    roster.push_back(Avenger("Iron Man", 100, "Nano-Tech Repulsors", 90));
    roster.push_back(Avenger("Thor", 150, "Mjolnir Lightning Strike", 120));

    int choice = 0;
    
    // 2. Playable Game Loop and Main Menu
    while (choice != 4) {
        cout << "=== S.H.I.E.L.D. HQ (Phase 3 Command) ===" << endl;
        cout << "1. View Active Avengers Profiles" << endl;
        cout << "2. Load Mission Intel from File" << endl;
        cout << "3. Simulate Operational Threat Check" << endl;
        cout << "4. Abort Operation" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (size_t i = 0; i < roster.size(); i++) {
                cout << roster[i].getName() << " | HP: " << roster[i].getHealth() 
                     << " | Tactical Power: " << roster[i].getPowerLevel() << endl;
            }
        } 
        else if (choice == 2) {
            // 3. Mandatory Requirement: Read information from a file using ifstream
            ifstream fileIn("missions.txt");
            if (!fileIn.is_open()) {
                cout << "Error: Intelligence data file 'missions.txt' missing." << endl;
            } else {
                string missionName, riskLevel;
                int threatValue;
                cout << "\n--- Loading S.H.I.E.L.D. Threat Assessment Logs ---" << endl;
                while (fileIn >> missionName >> threatValue >> riskLevel) {
                    cout << "Threat Focus: " << missionName 
                         << " | Difficulty Rating: " << threatValue 
                         << " | Priority Rank: " << riskLevel << endl;
                }
                fileIn.close();
            }
        } 
        else if (choice == 3) {
            int threatRating;
            cout << "Enter a temporary threat level rating to calculate response viability: ";
            cin >> threatRating;
            
            if (roster[0].calculateMissionSuccess(threatRating)) {
                cout << "Outcome Matrix: " << roster[0].getName() << " can safely neutralize this threat alone." << endl;
            } else {
                cout << "Warning: Danger parameters exceed standalone agent threshold. Assistance required." << endl;
            }
        }
        cout << endl;
    }
    return 0;
}