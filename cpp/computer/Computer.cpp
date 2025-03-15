#pragma once
#include <bits/stdc++.h>

#include "../hardware/motherboard/Motherboard.cpp"
#include "../hardware/power/PowerSupply.cpp"
#include "../hardware/cooling/AirCooling.cpp"
#include "../hardware/cooling/LiquidCooling.cpp"
#include "../hardware/peripheral/Monitor.cpp"
#include "../hardware/peripheral/Keyboard.cpp"
#include "../hardware/peripheral/Mouse.cpp"
#include "../software/OperatingSystem.cpp"
#include "../software/Application.cpp"
#include "../software/BIOS.cpp"
#include "../software/Driver.cpp"
#include "../software/Utility.cpp"
#include "../interfaces/Bootable.cpp"
#include "../component/Component.cpp"

class Computer : public Bootable, public Component
{
private:
    std::string name;
    bool powerStatus;
    Motherboard *motherboard;
    PowerSupply *powerSupply;
    Cooling *cooling;
    std::vector<Peripheral *> peripherals;
    std::vector<Software *> installedSoftware;
    BIOS *bios;
    OperatingSystem *operatingSystem;
    std::vector<Driver *> drivers;

public:
    // Constructor
    Computer()
        : Component(), name(""), powerStatus(false), motherboard(nullptr),
          powerSupply(nullptr), cooling(nullptr), bios(nullptr), operatingSystem(nullptr) {}

    Computer(std::string id, std::string manufacturer, std::string model, double price, std::string name)
        : Component(id, manufacturer, model, price), name(name), powerStatus(false),
          motherboard(nullptr), powerSupply(nullptr), cooling(nullptr),
          bios(nullptr), operatingSystem(nullptr) {}

    // Destructor
    ~Computer()
    {
        // Clean up all pointers
        if (motherboard)
            delete motherboard;
        if (powerSupply)
            delete powerSupply;
        if (cooling)
            delete cooling;
        if (bios)
            delete bios;
        if (operatingSystem)
            delete operatingSystem;

        for (auto peripheral : peripherals)
            delete peripheral;

        for (auto software : installedSoftware)
            delete software;

        for (auto driver : drivers)
            delete driver;
    }

    // Boot, shutdown, restart implementations
    bool boot() override
    {
        if (!powerStatus && powerSupply && motherboard && bios)
        {
            std::cout << "Starting computer " << name << "..." << std::endl;

            // Boot sequence
            bios->boot();
            if (operatingSystem)
            {
                operatingSystem->boot();
                std::cout << "Welcome to " << operatingSystem->getOsName() << " version " << operatingSystem->getVersion() << std::endl;
            }
            else
            {
                std::cout << "No operating system found!" << std::endl;
                return false;
            }

            powerStatus = true;
            return true;
        }
        return false;
    }

    void shutdown() override
    {
        if (powerStatus)
        {
            std::cout << "Shutting down computer " << name << "..." << std::endl;

            if (operatingSystem)
            {
                operatingSystem->shutdown();
            }

            powerStatus = false;
        }
    }

    void restart() override
    {
        if (powerStatus)
        {
            std::cout << "Restarting computer " << name << "..." << std::endl;

            if (operatingSystem)
            {
                operatingSystem->restart();
            }

            // Simulate restart
            powerStatus = false;
            boot();
        }
    }

    // Setters
    void setName(const std::string &name)
    {
        this->name = name;
    }

    void setMotherboard(Motherboard *mobo)
    {
        if (motherboard)
            delete motherboard;
        motherboard = mobo;
    }

    void setPowerSupply(PowerSupply *psu)
    {
        if (powerSupply)
            delete powerSupply;
        powerSupply = psu;
    }

    void setCooling(Cooling *cool)
    {
        if (cooling)
            delete cooling;
        cooling = cool;
    }

    void setBIOS(BIOS *newBios)
    {
        if (bios)
            delete bios;
        bios = newBios;
    }

    void setOperatingSystem(OperatingSystem *os)
    {
        if (operatingSystem)
            delete operatingSystem;
        operatingSystem = os;
    }

    // Getters
    std::string getName() const
    {
        return name;
    }

    bool isPowered() const
    {
        return powerStatus;
    }

    Motherboard *getMotherboard() const
    {
        return motherboard;
    }

    PowerSupply *getPowerSupply() const
    {
        return powerSupply;
    }

    Cooling *getCooling() const
    {
        return cooling;
    }

    BIOS *getBIOS() const
    {
        return bios;
    }

