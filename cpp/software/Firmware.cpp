#pragma once
#include <bits/stdc++.h>

#include "../utils/Date.cpp"
#include "../interfaces/Executable.cpp"
#include "../interfaces/Upgradable.cpp"

class Firmware : public Executable, public Upgradable
{
protected:
    std::string firmwareVersion;
    std::string supportedHardware;
    Date releaseDate;
    bool installed;

public:
    // Constructors
    Firmware() : firmwareVersion(""), supportedHardware(""), releaseDate(), installed(false) {}
    Firmware(const std::string &version, const std::string &hardware, const Date &date)
        : firmwareVersion(version), supportedHardware(hardware), releaseDate(date), installed(false) {}

    // Destructor
    ~Firmware() {}

    // Setters
    void setFirmwareVersion(const std::string &version)
    {
        firmwareVersion = version;
    }

    void setSupportedHardware(const std::string &hardware)
    {
        supportedHardware = hardware;
    }

    void setReleaseDate(const Date &date)
    {
        releaseDate = date;
    }

    void setInstalled(bool isInstalled)
    {
        installed = isInstalled;
    }

    // Getters
    std::string getFirmwareVersion() const
    {
        return firmwareVersion;
    }

    std::string getSupportedHardware() const
    {
        return supportedHardware;
    }

    Date getReleaseDate() const
    {
        return releaseDate;
    }

    bool isInstalled() const
    {
        return installed;
    }

    void execute() override
    {
        printf("Firmware executed\n");
    }

    void terminate() override
    {
        printf("Firmware terminated\n");
    }

    bool upgrade() override
    {
        printf("Firmware upgraded\n");
        return true;
    }

    bool downgrade() override
    {
        printf("Firmware downgraded\n");
        return true;
    }
};
