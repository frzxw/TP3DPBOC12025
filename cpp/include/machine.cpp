#pragma once
#include "ComputerSystem.h"

using namespace std;

void displayMainMenu();
void displayComputerTable(const vector<Computer *> &computers);
void manageComputer(Computer *computer);
void manageSoftware(Computer *computer);
void addHardware(Computer *computer);
void removeHardware(Computer *computer);
void addHardwareToMotherboard(Motherboard *motherboard);
void removeHardwareFromMotherboard(Motherboard *motherboard);
void displayHardwareDetails(Computer *computer);
Computer *createDemoComputer(const Date &today);
void createNewComputer(vector<Computer *> &computers);
string centerText(const string &text, int width);
void drawHorizontalLine(const vector<int> &columnWidths, char left = '+', char mid = '+', char right = '+', char horizontal = '-');
void drawTableRow(const vector<string> &data, const vector<int> &columnWidths);
string truncateString(const string &str, size_t maxLength);
void displayHeader();

void displayHeader()
{
    cout << "+---------------------------------------------------------------------+\n";
    cout << "|                      COMPUTER MANAGEMENT SYSTEM                     |\n";
    cout << "|                         Professional Edition                        |\n";
    cout << "+---------------------------------------------------------------------+\n";
    cout << "| Author: Fariz Wibisono                                              |\n";
    cout << "| NIM: 2307589                                                        |\n";
    cout << "| Tugas Praktikum 3                                                   |\n";
    cout << "| Desain dan Pemrograman Berbasis Objek                               |\n";
    cout << "+---------------------------------------------------------------------+\n";
}

void displayMainMenu()
{
    cout << "\n 1. Show Computer\n";
    cout << " 2. Update Computer\n";
    cout << " 3. Create Computer\n";
    cout << " 4. Delete Computer\n";
    cout << " 0. Exit\n\n";
}

// Helper functions for table formatting
void drawHorizontalLine(const vector<int> &columnWidths, char left, char mid, char right, char horizontal)
{
    cout << left;

    for (size_t i = 0; i < columnWidths.size(); i++)
    {
        cout << string(columnWidths[i], horizontal);

        if (i < columnWidths.size() - 1)
        {
            cout << mid;
        }
    }

    cout << right << "\n";
}

void drawTableRow(const vector<string> &data, const vector<int> &columnWidths)
{
    cout << "|";

    for (size_t i = 0; i < columnWidths.size(); i++)
    {
        string cellData = (i < data.size()) ? data[i] : "";

        // If data is longer than column width, truncate it
        if (cellData.length() > static_cast<size_t>(columnWidths[i] - 2))
        {
            cellData = truncateString(cellData, columnWidths[i] - 2);
        }

        // Center the "No" column and power status
        if (i == 0 || i == columnWidths.size() - 1)
        {
            int padding = columnWidths[i] - cellData.length();
            int padLeft = padding / 2;
            int padRight = padding - padLeft;
            cout << string(padLeft, ' ') << cellData << string(padRight, ' ');
        }
        else
        {
            // Left align the rest of the data
            cout << " " << left << setw(columnWidths[i] - 2) << cellData << " ";
        }

        cout << "|";
    }

    cout << "\n";
}

string truncateString(const string &str, size_t maxLength)
{
    if (str.length() <= maxLength)
        return str;
    return str.substr(0, maxLength - 3) + "...";
}

string centerText(const string &text, int width)
{
    int padding = width - text.length();
    int padLeft = padding / 2;
    int padRight = padding - padLeft;
    return string(padLeft, ' ') + text + string(padRight, ' ');
}

void displayComputerTable(const vector<Computer *> &computers)
{
    if (computers.empty())
    {
        cout << "\n[!] No computers available.\n";
        return;
    }

    // Define column headers and minimum widths
    vector<string> headers = {"No", "Name", "Manufacturer", "Model", "CPU", "RAM", "Storage", "Power"};
    vector<int> columnWidths = {4, 15, 15, 15, 10, 10, 10, 8}; // Minimum widths

    // Calculate dynamic column widths based on content
    for (size_t i = 0; i < computers.size(); i++)
    {
        Computer *comp = computers[i];
        Motherboard *mobo = comp->getMotherboard();

        // Default values
        string cpuInfo = "None";
        string ramInfo = "0 GB";
        string storageInfo = "None";
        string powerInfo = "Off";

        // Get actual data if available
        if (mobo)
        {
            if (mobo->getCPU())
            {
                cpuInfo = mobo->getCPU()->getModel();
            }

            int ramTotal = 0;
            for (RAM *ram : mobo->getRamSlots())
            {
                ramTotal += ram->getCapacityGB();
            }
            ramInfo = to_string(ramTotal) + " GB";

            int storageTotal = 0;
            for (StorageDevice *storage : mobo->getStorageSlots())
            {
                storageTotal += storage->getCapacityGB();
            }
            storageInfo = to_string(storageTotal) + " GB";
        }

        if (comp->isPowered())
        {
            powerInfo = "On";
        }

        // Update column widths based on content
        columnWidths[0] = max(columnWidths[0], static_cast<int>(to_string(i + 1).length()));
        columnWidths[1] = max(columnWidths[1], static_cast<int>(comp->getName().length()));
        columnWidths[2] = max(columnWidths[2], static_cast<int>(comp->getManufacturer().length()));
        columnWidths[3] = max(columnWidths[3], static_cast<int>(comp->getModel().length()));
        columnWidths[4] = max(columnWidths[4], static_cast<int>(cpuInfo.length()));
        columnWidths[5] = max(columnWidths[5], static_cast<int>(ramInfo.length()));
        columnWidths[6] = max(columnWidths[6], static_cast<int>(storageInfo.length()));
        columnWidths[7] = max(columnWidths[7], static_cast<int>(powerInfo.length()));
    }

    // Make sure headers fit in the column widths
    for (size_t i = 0; i < headers.size(); i++)
    {
        columnWidths[i] = max(columnWidths[i], static_cast<int>(headers[i].length()));
    }

    // Add some padding
    for (size_t i = 0; i < columnWidths.size(); i++)
    {
        columnWidths[i] += 2;
    }

    cout << "\n";

    // Draw table header
    drawHorizontalLine(columnWidths);
    drawTableRow(headers, columnWidths);
    drawHorizontalLine(columnWidths);

    // Draw table content
    for (size_t i = 0; i < computers.size(); i++)
    {
        Computer *comp = computers[i];
        Motherboard *mobo = comp->getMotherboard();

        // Default values
        string cpuInfo = "None";
        string ramInfo = "0 GB";
        string storageInfo = "None";
        string powerInfo = "Off";

        // Get actual data if available
        if (mobo)
        {
            if (mobo->getCPU())
            {
                cpuInfo = mobo->getCPU()->getModel();
            }

            int ramTotal = 0;
            for (RAM *ram : mobo->getRamSlots())
            {
                ramTotal += ram->getCapacityGB();
            }
            ramInfo = to_string(ramTotal) + " GB";

            int storageTotal = 0;
            for (StorageDevice *storage : mobo->getStorageSlots())
            {
                storageTotal += storage->getCapacityGB();
            }
            storageInfo = to_string(storageTotal) + " GB";
        }

        if (comp->isPowered())
        {
            powerInfo = "On";
        }

        vector<string> rowData;
        rowData.push_back(to_string(i + 1));
        rowData.push_back(comp->getName());
        rowData.push_back(comp->getManufacturer());
        rowData.push_back(comp->getModel());
        rowData.push_back(cpuInfo);
        rowData.push_back(ramInfo);
        rowData.push_back(storageInfo);
        rowData.push_back(powerInfo);

        drawTableRow(rowData, columnWidths);
    }

    drawHorizontalLine(columnWidths);
    cout << "\n";
}

