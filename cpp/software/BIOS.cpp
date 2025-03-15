#pragma once
#include <bits/stdc++.h>

#include "Firmware.cpp"
#include "../interfaces/Bootable.cpp"

class BIOS : public Firmware, public Bootable
{
private:
    std::string manufacturer;
    Date releaseDate;
    bool installed;

public:
    // Constructors
    BIOS() : Firmware(), manufacturer(""), releaseDate(Date())
    {
    }
    BIOS(std::string manufacturer, Date releaseDate, std::string firmwareVersion, std::string supportedHardware, Date firmwareReleaseDate, bool installed)
        : Firmware(firmwareVersion, supportedHardware, firmwareReleaseDate), manufacturer(manufacturer), releaseDate(releaseDate) {}

    // Destructor
    ~BIOS() {}

    // Setters
    void setManufacturer(const std::string &manufacturer)
    {
        this->manufacturer = manufacturer;
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
    std::string getManufacturer() const
    {
        return manufacturer;
    }

    Date getReleaseDate() const
    {
        return releaseDate;
    }

    bool isInstalled() const
    {
        return installed;
    }

    bool boot() override
    {
        printf("BIOS booted\n");
        return true;
    }

    void shutdown() override
    {
        printf("BIOS shutdown\n");
    }

    void restart() override
    {
        printf("BIOS restarted\n");
    }
};
