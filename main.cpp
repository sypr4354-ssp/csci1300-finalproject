#include <iostream>
#include <vector>
#include "Avenger.h"

using namespace std;

int main() {
    vector<Avenger> roster;
    roster.push_back(Avenger("Iron Man", 100, "Repulsor Blasts"));
    roster.push_back(Avenger("Thor", 150, "Lightning Strike"));

    int choice = 0;
    while (choice != 3) {
        cout << "=== S.H.I.E.L.D. HQ ===" << endl;
        cout << "1. View Active Avengers" << endl;
        cout << "2. Deploy Avenger" << endl;
        cout << "3. Exit Operation" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (size_t i = 0; i < roster.size(); i++) {
                cout << roster[i].getName() << " - HP: " << roster[i].getHealth() << endl;
            }
        } else if (choice == 2) {
            roster[0].useSpecialAbility();
        }
        cout << endl;
    }
    return 0;
}