void manageComputer(Computer *computer)
{
    bool managing = true;
    while (managing)
    {
        system("cls");
        // system("clear"); // For Linux/Mac

        displayHeader();

        cout << "\nManaging Computer: " << left << setw(50) << computer->getName() << "\n";
        cout << "Status: " << (computer->isPowered() ? "Powered ON" : "Powered OFF") << "\n";

        cout << "\n1. Display Specifications\n";
        cout << "2. Power " << (computer->isPowered() ? "Off" : "On") << "\n";
        cout << "3. Add Hardware to Computer\n";
        cout << "4. Remove Hardware from Computer\n";
        cout << "5. Add Hardware to Motherboard\n";
        cout << "6. Remove Hardware from Motherboard\n";
        cout << "7. Software Management\n";
        cout << "8. Upgrade System\n";
        cout << "0. Back to Main Menu\n";

        int choice;
        cout << "\n-> Enter your choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            system("cls");
            displayHeader();
            computer->displaySpecifications();
            system("pause");
            break;

        case 2:
            if (computer->isPowered())
            {
                cout << "\n[*] Shutting down...\n";
                computer->shutdown();
                cout << "[+] Computer powered off successfully.\n";
            }
            else
            {
                cout << "\n[*] Booting up...\n";
                computer->boot();
                cout << "[+] Computer powered on successfully.\n";
            }
            system("pause");
            break;

        case 3:
            addHardware(computer);
            break;

        case 4:
            removeHardware(computer);
            break;

        case 5:
            if (computer->getMotherboard())
            {
                addHardwareToMotherboard(computer->getMotherboard());
            }
            else
            {
                cout << "\n[!] No motherboard installed. Please add a motherboard first.\n";
                system("pause");
            }
            break;

        case 6:
            if (computer->getMotherboard())
            {
                removeHardwareFromMotherboard(computer->getMotherboard());
            }
            else
            {
                cout << "\n[!] No motherboard installed. Please add a motherboard first.\n";
                system("pause");
            }
            break;

        case 7:
            // Software management
            break;

        case 8:
            if (computer->isPowered())
            {
                cout << "\n[!] Cannot upgrade while system is powered on.\n";
            }
            else
            {
                cout << "\n[*] Upgrading system...\n";
                computer->upgradeSystem();
                cout << "[+] System upgraded successfully.\n";
            }
            system("pause");
            break;

        case 0:
            managing = false;
            break;

        default:
            cout << "\n[!] Invalid choice.\n";
            system("pause");
            break;
        }
    }
}