    OperatingSystem *getOperatingSystem() const
    {
        return operatingSystem;
    }

    // Component management methods
    void addPeripheral(Peripheral *peripheral)
    {
        if (peripheral)
        {
            peripherals.push_back(peripheral);
            peripheral->connect();
        }
    }

    void removePeripheral(Peripheral *peripheral)
    {
        auto it = std::find(peripherals.begin(), peripherals.end(), peripheral);
        if (it != peripherals.end())
        {
            (*it)->disconnect();
            peripherals.erase(it);
        }
    }

    void installSoftware(Software *software)
    {
        if (software && operatingSystem)
        {
            installedSoftware.push_back(software);
            std::cout << "Software installed: " << typeid(*software).name() << std::endl;
        }
    }

    void uninstallSoftware(Software *software)
    {
        auto it = std::find(installedSoftware.begin(), installedSoftware.end(), software);
        if (it != installedSoftware.end())
        {
            std::cout << "Software uninstalled: " << typeid(**it).name() << std::endl;
            installedSoftware.erase(it);
        }
    }

    void installDriver(Driver *driver)
    {
        if (driver && operatingSystem)
        {
            drivers.push_back(driver);
            std::cout << "Driver installed: " << driver->getDeviceName() << std::endl;
        }
    }

    void uninstallDriver(Driver *driver)
    {
        auto it = std::find(drivers.begin(), drivers.end(), driver);
        if (it != drivers.end())
        {
            std::cout << "Driver uninstalled: " << (*it)->getDeviceName() << std::endl;
            drivers.erase(it);
        }
    }

    // Display computer specification
    void displaySpecifications()
    {
        std::cout << "=== Computer Specifications ===" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Manufacturer: " << getManufacturer() << std::endl;
        std::cout << "Model: " << getModel() << std::endl;
        std::cout << "Power status: " << (powerStatus ? "ON" : "OFF") << std::endl;

        std::cout << "\n--- Hardware Components ---" << std::endl;
        if (motherboard)
        {
            std::cout << "Motherboard: " << motherboard->getManufacturer() << " " << motherboard->getModel() << std::endl;
            motherboard->displayInfo(); // This uses the displayInfo method from the Motherboard class
        }

        if (powerSupply)
        {
            std::cout << "Power Supply: " << powerSupply->getManufacturer() << " " << powerSupply->getModel()
                      << " (" << powerSupply->getWattage() << "W, " << powerSupply->getCertification() << ")" << std::endl;
        }

        if (cooling)
        {
            std::cout << "Cooling System: " << cooling->getManufacturer() << " " << cooling->getModel() << std::endl;
            std::cout << " - Max Thermal Dissipation: " << cooling->getMaxThermalDissipation() << "W" << std::endl;

            if (AirCooling *airCooler = dynamic_cast<AirCooling *>(cooling))
            {
                std::cout << " - Type: Air Cooling" << std::endl;
                std::cout << " - Fans: " << airCooler->getFanCount() << " @ " << airCooler->getFanSpeedRPM() << " RPM" << std::endl;
            }
            else if (LiquidCooling *liquidCooler = dynamic_cast<LiquidCooling *>(cooling))
            {
                std::cout << " - Type: Liquid Cooling" << std::endl;
                std::cout << " - Fluid: " << liquidCooler->getFluidType() << " (" << liquidCooler->getFluidVolume() << " ml)" << std::endl;
                std::cout << " - Has pump: " << (liquidCooler->getHasPump() ? "Yes" : "No") << std::endl;
            }
        }

        std::cout << "\n--- Peripherals ---" << std::endl;
        for (auto peripheral : peripherals)
        {
            std::cout << "- " << peripheral->getName() << ": " << peripheral->getManufacturer() << " " << peripheral->getModel() << std::endl;

            if (Monitor *monitor = dynamic_cast<Monitor *>(peripheral))
            {
                std::cout << "  Monitor: " << monitor->getScreenSizeInches() << "\" "
                          << monitor->getResolutionWidth() << "x" << monitor->getResolutionHeight()
                          << " @ " << monitor->getRefreshRate() << "Hz (" << monitor->getPanelType() << ")" << std::endl;
            }
            else if (Keyboard *keyboard = dynamic_cast<Keyboard *>(peripheral))
            {
                std::cout << "  Keyboard: " << keyboard->getLayoutType()
                          << (keyboard->isMechanical() ? " (Mechanical)" : "")
                          << (keyboard->hasBacklightFeature() ? " with backlight" : "") << std::endl;
            }
            else if (Mouse *mouse = dynamic_cast<Mouse *>(peripheral))
            {
                std::cout << "  Mouse: " << mouse->getButtonCount() << " buttons, "
                          << mouse->getDPI() << " DPI"
                          << (mouse->getHasScrollWheel() ? " with scroll wheel" : "") << std::endl;
            }
        }

        std::cout << "\n--- Software ---" << std::endl;
        if (bios)
        {
            std::cout << "BIOS: " << bios->getManufacturer() << " version " << bios->getFirmwareVersion() << std::endl;
        }

        if (operatingSystem)
        {
            std::cout << "OS: " << operatingSystem->getOsName() << " " << operatingSystem->getVersion()
                      << (operatingSystem->getIs64Bit() ? " (64-bit)" : " (32-bit)") << std::endl;
        }

        std::cout << "Installed Applications: " << installedSoftware.size() << std::endl;
        for (auto software : installedSoftware)
        {
            if (Application *app = dynamic_cast<Application *>(software))
            {
                std::cout << "- " << app->getAppName() << " by " << app->getDeveloper()
                          << " (ver " << app->getVersion() << ")" << std::endl;
            }
        }

        std::cout << "Installed Drivers: " << drivers.size() << std::endl;
        for (auto driver : drivers)
        {
            std::cout << "- " << driver->getDeviceName() << " driver (ver " << driver->getDriverVersion() << ")"
                      << (driver->getIsSigned() ? " [Signed]" : " [Unsigned]") << std::endl;
        }
    }

