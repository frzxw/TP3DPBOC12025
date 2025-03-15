#pragma once
#include <bits/stdc++.h>

#include "../utils/Date.cpp"

class Hardware
{
protected:
    std::string serialNumber;
    Date installationDate;
    bool physicallyInstalled;

public:
    // Constructors
    Hardware() : serialNumber(""), installationDate(Date()), physicallyInstalled(false) {}
    Hardware(const std::string &serial, const Date &date, bool installed)
        : serialNumber(serial), installationDate(date), physicallyInstalled(installed) {}

    // Destructor
    virtual ~Hardware() {}

    // Setters
    void setSerialNumber(const std::string &serial)
    {
        serialNumber = serial;
    }

    void setInstallationDate(const Date &date)
    {
        installationDate = date;
    }

    void setPhysicallyInstalled(bool installed)
    {
        physicallyInstalled = installed;
    }

    // Getters
    std::string getSerialNumber() const
    {
        return serialNumber;
    }

    Date getInstallationDate() const
    {
        return installationDate;
    }

    bool isPhysicallyInstalled() const
    {
        return physicallyInstalled;
    }
};