void manageSoftware(Computer *computer)
{
    if (!computer->getOperatingSystem())
    {
        cout << "\n[!] No operating system installed. Please install an OS first.\n";
        system("pause");
        return;
    }

    bool managing = true;
    while (managing)
    {
        system("cls");
        displayHeader();

        cout << "\nManaging Computer: " << left << setw(50) << computer->getName() << "\n";
        cout << "Operating System: " << computer->getOperatingSystem()->getOsName() << " "
             << computer->getOperatingSystem()->getVersion() << "\n\n";

        cout << "1. Install Application\n";
        cout << "2. Uninstall Application\n";
        cout << "3. Install Driver\n";
        cout << "4. Uninstall Driver\n";
        cout << "5. Run Application\n";
        cout << "6. Close Application\n";
        cout << "7. List Installed Software\n";
        cout << "0. Back\n";

        int choice;
        cout << "\n-> Enter your choice: ";
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Date today(15, 3, 2025); // Default date

        switch (choice)
        {
        case 1: // Install Application
        {
            string appName, developer, version, supportedOS;
            double sizeMB;

            cout << "\nINSTALL APPLICATION\n";
            cout << "-> Enter application name: ";
            getline(cin, appName);

            cout << "-> Enter developer: ";
            getline(cin, developer);

            cout << "-> Enter version: ";
            getline(cin, version);

            cout << "-> Enter supported OS: ";
            getline(cin, supportedOS);

            cout << "-> Enter size (MB): ";
            cin >> sizeMB;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string licenseKey = "LICENSE-" + to_string(rand() % 10000);

            Application *app = new Application(appName, developer, supportedOS, version, licenseKey, sizeMB);
            computer->installSoftware(app);

            cout << "\n[+] Application installed successfully.\n";
            system("pause");
            break;
        }

        case 2: // Uninstall Application
        {
            // We need to get the installed applications from the computer
            // This is a placeholder since the shown Computer class doesn't expose the application list directly
            cout << "\n[!] Feature not fully implemented. The current Computer class doesn't provide direct access to the application list.\n";
            // In a complete implementation, you would:
            // 1. Get a list of installed applications
            // 2. Show them to the user
            // 3. Let the user select one to uninstall
            // 4. Call computer->uninstallSoftware(selectedApp)
            system("pause");
            break;
        }

        case 3: // Install Driver
        {
            string deviceName, driverVersion, supportedOS;
            bool isSigned;

            cout << "\nINSTALL DRIVER\n";
            cout << "-> Enter device name: ";
            getline(cin, deviceName);

            cout << "-> Enter driver version: ";
            getline(cin, driverVersion);

            cout << "-> Enter supported OS: ";
            getline(cin, supportedOS);

            cout << "-> Is signed (1=Yes, 0=No): ";
            cin >> isSigned;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            Driver *driver = new Driver(deviceName, driverVersion, supportedOS, isSigned);
            computer->installDriver(driver);

            cout << "\n[+] Driver installed successfully.\n";
            system("pause");
            break;
        }

        case 4: // Uninstall Driver
        {
            // Similar to uninstalling applications, we would need direct access to the drivers list
            cout << "\n[!] Feature not fully implemented. The current Computer class doesn't provide direct access to the driver list.\n";
            system("pause");
            break;
        }

        case 5: // Run Application
        {
            cout << "\n[!] Feature not fully implemented. The current Computer class doesn't provide direct access to the application list.\n";
            // In a complete implementation, you would:
            // 1. Get a list of installed applications
            // 2. Show them to the user
            // 3. Let the user select one to run
            // 4. Call computer->runApplication(selectedApp)

            // For demonstration, adding a mock implementation:
            if (!computer->isPowered())
            {
                cout << "\n[!] Computer is powered off. Please boot the system first.\n";
            }
            else
            {
                cout << "\n[*] Simulating running an application...\n";
                // Create a temporary application just for demonstration
                Application demoApp("Demo App", "Demo Developer", computer->getOperatingSystem()->getOsName(),
                                    "1.0", "DEMO-LICENSE", 100.0);
                computer->runApplication(&demoApp);
            }
            system("pause");
            break;
        }

        case 6: // Close Application
        {
            cout << "\n[!] Feature not fully implemented. The current Computer class doesn't provide direct access to running applications.\n";
            // Similar to running an app, but would call computer->closeApplication(selectedApp)
            system("pause");
            break;
        }

        case 7: // List Installed Software
        {
            system("cls");
            displayHeader();
            cout << "\nINSTALLED SOFTWARE - " << computer->getName() << "\n\n";

            // Display the info - we can access this through displaySpecifications
            if (computer->getBIOS())
            {
                cout << "BIOS: " << computer->getBIOS()->getManufacturer() << " version "
                     << computer->getBIOS()->getFirmwareVersion() << "\n";
            }

            if (computer->getOperatingSystem())
            {
                cout << "OS: " << computer->getOperatingSystem()->getOsName() << " "
                     << computer->getOperatingSystem()->getVersion()
                     << (computer->getOperatingSystem()->getIs64Bit() ? " (64-bit)" : " (32-bit)") << "\n";
            }

            // Note: Since we don't have direct access to the installed software lists,
            // we would ideally modify the Computer class to provide getter methods for these lists

            cout << "\n[i] To view all installed applications and drivers, use 'Display Specifications' from the main computer menu.\n";
            system("pause");
            break;
        }

        case 0:
            managing = false;
            break;

        default:
            cout << "\n[!] Invalid choice.\n";
            system("pause");
            break;
        }
    }
}