    // Calculate total power consumption (in watts)
    int calculatePowerConsumption()
    {
        int totalWatts = 0;

        // This is a simplified calculation
        if (motherboard)
        {
            // Base motherboard consumption (estimate)
            totalWatts += 50;

            // CPU power
            if (motherboard->getCPU())
            {
                // Estimate based on cores and clock speed
                CPU *cpu = motherboard->getCPU();
                totalWatts += static_cast<int>(cpu->getCores() * cpu->getClockSpeedGHz() * 10);
            }

            // RAM power (estimate: 3W per stick)
            totalWatts += motherboard->getRamSlots().size() * 3;

            // Graphics card (if present)
            if (motherboard->getGPU())
            {
                totalWatts += motherboard->getGPU()->getVramGB() * 20; // Rough estimate
            }

            // Storage devices (estimate: 5-10W each)
            totalWatts += motherboard->getStorageSlots().size() * 8;
        }

        return totalWatts;
    }

    // Estimate computer market value
    double estimateValue()
    {
        double totalValue = this->getPrice(); // Base computer price

        // Add component values
        if (motherboard)
            totalValue += motherboard->getPrice();
        if (powerSupply)
            totalValue += powerSupply->getPrice();
        if (cooling)
            totalValue += cooling->getPrice();

        // Add peripherals
        for (auto peripheral : peripherals)
        {
            totalValue += peripheral->getPrice();
        }

        // Apply depreciation (simplified)
        // For example, 15% depreciation per year since installation
        // This is just a placeholder for real depreciation calculation
        double depreciationRate = 0.85; // 15% depreciation
        totalValue *= depreciationRate;

        return totalValue;
    }

    // Run a software application
    void runApplication(Application *app)
    {
        if (powerStatus && app)
        {
            std::cout << "Running " << app->getAppName() << "..." << std::endl;
            app->execute();
        }
        else
        {
            std::cout << "Cannot run application. Computer is " << (powerStatus ? "on" : "off") << std::endl;
        }
    }

    // Close a running application
    void closeApplication(Application *app)
    {
        if (app)
        {
            std::cout << "Closing " << app->getAppName() << "..." << std::endl;
            app->terminate();
        }
    }

    // Perform system upgrade
    bool upgradeSystem()
    {
        if (!powerStatus)
        {
            std::cout << "Starting system upgrade..." << std::endl;

            bool success = true;

            // Upgrade BIOS if available
            if (bios)
            {
                success &= bios->upgrade();
            }

            // Upgrade OS if available
            if (operatingSystem)
            {
                success &= operatingSystem->upgrade();
            }

            // Upgrade drivers
            for (auto driver : drivers)
            {
                success &= driver->upgrade();
            }

            std::cout << "System upgrade " << (success ? "completed successfully" : "failed") << std::endl;
            return success;
        }
        else
        {
            std::cout << "Cannot upgrade while system is running. Please shut down first." << std::endl;
            return false;
        }
    }
};