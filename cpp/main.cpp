#include "include/ComputerSystem.h"
#include "include/machine.cpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    Date today(15, 3, 2025);

    // Create computers
    vector<Computer *> computers;
    computers.push_back(new Computer("PC-002", "Dell", "OptiPlex", 899.99, "Dell OptiPlex"));
    computers.push_back(new Computer("PC-003", "HP", "Pavilion", 799.99, "HP Pavilion"));
    computers.push_back(new Computer("PC-004", "Lenovo", "ThinkCentre", 999.99, "Lenovo ThinkCentre"));
    computers.push_back(new Computer("PC-005", "Apple", "iMac", 1299.99, "Apple iMac"));
    computers.push_back(new Computer("PC-006", "Asus", "ZenBook", 1099.99, "Asus ZenBook"));
    computers.push_back(new Computer("PC-007", "Acer", "Aspire", 699.99, "Acer Aspire"));
    computers.push_back(new Computer("PC-008", "Microsoft", "Surface", 1199.99, "Microsoft Surface"));
    computers.push_back(new Computer("PC-009", "Samsung", "Galaxy Book", 999.99, "Samsung Galaxy Book"));
    computers.push_back(new Computer("PC-010", "MSI", "Prestige", 1399.99, "MSI Prestige"));
    computers.push_back(new Computer("PC-011", "Alienware", "Aurora R11", 1499.99, "Alienware Aurora R11"));

    // Create CPUs and install to each computer
    vector<CPU *> cpus;
    cpus.push_back(new CPU("SN-CPU-001", today, true, 3.6, 6, 12, "x64", 12.0, true, "CPU-001", "Intel", "Core i5-10400F", 150.99, "LGA1200"));
    cpus.push_back(new CPU("SN-CPU-002", today, true, 3.8, 8, 16, "x64", 16.0, true, "CPU-002", "AMD", "Ryzen 7 3700X", 329.99, "AM4"));
    cpus.push_back(new CPU("SN-CPU-003", today, true, 4.0, 8, 16, "x64", 16.0, true, "CPU-003", "Intel", "Core i7-10700K", 374.99, "LGA1200"));
    cpus.push_back(new CPU("SN-CPU-004", today, true, 3.7, 6, 12, "x64", 12.0, true, "CPU-004", "AMD", "Ryzen 5 3600", 199.99, "AM4"));
    cpus.push_back(new CPU("SN-CPU-005", today, true, 3.9, 12, 24, "x64", 24.0, true, "CPU-005", "AMD", "Ryzen 9 3900X", 499.99, "AM4"));
    cpus.push_back(new CPU("SN-CPU-006", today, true, 4.2, 8, 16, "x64", 16.0, true, "CPU-006", "Intel", "Core i7-11700K", 399.99, "LGA1200"));
    cpus.push_back(new CPU("SN-CPU-007", today, true, 3.5, 4, 8, "x64", 8.0, true, "CPU-007", "Intel", "Core i3-10100", 119.99, "LGA1200"));
    cpus.push_back(new CPU("SN-CPU-008", today, true, 3.6, 6, 12, "x64", 12.0, true, "CPU-008", "AMD", "Ryzen 5 5600X", 299.99, "AM4"));
    cpus.push_back(new CPU("SN-CPU-009", today, true, 3.8, 8, 16, "x64", 16.0, true, "CPU-009", "Intel", "Core i7-9700K", 349.99, "LGA1151"));
    cpus.push_back(new CPU("SN-CPU-010", today, true, 4.2, 8, 16, "x64", 16.0, true, "CPU-010", "Intel", "Core i7-12700K", 350.99, "LGA1700"));

    // Create RAM modules
    vector<RAM *> rams;
    rams.push_back(new RAM(16, "DDR4", 3600, false, "SN-RAM-001", today, true, "RAM-001", "Corsair", "Vengeance LPX", 79.99));
    rams.push_back(new RAM(32, "DDR4", 3200, false, "SN-RAM-002", today, true, "RAM-002", "G.Skill", "Trident Z", 149.99));
    rams.push_back(new RAM(8, "DDR4", 3000, false, "SN-RAM-003", today, true, "RAM-003", "Kingston", "HyperX Fury", 49.99));
    rams.push_back(new RAM(16, "DDR4", 3200, false, "SN-RAM-004", today, true, "RAM-004", "Crucial", "Ballistix", 74.99));
    rams.push_back(new RAM(16, "DDR4", 3600, false, "SN-RAM-005", today, true, "RAM-005", "TeamGroup", "T-Force Delta", 84.99));
    rams.push_back(new RAM(32, "DDR4", 3600, false, "SN-RAM-006", today, true, "RAM-006", "Patriot", "Viper Steel", 159.99));
    rams.push_back(new RAM(8, "DDR4", 2666, false, "SN-RAM-007", today, true, "RAM-007", "ADATA", "XPG Z1", 39.99));
    rams.push_back(new RAM(16, "DDR4", 3000, false, "SN-RAM-008", today, true, "RAM-008", "GeIL", "EVO POTENZA", 69.99));
    rams.push_back(new RAM(32, "DDR4", 3200, false, "SN-RAM-009", today, true, "RAM-009", "Silicon Power", "XPOWER Turbine", 139.99));
    rams.push_back(new RAM(16, "DDR4", 3600, false, "SN-RAM-010", today, true, "RAM-010", "Mushkin", "Redline", 89.99));

    // Create GPUs
    vector<GraphicsCard *> gpus;
    gpus.push_back(new GraphicsCard(8, "RTX 3070", 5888, 3, 1, "PCIe 4.0", "SN-GPU-001", today, true, "GPU-001", "NVIDIA", "GeForce RTX 3070", 499.99));
    gpus.push_back(new GraphicsCard(10, "RTX 3080", 8704, 3, 1, "PCIe 4.0", "SN-GPU-002", today, true, "GPU-002", "NVIDIA", "GeForce RTX 3080", 699.99));
    gpus.push_back(new GraphicsCard(24, "RTX 3090", 10496, 3, 1, "PCIe 4.0", "SN-GPU-003", today, true, "GPU-003", "NVIDIA", "GeForce RTX 3090", 1499.99));
    gpus.push_back(new GraphicsCard(8, "RX 6800 XT", 4608, 3, 1, "PCIe 4.0", "SN-GPU-004", today, true, "GPU-004", "AMD", "Radeon RX 6800 XT", 649.99));
    gpus.push_back(new GraphicsCard(16, "RX 6900 XT", 5120, 3, 1, "PCIe 4.0", "SN-GPU-005", today, true, "GPU-005", "AMD", "Radeon RX 6900 XT", 999.99));
    gpus.push_back(new GraphicsCard(12, "RTX 3060", 3584, 3, 1, "PCIe 4.0", "SN-GPU-006", today, true, "GPU-006", "NVIDIA", "GeForce RTX 3060", 329.99));
    gpus.push_back(new GraphicsCard(8, "RTX 2060", 1920, 3, 1, "PCIe 3.0", "SN-GPU-007", today, true, "GPU-007", "NVIDIA", "GeForce RTX 2060", 349.99));
    gpus.push_back(new GraphicsCard(6, "GTX 1660 Ti", 1536, 3, 1, "PCIe 3.0", "SN-GPU-008", today, true, "GPU-008", "NVIDIA", "GeForce GTX 1660 Ti", 279.99));
    gpus.push_back(new GraphicsCard(8, "RX 5700 XT", 2560, 3, 1, "PCIe 4.0", "SN-GPU-009", today, true, "GPU-009", "AMD", "Radeon RX 5700 XT", 399.99));
    gpus.push_back(new GraphicsCard(4, "GTX 1650", 896, 3, 1, "PCIe 3.0", "SN-GPU-010", today, true, "GPU-010", "NVIDIA", "GeForce GTX 1650", 149.99));

    // Create Storage
    vector<SSD *> ssds;
    ssds.push_back(new SSD("SN-SSD-001", today, true, 1000, 7000, 5000, "SSD-001", "Samsung", "970 EVO Plus", 149.99, "TLC", 600));
    ssds.push_back(new SSD("SN-SSD-002", today, true, 500, 3500, 3000, "SSD-002", "WD", "Black SN750", 79.99, "TLC", 300));
    ssds.push_back(new SSD("SN-SSD-003", today, true, 2000, 7000, 5000, "SSD-003", "Samsung", "980 PRO", 299.99, "TLC", 1200));
    ssds.push_back(new SSD("SN-SSD-004", today, true, 1000, 3400, 3000, "SSD-004", "Crucial", "P5", 129.99, "TLC", 600));
    ssds.push_back(new SSD("SN-SSD-005", today, true, 500, 3500, 3000, "SSD-005", "Kingston", "KC2500", 89.99, "TLC", 300));
    ssds.push_back(new SSD("SN-SSD-006", today, true, 1000, 5000, 4500, "SSD-006", "ADATA", "XPG SX8200 Pro", 139.99, "TLC", 600));
    ssds.push_back(new SSD("SN-SSD-007", today, true, 2000, 7000, 5000, "SSD-007", "Sabrent", "Rocket 4 Plus", 399.99, "TLC", 1200));
    ssds.push_back(new SSD("SN-SSD-008", today, true, 1000, 3500, 3000, "SSD-008", "Seagate", "FireCuda 520", 149.99, "TLC", 600));
    ssds.push_back(new SSD("SN-SSD-009", today, true, 500, 3400, 3000, "SSD-009", "Intel", "660p", 69.99, "QLC", 300));
    ssds.push_back(new SSD("SN-SSD-010", today, true, 1000, 3500, 3000, "SSD-010", "Patriot", "Viper VP4100", 159.99, "TLC", 600));

    // Create Cooling
    vector<AirCooling *> air_coolings;
    air_coolings.push_back(new AirCooling("SN-COOL-001", today, true, 150, "COOL-001", "Noctua", "NH-D15", 89.99, 2, 1500));
    air_coolings.push_back(new AirCooling("SN-COOL-002", today, true, 120, "COOL-002", "Cooler Master", "Hyper 212", 39.99, 1, 2000));
    air_coolings.push_back(new AirCooling("SN-COOL-003", today, true, 140, "COOL-003", "be quiet!", "Dark Rock Pro 4", 79.99, 2, 1500));
    air_coolings.push_back(new AirCooling("SN-COOL-004", today, true, 120, "COOL-004", "Corsair", "A500", 59.99, 2, 1700));
    air_coolings.push_back(new AirCooling("SN-COOL-005", today, true, 92, "COOL-005", "Arctic", "Freezer 34", 29.99, 1, 1800));

    for (int i = 0; i < 5 && i < computers.size(); ++i)
    {
        computers[i]->setCooling(air_coolings[i]);
    }

    // Create Liquid Cooling
    vector<LiquidCooling *> liquid_coolings;
    liquid_coolings.push_back(new LiquidCooling("SN-LC-001", today, true, 240, "LC-001", "Corsair", "H100i RGB Platinum", 129.99, 240.0, "Water", true));
    liquid_coolings.push_back(new LiquidCooling("SN-LC-002", today, true, 360, "LC-002", "NZXT", "Kraken X73", 179.99, 360.0, "Water", true));
    liquid_coolings.push_back(new LiquidCooling("SN-LC-003", today, true, 280, "LC-003", "Cooler Master", "MasterLiquid ML280", 139.99, 280.0, "Water", true));
    liquid_coolings.push_back(new LiquidCooling("SN-LC-004", today, true, 240, "LC-004", "EVGA", "CLC 240", 119.99, 240.0, "Water", true));
    liquid_coolings.push_back(new LiquidCooling("SN-LC-005", today, true, 360, "LC-005", "Thermaltake", "Floe Riing RGB 360", 199.99, 360.0, "Water", true));

    for (int i = 5; i < computers.size(); ++i)
    {
        computers[i]->setCooling(liquid_coolings[i]);
    }

    // Create Power Supplies
    vector<PowerSupply *> psus;
    psus.push_back(new PowerSupply(750, "80+ Gold", true, "PSU-001", "Corsair", "RM750x", 124.99, "SN-PSU-001", today, true));
    psus.push_back(new PowerSupply(650, "80+ Bronze", true, "PSU-002", "EVGA", "600 BQ", 59.99, "SN-PSU-002", today, true));
    psus.push_back(new PowerSupply(850, "80+ Platinum", true, "PSU-003", "Seasonic", "Prime TX-850", 199.99, "SN-PSU-003", today, true));
    psus.push_back(new PowerSupply(550, "80+ Bronze", true, "PSU-004", "Cooler Master", "MWE 550", 49.99, "SN-PSU-004", today, true));
    psus.push_back(new PowerSupply(1000, "80+ Gold", true, "PSU-005", "Corsair", "RM1000x", 159.99, "SN-PSU-005", today, true));
    psus.push_back(new PowerSupply(750, "80+ Platinum", true, "PSU-006", "EVGA", "SuperNOVA 750 P2", 139.99, "SN-PSU-006", today, true));
    psus.push_back(new PowerSupply(650, "80+ Gold", true, "PSU-007", "Seasonic", "Focus GX-650", 109.99, "SN-PSU-007", today, true));
    psus.push_back(new PowerSupply(850, "80+ Gold", true, "PSU-008", "Cooler Master", "V850", 129.99, "SN-PSU-008", today, true));
    psus.push_back(new PowerSupply(550, "80+ Gold", true, "PSU-009", "Corsair", "CX550M", 69.99, "SN-PSU-009", today, true));
    psus.push_back(new PowerSupply(1000, "80+ Platinum", true, "PSU-010", "EVGA", "SuperNOVA 1000 P2", 229.99, "SN-PSU-010", today, true));

    for (int i = 0; i < computers.size(); ++i)
    {
        computers[i]->setPowerSupply(psus[i]);
    }

    // Create Motherboards
    vector<Motherboard *> motherboards;
    motherboards.push_back(new Motherboard("MB-001", "ASUS", "ROG Strix Z690-A", 299.99, "SN-MB-001", today, true, "Z690", "ATX", 4, 3, 6, true));
    motherboards.push_back(new Motherboard("MB-002", "MSI", "MPG Z490 Gaming Edge", 189.99, "SN-MB-002", today, true, "Z490", "ATX", 4, 2, 6, true));
    motherboards.push_back(new Motherboard("MB-003", "Gigabyte", "Z590 AORUS Elite", 229.99, "SN-MB-003", today, true, "Z590", "ATX", 4, 3, 6, true));
    motherboards.push_back(new Motherboard("MB-004", "ASRock", "B550 Phantom Gaming", 159.99, "SN-MB-004", today, true, "B550", "ATX", 4, 2, 6, true));
    motherboards.push_back(new Motherboard("MB-005", "ASUS", "TUF Gaming X570-Plus", 199.99, "SN-MB-005", today, true, "X570", "ATX", 4, 3, 6, true));
    motherboards.push_back(new Motherboard("MB-006", "MSI", "MAG B550 Tomahawk", 179.99, "SN-MB-006", today, true, "B550", "ATX", 4, 2, 6, true));
    motherboards.push_back(new Motherboard("MB-007", "Gigabyte", "B450 AORUS Pro", 129.99, "SN-MB-007", today, true, "B450", "ATX", 4, 2, 6, true));
    motherboards.push_back(new Motherboard("MB-008", "ASRock", "X570 Taichi", 249.99, "SN-MB-008", today, true, "X570", "ATX", 4, 3, 6, true));
    motherboards.push_back(new Motherboard("MB-009", "ASUS", "Prime Z390-A", 169.99, "SN-MB-009", today, true, "Z390", "ATX", 4, 2, 6, true));
    motherboards.push_back(new Motherboard("MB-010", "MSI", "Z370 Gaming Pro Carbon", 159.99, "SN-MB-010", today, true, "Z370", "ATX", 4, 2, 6, true));

    for (int i = 0; i < motherboards.size(); ++i)
    {
        motherboards[i]->installCPU(cpus[i]);
        motherboards[i]->installRAM(rams[i]);
        motherboards[i]->installExpansionCard(gpus[i]);
        motherboards[i]->installStorage(ssds[i]);
    }

    for (int i = 0; i < computers.size(); ++i)
    {
        computers[i]->setMotherboard(motherboards[i]);
    }

    // Create BIOS
    vector<BIOS *> bioses;
    bioses.push_back(new BIOS("ASUS", today, "F11", "Z690", today, true));
    bioses.push_back(new BIOS("MSI", today, "E7C91IMS", "Z490", today, true));
    bioses.push_back(new BIOS("Gigabyte", today, "F20", "Z590", today, true));
    bioses.push_back(new BIOS("ASRock", today, "P1.20", "B550", today, true));
    bioses.push_back(new BIOS("ASUS", today, "F12", "X570", today, true));
    bioses.push_back(new BIOS("MSI", today, "E7C37IMS", "B550", today, true));
    bioses.push_back(new BIOS("Gigabyte", today, "F50", "B450", today, true));
    bioses.push_back(new BIOS("ASRock", today, "P3.00", "X570", today, true));
    bioses.push_back(new BIOS("ASUS", today, "F10", "Z390", today, true));
    bioses.push_back(new BIOS("MSI", today, "E7B45IMS", "Z370", today, true));

    for (int i = 0; i < computers.size(); ++i)
    {
        computers[i]->setBIOS(bioses[i]);
    }

    // Create OS
    vector<OperatingSystem *> operatingSystems;
    operatingSystems.push_back(new OperatingSystem("Windows", "11", true, "22H2", "XXXXX-XXXXX-XXXXX-XXXXX", 16000.0));
    operatingSystems.push_back(new OperatingSystem("Windows", "10", true, "21H1", "XXXXX-XXXXX-XXXXX-XXXXX", 16000.0));
    operatingSystems.push_back(new OperatingSystem("Ubuntu", "20.04", true, "Focal Fossa", "XXXXX-XXXXX-XXXXX-XXXXX", 16000.0));
    operatingSystems.push_back(new OperatingSystem("Fedora", "34", true, "Workstation", "XXXXX-XXXXX-XXXXX-XXXXX", 16000.0));
    operatingSystems.push_back(new OperatingSystem("Debian", "11", true, "Bullseye", "XXXXX-XXXXX-XXXXX-XXXXX", 16000.0));
    operatingSystems.push_back(new OperatingSystem("Arch", "Rolling", true, "N/A", "XXXXX-XXXXX-XXXXX-XXXXX", 16000.0));
    operatingSystems.push_back(new OperatingSystem("CentOS", "8", true, "Stream", "XXXXX-XXXXX-XXXXX-XXXXX", 16000.0));
    operatingSystems.push_back(new OperatingSystem("Red Hat", "8", true, "Enterprise", "XXXXX-XXXXX-XXXXX-XXXXX", 16000.0));
    operatingSystems.push_back(new OperatingSystem("macOS", "11", true, "Big Sur", "XXXXX-XXXXX-XXXXX-XXXXX", 16000.0));
    operatingSystems.push_back(new OperatingSystem("Windows", "8.1", true, "Update 3", "XXXXX-XXXXX-XXXXX-XXXXX", 16000.0));

    for (int i = 0; i < computers.size(); ++i)
    {
        computers[i]->setOperatingSystem(operatingSystems[i]);
    }

    Computer *demoComputer = createDemoComputer(today);
    computers.push_back(demoComputer);

    bool running = true;
    while (running)
    {
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