void addHardware(Computer *computer)
{
    system("cls");
    displayHeader();

    cout << "\nADD HARDWARE\n";
    cout << "1. Add Motherboard\n";
    cout << "2. Add Power Supply\n";
    cout << "3. Add Cooling System\n";
    cout << "4. Add Operating System\n";
    cout << "5. Add BIOS\n";
    cout << "6. Add Peripheral\n";
    cout << "0. Back\n";

    int choice;
    cout << "\n-> Enter your choice: ";
    cin >> choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Date today(15, 3, 2025); // Default installation date

    switch (choice)
    {
    case 1:
    {
        if (computer->getMotherboard())
        {
            cout << "\n[!] Motherboard already installed. Remove it first.\n";
            system("pause");
            return;
        }

        string manufacturer, model;

        cout << "Enter motherboard manufacturer: ";
        getline(cin, manufacturer);

        cout << "Enter motherboard model: ";
        getline(cin, model);

        Motherboard *mobo = new Motherboard(
            "MB-" + to_string(rand() % 1000),
            manufacturer, model, 299.99,
            "SN-MB-" + to_string(rand() % 10000),
            today, true, "Z690", "ATX", 4, 3, 6, true);

        computer->setMotherboard(mobo);
        cout << "\n[+] Motherboard installed successfully.\n";
        system("pause");
        break;
    }

    case 2:
    {
        if (computer->getPowerSupply())
        {
            cout << "\n[!] Power supply already installed. Remove it first.\n";
            system("pause");
            return;
        }

        int wattage;
        string certification, manufacturer, model;

        cout << "Enter power supply wattage: ";
        cin >> wattage;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter certification (e.g., 80+ Gold): ";
        getline(cin, certification);

        cout << "Enter manufacturer: ";
        getline(cin, manufacturer);

        cout << "Enter model: ";
        getline(cin, model);

        PowerSupply *psu = new PowerSupply(
            wattage, certification, true,
            "PSU-" + to_string(rand() % 1000),
            manufacturer, model, 124.99,
            "SN-PSU-" + to_string(rand() % 10000),
            today, true);

        computer->setPowerSupply(psu);
        cout << "\n[+] Power supply installed successfully.\n";
        system("pause");
        break;
    }

    case 3:
    {
        if (computer->getCooling())
        {
            cout << "\n[!] Cooling system already installed. Remove it first.\n";
            system("pause");
            return;
        }

        int coolingType;
        string manufacturer, model;
        int thermalDissipation;

        cout << "Select cooling type:\n";
        cout << "1. Air Cooling\n";
        cout << "2. Liquid Cooling\n";
        cout << "-> Choice: ";
        cin >> coolingType;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter manufacturer: ";
        getline(cin, manufacturer);

        cout << "Enter model: ";
        getline(cin, model);

        cout << "Enter max thermal dissipation (W): ";
        cin >> thermalDissipation;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Cooling *cooling;
        if (coolingType == 1)
        {
            int fanCount, fanSpeedRPM;
            cout << "Enter number of fans: ";
            cin >> fanCount;

            cout << "Enter fan speed (RPM): ";
            cin >> fanSpeedRPM;

            cooling = new AirCooling(
                "SN-COOL-" + to_string(rand() % 10000),
                today, true, thermalDissipation,
                "COOL-" + to_string(rand() % 1000),
                manufacturer, model, 89.99,
                fanCount, fanSpeedRPM);
        }
        else
        {
            double fluidVolume;
            string fluidType;
            bool hasPump;

            cout << "Enter fluid volume (ml): ";
            cin >> fluidVolume;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter fluid type: ";
            getline(cin, fluidType);

            cout << "Has pump (1=Yes, 0=No): ";
            cin >> hasPump;

            cooling = new LiquidCooling(
                "SN-COOL-" + to_string(rand() % 10000),
                today, true, thermalDissipation,
                "COOL-" + to_string(rand() % 1000),
                manufacturer, model, 149.99,
                fluidVolume, fluidType, hasPump);
        }

        computer->setCooling(cooling);
        cout << "\n[+] Cooling system installed successfully.\n";
        system("pause");
        break;
    }

    case 4:
    {
        if (computer->getOperatingSystem())
        {
            cout << "\n[!] Operating System already installed. Remove it first.\n";
            system("pause");
            return;
        }

        string osName, kernelVersion, licenseKey;
        bool is64Bit;
        double sizeMB;

        cout << "Enter OS name (e.g., Windows): ";
        getline(cin, osName);

        cout << "Enter version (e.g., 11): ";
        getline(cin, kernelVersion);

        cout << "Enter license key: ";
        getline(cin, licenseKey);

        cout << "Is 64-bit? (1=Yes, 0=No): ";
        cin >> is64Bit;

        cout << "Enter size (MB): ";
        cin >> sizeMB;

        OperatingSystem *os = new OperatingSystem(
            osName, kernelVersion, is64Bit,
            kernelVersion, licenseKey, sizeMB);

        computer->setOperatingSystem(os);
        cout << "\n[+] Operating System installed successfully.\n";
        system("pause");
        break;
    }

    case 5:
    {
        if (computer->getBIOS())
        {
            cout << "\n[!] BIOS already installed. Remove it first.\n";
            system("pause");
            return;
        }

        string manufacturer, version, supportedHardware;

        cout << "Enter BIOS manufacturer: ";
        getline(cin, manufacturer);

        cout << "Enter BIOS version: ";
        getline(cin, version);

        cout << "Enter supported hardware: ";
        getline(cin, supportedHardware);

        BIOS *bios = new BIOS(
            manufacturer, today,
            version, supportedHardware,
            today, true);

        computer->setBIOS(bios);
        cout << "\n[+] BIOS installed successfully.\n";
        system("pause");
        break;
    }

    case 6:
    {
        int peripheralType;
        string manufacturer, model, name, connectionType;
        bool wireless;

        cout << "Select peripheral type:\n";
        cout << "1. Monitor\n";
        cout << "2. Keyboard\n";
        cout << "3. Mouse\n";
        cout << "-> Choice: ";
        cin >> peripheralType;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter manufacturer: ";
        getline(cin, manufacturer);

        cout << "Enter model: ";
        getline(cin, model);

        cout << "Enter peripheral name: ";
        getline(cin, name);

        cout << "Enter connection type (e.g., USB, HDMI): ";
        getline(cin, connectionType);

        cout << "Is wireless? (1=Yes, 0=No): ";
        cin >> wireless;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Peripheral *peripheral;
        if (peripheralType == 1) // Monitor
        {
            double screenSize;
            int resWidth, resHeight, refreshRate;
            string panelType;

            cout << "Enter screen size (inches): ";
            cin >> screenSize;

            cout << "Enter resolution width: ";
            cin >> resWidth;

            cout << "Enter resolution height: ";
            cin >> resHeight;

            cout << "Enter refresh rate (Hz): ";
            cin >> refreshRate;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter panel type (e.g., IPS, VA): ";
            getline(cin, panelType);

            peripheral = new Monitor(
                screenSize, resWidth, resHeight, refreshRate, panelType,
                "SN-MON-" + to_string(rand() % 10000),
                today, true, connectionType, wireless, name,
                "MON-" + to_string(rand() % 1000),
                manufacturer, model, 249.99);
        }
        else if (peripheralType == 2) // Keyboard
        {
            bool mechanical, hasBacklight;
            string layoutType;

            cout << "Is mechanical? (1=Yes, 0=No): ";
            cin >> mechanical;

            cout << "Has backlight? (1=Yes, 0=No): ";
            cin >> hasBacklight;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter layout type (e.g., QWERTY): ";
            getline(cin, layoutType);

            peripheral = new Keyboard(
                mechanical, layoutType, hasBacklight,
                "SN-KB-" + to_string(rand() % 10000),
                today, true, connectionType, wireless, name,
                "KB-" + to_string(rand() % 1000),
                manufacturer, model, 79.99);
        }
        else if (peripheralType == 3) // Mouse
        {
            int buttonCount, dpi;
            bool hasScrollWheel;

            cout << "Enter button count: ";
            cin >> buttonCount;

            cout << "Enter DPI: ";
            cin >> dpi;

            cout << "Has scroll wheel? (1=Yes, 0=No): ";
            cin >> hasScrollWheel;

            peripheral = new Mouse(
                buttonCount, hasScrollWheel, dpi,
                "SN-MOUSE-" + to_string(rand() % 10000),
                today, true, connectionType, wireless, name,
                "MOUSE-" + to_string(rand() % 1000),
                manufacturer, model, 49.99);
        }
        else
        {
            cout << "\n[!] Invalid peripheral type.\n";
            system("pause");
            break;
        }

        computer->addPeripheral(peripheral);
        cout << "\n[+] Peripheral added successfully.\n";
        system("pause");
        break;
    }

    case 0:
        return;

    default:
        cout << "\n[!] Invalid choice.\n";
        system("pause");
        break;
    }
}

