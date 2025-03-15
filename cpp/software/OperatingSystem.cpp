#pragma once
#include <bits/stdc++.h>

#include "../component/Software.cpp"
#include "../interfaces/Bootable.cpp"
#include "../interfaces/Executable.cpp"
#include "../interfaces/Upgradable.cpp"

class OperatingSystem : public Software, public Bootable, public Upgradable
{
private:
    std::string osName;
    std::string kernelVersion;
    bool is64Bit;
    bool installed;

public:
    // Constructor
    OperatingSystem() : Software("", "", 0.0), osName(""), kernelVersion(""), is64Bit(false) {}
    OperatingSystem(std::string name, std::string version, bool bit64, std::string softwareVersion, std::string licenseKey, double sizeMB)
        : Software(softwareVersion, licenseKey, sizeMB), osName(name), kernelVersion(version), is64Bit(bit64) {}

    // Destructor
    ~OperatingSystem() {}

    // Setters
    void setOsName(const std::string &name)
    {
        osName = name;
    }

    void setKernelVersion(const std::string &version)
    {
        kernelVersion = version;
    }

    void setIs64Bit(bool bit64)
    {
        is64Bit = bit64;
    }

    void setInstalled(bool isInstalled)
    {
        installed = isInstalled;
    }

    // Getters
    std::string getOsName() const
    {
        return osName;
    }

    std::string getKernelVersion() const
    {
        return kernelVersion;
    }

    bool getIs64Bit() const
    {
        return is64Bit;
    }

    bool isInstalled() const
    {
        return installed;
    }

    bool boot() override
    {
        printf("Operating System booted\n");
        return true;
    }

    void shutdown() override
    {
        printf("Operating System shutdown\n");
    }

    void restart() override
    {
        printf("Operating System restarted\n");
    }

    bool upgrade() override
    {
        printf("Operating System upgraded\n");
        return true;
    }

    bool downgrade() override
    {
        printf("Operating System downgraded\n");
        return true;
    }
};
