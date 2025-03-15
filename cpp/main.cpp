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
    computers.push_back(new Computer("PC-002", "Dell", "OptiPlex", 899.99, "Dell OptiPlex"));
    computers.push_back(new Computer("PC-003", "HP", "Pavilion", 799.99, "HP Pavilion"));
    computers.push_back(new Computer("PC-004", "Lenovo", "ThinkCentre", 999.99, "Lenovo ThinkCentre"));
    computers.push_back(new Computer("PC-005", "Apple", "iMac", 1299.99, "Apple iMac"));
    computers.push_back(new Computer("PC-006", "Asus", "ZenBook", 1099.99, "Asus ZenBook"));
    computers.push_back(new Computer("PC-007", "Acer", "Aspire", 699.99, "Acer Aspire"));
    computers.push_back(new Computer("PC-008", "Microsoft", "Surface", 1199.99, "Microsoft Surface"));
    computers.push_back(new Computer("PC-009", "Samsung", "Galaxy Book", 999.99, "Samsung Galaxy Book"));
    computers.push_back(new Computer("PC-010", "MSI", "Prestige", 1399.99, "MSI Prestige"));
    

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