void removeHardware(Computer *computer)
{
    system("cls");
    displayHeader();

    cout << "\nREMOVE HARDWARE\n";
    cout << "1. Remove Motherboard\n";
    cout << "2. Remove Power Supply\n";
    cout << "3. Remove Cooling System\n";
    cout << "4. Remove Operating System\n";
    cout << "5. Remove BIOS\n";
    cout << "6. Remove Peripheral\n";
    cout << "0. Back\n";

    int choice;
    cout << "\n-> Enter your choice: ";
    cin >> choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice)
    {
    case 1:
    {
        if (!computer->getMotherboard())
        {
            cout << "\n[!] No motherboard installed.\n";
            system("pause");
            return;
        }

        // Don't allow removing motherboard if computer is powered on
        if (computer->isPowered())
        {
            cout << "\n[!] Cannot remove motherboard while computer is powered on. Shut down first.\n";
            system("pause");
            return;
        }

        // Confirm removal
        char confirm;
        cout << "\n[!] Removing the motherboard will also remove all attached hardwares (CPU, RAM, etc.).\n";
        cout << "Are you sure you want to proceed? (y/n): ";
        cin >> confirm;

        if (tolower(confirm) != 'y')
        {
            cout << "\nOperation cancelled.\n";
            system("pause");
            return;
        }

        computer->setMotherboard(nullptr);
        cout << "\n[-] Motherboard removed successfully.\n";
        system("pause");
        break;
    }

    case 2:
    {
        if (!computer->getPowerSupply())
        {
            cout << "\n[!] No power supply installed.\n";
            system("pause");
            return;
        }

        // Don't allow removing power supply if computer is powered on
        if (computer->isPowered())
        {
            cout << "\n[!] Cannot remove power supply while computer is powered on. Shut down first.\n";
            system("pause");
            return;
        }

        computer->setPowerSupply(nullptr);
        cout << "\n[-] Power supply removed successfully.\n";
        system("pause");
        break;
    }

    case 3:
    {
        if (!computer->getCooling())
        {
            cout << "\n[!] No cooling system installed.\n";
            system("pause");
            return;
        }

        // Don't allow removing cooling if computer is powered on
        if (computer->isPowered())
        {
            cout << "\n[!] Cannot remove cooling system while computer is powered on. Shut down first.\n";
            system("pause");
            return;
        }

        computer->setCooling(nullptr);
        cout << "\n[-] Cooling system removed successfully.\n";
        system("pause");
        break;
    }

    case 4:
    {
        if (!computer->getOperatingSystem())
        {
            cout << "\n[!] No operating system installed.\n";
            system("pause");
            return;
        }

        // Don't allow removing OS if computer is powered on
        if (computer->isPowered())
        {
            cout << "\n[!] Cannot remove operating system while computer is powered on. Shut down first.\n";
            system("pause");
            return;
        }

        computer->setOperatingSystem(nullptr);
        cout << "\n[-] Operating System removed successfully.\n";
        system("pause");
        break;
    }

    case 5:
    {
        if (!computer->getBIOS())
        {
            cout << "\n[!] No BIOS installed.\n";
            system("pause");
            return;
        }

        // Don't allow removing BIOS if computer is powered on
        if (computer->isPowered())
        {
            cout << "\n[!] Cannot remove BIOS while computer is powered on. Shut down first.\n";
            system("pause");
            return;
        }

        computer->setBIOS(nullptr);
        cout << "\n[-] BIOS removed successfully.\n";
        system("pause");
        break;
    }

    case 6:
    {
        vector<Peripheral *> peripherals;
        // Need to get the peripherals from the computer - assuming there's a method

        if (peripherals.empty())
        {
            cout << "\n[!] No peripherals installed.\n";
            system("pause");
            return;
        }

        cout << "\nInstalled peripherals:\n";
        for (size_t i = 0; i < peripherals.size(); i++)
        {
            cout << (i + 1) << ". " << peripherals[i]->getManufacturer() << " "
                 << peripherals[i]->getModel() << " (" << peripherals[i]->getName() << ")\n";
        }

        int peripheralIndex;
        cout << "\nSelect peripheral to remove (1-" << peripherals.size() << ") or 0 to cancel: ";
        cin >> peripheralIndex;

        if (peripheralIndex < 1 || peripheralIndex > peripherals.size())
        {
            cout << "\nOperation cancelled.\n";
            system("pause");
            return;
        }

        computer->removePeripheral(peripherals[peripheralIndex - 1]);
        cout << "\n[-] Peripheral removed successfully.\n";
        system("pause");
        break;
    }

    case 0:
        return;

    default:
        cout << "\n[!] Invalid choice.\n";
        system("pause");
        break;
    }
}

