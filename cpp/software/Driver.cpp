#pragma once
#include <bits/stdc++.h>

#include "../interfaces/Upgradable.cpp"

class Driver : public Upgradable
{
private:
    std::string deviceName;
    std::string driverVersion;
    std::string supportedOS;
    bool isSigned;

public:
    // Constructor
    Driver() : deviceName(""), driverVersion(""), supportedOS(""), isSigned(false) {}
    Driver(std::string deviceName, std::string driverVersion, std::string supportedOS, bool isSigned)
    {
        this->deviceName = deviceName;
        this->driverVersion = driverVersion;
        this->supportedOS = supportedOS;
        this->isSigned = isSigned;
    }

    // Destructor
    ~Driver() {}

    // Setters
    void setDeviceName(std::string deviceName)
    {
        this->deviceName = deviceName;
    }

    void setDriverVersion(std::string driverVersion)
    {
        this->driverVersion = driverVersion;
    }

    void setSupportedOS(std::string supportedOS)
    {
        this->supportedOS = supportedOS;
    }

    void setIsSigned(bool isSigned)
    {
        this->isSigned = isSigned;
    }

    // Getters
    std::string getDeviceName()
    {
        return deviceName;
    }

    std::string getDriverVersion()
    {
        return driverVersion;
    }

    std::string getSupportedOS()
    {
        return supportedOS;
    }

    bool getIsSigned()
    {
        return isSigned;
    }

    bool upgrade() override
    {
        printf("Driver upgraded\n");
        return true;
    }

    bool downgrade() override
    {
        printf("Driver downgraded\n");
        return true;
    }
};
