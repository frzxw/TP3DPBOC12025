#include "include/ComputerSystem.h"
#include "include/machine.cpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    Date today(15, 3, 2025);

    vector<Computer *> computers;

    Computer *demoComputer = createDemoComputer(today);
    computers.push_back(demoComputer);

    bool running = true;
    while (running)
    {
        system("cls");

        displayHeader();
        displayMainMenu();

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            if (computers.empty())
            {
                cout << "[!] No computers available. Create one first.\n";
            }
            else
            {
                displayComputerTable(computers);
                system("pause");
            }
            break;
        case 2:
            if (computers.empty())
            {
                cout << "[!] No computers available. Create one first.\n";
            }
            else
            {
                int computerIndex;
                if (computers.size() == 1)
                {
                    cout << "Enter computer number to manage (1): ";
                }
                else
                {
                    cout << "Enter computer number to manage (1-" << computers.size() << "): ";
                }
                cin >> computerIndex;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (computerIndex >= 1 && computerIndex <= computers.size())
                {
                    manageComputer(computers[computerIndex - 1]);
                }
                else
                {
                    cout << "[!] Invalid computer number.\n";
                }
            }
            break;

        case 3:
            createNewComputer(computers);
            break;

        case 4:
            if (computers.empty())
            {
                cout << "[!] No computers available.\n";
            }
            else
            {
                int computerIndex;
                cout << "Enter computer number to delete (1-" << computers.size() << "): ";
                cin >> computerIndex;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (computerIndex >= 1 && computerIndex <= computers.size())
                {
                    Computer *comp = computers[computerIndex - 1];
                    cout << "[*] Deleting computer " << comp->getName() << "...\n";
                    delete comp;
                    computers.erase(computers.begin() + computerIndex - 1);
                    cout << "[-] Computer deleted successfully.\n";
                }
                else
                {
                    cout << "[!] Invalid computer number.\n";
                }
            }
            break;

        case 0:
            running = false;
            break;

        default:
            cout << "[!] Invalid choice.\n";
            break;
        }
    }
}