void addHardwareToMotherboard(Motherboard *motherboard)
{
    system("cls");
    displayHeader();

    cout << "\nADD HARDWARE TO MOTHERBOARD\n";
    cout << "1. Add CPU\n";
    cout << "2. Add RAM\n";
    cout << "3. Add Graphics Card\n";
    cout << "4. Add Storage Device\n";
    cout << "5. Add Network Card\n";
    cout << "6. Add Sound Card\n";
    cout << "0. Back\n";

    int choice;
    cout << "\n-> Enter your choice: ";
    cin >> choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Date today(15, 3, 2025); // Default installation date

    switch (choice)
    {
    case 1:
    {
        if (motherboard->getCPU())
        {
            cout << "\n[!] CPU already installed. Remove it first.\n";
            system("pause");
            return;
        }

        string manufacturer, model, socket;
        double clockSpeed;
        int cores, threads;

        cout << "-> Enter CPU manufacturer: ";
        getline(cin, manufacturer);

        cout << "-> Enter CPU model: ";
        getline(cin, model);

        cout << "-> Enter socket type: ";
        getline(cin, socket);

        cout << "-> Enter clock speed (GHz): ";
        cin >> clockSpeed;

        cout << "-> Enter number of cores: ";
        cin >> cores;

        cout << "-> Enter number of threads: ";
        cin >> threads;

        CPU *cpu = new CPU(
            "SN-CPU-" + to_string(rand() % 10000),
            today, true, clockSpeed, cores, threads,
            "x64", 16.0, true,
            "CPU-" + to_string(rand() % 1000),
            manufacturer, model, 350.99, socket);

        motherboard->installCPU(cpu);
        cout << "\n[+] CPU installed successfully.\n";
        system("pause");
        break;
    }

    case 2:
    {
        if (motherboard->getRamSlots().size() >= motherboard->getRamSlotsCount())
        {
            cout << "\n[!] All RAM slots are occupied.\n";
            system("pause");
            return;
        }

        string manufacturer, model, type;
        int capacity, speed;

        cout << "-> Enter RAM manufacturer: ";
        getline(cin, manufacturer);

        cout << "-> Enter RAM model: ";
        getline(cin, model);

        cout << "-> Enter RAM type (e.g., DDR4): ";
        getline(cin, type);

        cout << "-> Enter capacity (GB): ";
        cin >> capacity;

        cout << "-> Enter speed (MHz): ";
        cin >> speed;

        RAM *ram = new RAM(
            capacity, type, speed, false,
            "SN-RAM-" + to_string(rand() % 10000),
            today, true,
            "RAM-" + to_string(rand() % 1000),
            manufacturer, model, 79.99);

        motherboard->installRAM(ram);
        cout << "\n[+] RAM installed successfully.\n";
        system("pause");
        break;
    }

    case 3:
    {
        if (motherboard->getExpansionSlots().size() >= motherboard->getPcieSlotsCount())
        {
            cout << "\n[!] All expansion slots are occupied.\n";
            system("pause");
            return;
        }

        string manufacturer, model, chipset;
        int vramGB;

        cout << "-> Enter GPU manufacturer: ";
        getline(cin, manufacturer);

        cout << "-> Enter GPU model: ";
        getline(cin, model);

        cout << "-> Enter chipset (e.g., RTX 3080): ";
        getline(cin, chipset);

        cout << "-> Enter VRAM capacity (GB): ";
        cin >> vramGB;

        GraphicsCard *gpu = new GraphicsCard(
            vramGB, chipset, 5888, 3, 1,
            "PCIe 4.0",
            "SN-GPU-" + to_string(rand() % 10000),
            today, true,
            "GPU-" + to_string(rand() % 1000),
            manufacturer, model, 499.99);

        motherboard->installExpansionCard(gpu);
        cout << "\n[+] Graphics card installed successfully.\n";
        system("pause");
        break;
    }

    case 4:
    {
        if (motherboard->getStorageSlots().size() >= motherboard->getSataPortsCount())
        {
            cout << "\n[!] All storage slots are occupied.\n";
            system("pause");
            return;
        }

        string manufacturer, model;
        int capacity;
        int storageType;

        cout << "-> Select storage type:\n";
        cout << "  1. SSD\n";
        cout << "  2. HDD\n";
        cout << "-> Choice: ";
        cin >> storageType;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "-> Enter manufacturer: ";
        getline(cin, manufacturer);

        cout << "-> Enter model: ";
        getline(cin, model);

        cout << "-> Enter capacity (GB): ";
        cin >> capacity;

        StorageDevice *storage;
        if (storageType == 1)
        {
            storage = new SSD(
                "SN-SSD-" + to_string(rand() % 10000),
                today, true, capacity, 7000, 5000,
                "SSD-" + to_string(rand() % 1000),
                manufacturer, model, 149.99,
                "TLC", 600);
        }
        else
        {
            storage = new HDD(
                "SN-HDD-" + to_string(rand() % 10000),
                today, true, capacity, 150, 150,
                7200, 2,
                "HDD-" + to_string(rand() % 1000),
                manufacturer, model, 89.99);
        }

        motherboard->installStorage(storage);
        cout << "\n[+] Storage device installed successfully.\n";
        system("pause");
        break;
    }

    case 5:
    {
        if (motherboard->getExpansionSlots().size() >= motherboard->getPcieSlotsCount())
        {
            cout << "\n[!] All expansion slots are occupied.\n";
            system("pause");
            return;
        }

        string manufacturer, model, macAddress;
        int speed;

        cout << "-> Enter network card manufacturer: ";
        getline(cin, manufacturer);

        cout << "-> Enter network card model: ";
        getline(cin, model);

        cout << "-> Enter MAC address: ";
        getline(cin, macAddress);

        cout << "-> Enter speed (Mbps): ";
        cin >> speed;

        NetworkCard *networkCard = new NetworkCard(
            "PCIe 3.0",
            "SN-NIC-" + to_string(rand() % 10000),
            today, true,
            "NIC-" + to_string(rand() % 1000),
            manufacturer, model, 49.99,
            macAddress, speed, false, false);

        motherboard->installExpansionCard(networkCard);
        cout << "\n[+] Network card installed successfully.\n";
        system("pause");
        break;
    }

    case 6:
    {
        if (motherboard->getExpansionSlots().size() >= motherboard->getPcieSlotsCount())
        {
            cout << "\n[!] All expansion slots are occupied.\n";
            system("pause");
            return;
        }

        string manufacturer, model, macAddress;
        int speed;

        cout << "-> Enter network card manufacturer: ";
        getline(cin, manufacturer);

        cout << "-> Enter network card model: ";
        getline(cin, model);

        cout << "-> Enter MAC address: ";
        getline(cin, macAddress);

        cout << "-> Enter speed (Mbps): ";
        cin >> speed;

        NetworkCard *networkCard = new NetworkCard(
            "PCIe 3.0",
            "SN-NIC-" + to_string(rand() % 10000),
            today, true,
            "NIC-" + to_string(rand() % 1000),
            manufacturer, model, 49.99,
            macAddress, speed, false, false);

        motherboard->installExpansionCard(networkCard);
        cout << "\n[+] Network card installed successfully.\n";
        system("pause");
        break;
    }

    case 0:
        return;

    default:
        cout << "\n[!] Invalid choice.\n";
        system("pause");
        break;
    }
}

void removeHardwareFromMotherboard(Motherboard *motherboard)
{
    system("cls");
    displayHeader();

    cout << "\nREMOVE HARDWARE FROM MOTHERBOARD\n";
    cout << "1. Remove CPU\n";
    cout << "2. Remove RAM\n";
    cout << "3. Remove Graphics Card\n";
    cout << "4. Remove Storage Device\n";
    cout << "5. Remove Network Card\n";
    cout << "6. Remove Sound Card\n";
    cout << "0. Back\n";

    int choice;
    cout << "\n-> Enter your choice: ";
    cin >> choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice)
    {
    case 1:
    {
        if (!motherboard->getCPU())
        {
            cout << "\n[!] No CPU installed.\n";
            system("pause");
            return;
        }

        CPU *cpu = motherboard->getCPU();
        cout << "\nCurrently installed CPU: " << cpu->getManufacturer() << " " << cpu->getModel() << "\n";

        char confirm;
        cout << "Are you sure you want to remove this CPU? (y/n): ";
        cin >> confirm;

        if (tolower(confirm) == 'y')
        {
            motherboard->removeCPU();
            cout << "\n[-] CPU removed successfully.\n";
        }
        else
        {
            cout << "\nOperation cancelled.\n";
        }
        system("pause");
        break;
    }

    case 2:
    {
        vector<RAM *> ramSlots = motherboard->getRamSlots();

        if (ramSlots.empty())
        {
            cout << "\n[!] No RAM modules installed.\n";
            system("pause");
            return;
        }

        cout << "\nInstalled RAM modules:\n";
        for (size_t i = 0; i < ramSlots.size(); i++)
        {
            cout << (i + 1) << ". " << ramSlots[i]->getCapacityGB() << "GB "
                 << ramSlots[i]->getManufacturer() << " " << ramSlots[i]->getModel()
                 << " (" << ramSlots[i]->getType() << " @ " << ramSlots[i]->getSpeedMHz() << "MHz)\n";
        }

        int ramIndex;
        cout << "\nSelect RAM module to remove (1-" << ramSlots.size() << ") or 0 to cancel: ";
        cin >> ramIndex;

        if (ramIndex < 1 || ramIndex > ramSlots.size())
        {
            cout << "\nOperation cancelled.\n";
            system("pause");
            return;
        }

        motherboard->removeRAM(ramSlots[ramIndex - 1]);
        cout << "\n[-] RAM module removed successfully.\n";
        system("pause");
        break;
    }

    case 3:
    {
        if (!motherboard->getGPU())
        {
            cout << "\n[!] No graphics card installed.\n";
            system("pause");
            return;
        }

        GraphicsCard *gpu = motherboard->getGPU();
        cout << "\nCurrently installed GPU: " << gpu->getManufacturer() << " "
             << gpu->getModel() << " (" << gpu->getGpuModel() << ", " << gpu->getVramGB() << "GB VRAM)\n";

        char confirm;
        cout << "Are you sure you want to remove this graphics card? (y/n): ";
        cin >> confirm;

        if (tolower(confirm) == 'y')
        {
            motherboard->removeExpansionCard(gpu);
            cout << "\n[-] Graphics card removed successfully.\n";
        }
        else
        {
            cout << "\nOperation cancelled.\n";
        }
        system("pause");
        break;
    }

    case 4:
    {
        vector<StorageDevice *> storageSlots = motherboard->getStorageSlots();

        if (storageSlots.empty())
        {
            cout << "\n[!] No storage devices installed.\n";
            system("pause");
            return;
        }

        cout << "\nInstalled storage devices:\n";
        for (size_t i = 0; i < storageSlots.size(); i++)
        {
            string deviceType = "Storage Device";
            if (dynamic_cast<SSD *>(storageSlots[i]))
                deviceType = "SSD";
            else if (dynamic_cast<HDD *>(storageSlots[i]))
                deviceType = "HDD";

            cout << (i + 1) << ". " << deviceType << ": " << storageSlots[i]->getManufacturer() << " "
                 << storageSlots[i]->getModel() << " (" << storageSlots[i]->getCapacityGB() << "GB)\n";
        }

        int storageIndex;
        cout << "\nSelect storage device to remove (1-" << storageSlots.size() << ") or 0 to cancel: ";
        cin >> storageIndex;

        if (storageIndex < 1 || storageIndex > storageSlots.size())
        {
            cout << "\nOperation cancelled.\n";
            system("pause");
            return;
        }

        motherboard->removeStorage(storageSlots[storageIndex - 1]);
        cout << "\n[-] Storage device removed successfully.\n";
        system("pause");
        break;
    }

    case 5:
    {
        if (!motherboard->getNetworkCard())
        {
            cout << "\n[!] No network card installed.\n";
            system("pause");
            return;
        }

        NetworkCard *networkCard = motherboard->getNetworkCard();
        cout << "\nCurrently installed network card: " << networkCard->getManufacturer() << " "
             << networkCard->getModel() << " (" << networkCard->getMaxSpeedMbps() << " Mbps)\n";

        char confirm;
        cout << "Are you sure you want to remove this network card? (y/n): ";
        cin >> confirm;

        if (tolower(confirm) == 'y')
        {
            motherboard->removeExpansionCard(networkCard);
            cout << "\n[-] Network card removed successfully.\n";
        }
        else
        {
            cout << "\nOperation cancelled.\n";
        }
        system("pause");
        break;
    }

    case 6:
    {
        if (!motherboard->getSoundCard())
        {
            cout << "\n[!] No sound card installed.\n";
            system("pause");
            return;
        }

        SoundCard *soundCard = motherboard->getSoundCard();
        cout << "\nCurrently installed sound card: " << soundCard->getManufacturer() << " "
             << soundCard->getModel() << "\n";

        char confirm;
        cout << "Are you sure you want to remove this sound card? (y/n): ";
        cin >> confirm;

        if (tolower(confirm) == 'y')
        {
            motherboard->removeExpansionCard(soundCard);
            cout << "\n[-] Sound card removed successfully.\n";
        }
        else
        {
            cout << "\nOperation cancelled.\n";
        }
        system("pause");
        break;
    }

    case 0:
        return;

    default:
        cout << "\n[!] Invalid choice.\n";
        system("pause");
        break;
    }
}

void createNewComputer(vector<Computer *> &computers)
{
    system("cls");
    displayHeader();

    string name, manufacturer, model;
    double price;

    cout << "-> Enter computer name: ";
    getline(cin, name);

    cout << "-> Enter manufacturer: ";
    getline(cin, manufacturer);

    cout << "-> Enter model: ";
    getline(cin, model);

    cout << "-> Enter price: ";
    cin >> price;

    string id = "PC-" + to_string(rand() % 1000);
    Computer *newComputer = new Computer(id, manufacturer, model, price, name);
    computers.push_back(newComputer);

    cout << "\n[+] Computer created successfully.\n";
    system("pause");
}

// Function to create a demo computer
Computer *createDemoComputer(const Date &today)
{
    // Create CPU
    CPU *cpu = new CPU("SN-CPU-1234", today, true, 4.2, 8, 16,
                       "x64", 16.0, true, "CPU-001", "Intel",
                       "Core i7-12700K", 350.99, "LGA1700");

    // Create RAM modules
    RAM *ram1 = new RAM(16, "DDR4", 3600, false, "SN-RAM-001", today,
                        true, "RAM-001", "Corsair", "Vengeance LPX", 79.99);

    // Create GPU
    GraphicsCard *gpu = new GraphicsCard(8, "RTX 3070", 5888, 3, 1,
                                         "PCIe 4.0", "SN-GPU-001", today,
                                         true, "GPU-001", "NVIDIA", "GeForce RTX 3070", 499.99);

    // Create Storage
    SSD *ssd = new SSD("SN-SSD-001", today, true, 1000, 7000, 5000,
                       "SSD-001", "Samsung", "970 EVO Plus", 149.99,
                       "TLC", 600);

    // Create Cooling
    AirCooling *cooling = new AirCooling("SN-COOL-001", today, true, 150,
                                         "COOL-001", "Noctua", "NH-D15", 89.99,
                                         2, 1500);

    // Create Power Supply
    PowerSupply *psu = new PowerSupply(750, "80+ Gold", true, "PSU-001",
                                       "Corsair", "RM750x", 124.99,
                                       "SN-PSU-001", today, true);

    // Create Motherboard
    Motherboard *mobo = new Motherboard("MB-001", "ASUS", "ROG Strix Z690-A", 299.99,
                                        "SN-MB-001", today, true, "Z690", "ATX",
                                        4, 3, 6, true);

    // Create BIOS
    BIOS *bios = new BIOS("ASUS", today, "F11", "Z690", today, true);

    // Create OS
    OperatingSystem *os = new OperatingSystem("Windows", "11", true, "22H2",
                                              "XXXXX-XXXXX-XXXXX-XXXXX", 16000.0);

    // Create Computer
    Computer *computer = new Computer("PC-001", "Custom Build", "Gaming Desktop", 1599.99, "Gaming PC");

    // Set main components
    computer->setMotherboard(mobo);
    computer->setPowerSupply(psu);
    computer->setCooling(cooling);
    computer->setBIOS(bios);
    computer->setOperatingSystem(os);

    // Install components to motherboard
    mobo->installCPU(cpu);
    mobo->installRAM(ram1);
    mobo->installExpansionCard(gpu);
    mobo->installStorage(ssd);

    return computer;
}