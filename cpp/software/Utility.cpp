#pragma once
#include <bits/stdc++.h>

#include "../component/Software.cpp"
#include "../interfaces/Executable.cpp"
#include "../interfaces/Upgradable.cpp"

class Utility : public Software, public Executable, public Upgradable
{
private:
    std::string utilityName;
    std::string function;
    std::string version;

public:
    // Constructor
    Utility() : Software("", "", 0.0), utilityName(""), function(""), version("") {}
    Utility(std::string name, std::string func, std::string ver, std::string softwareVersion, std::string licenseKey, double sizeMB)
        : Software(softwareVersion, licenseKey, sizeMB), utilityName(name), function(func), version(ver) {}

    // Destructor
    ~Utility() {}

    // Setters
    void setUtilityName(const std::string &name)
    {
        utilityName = name;
    }

    void setFunction(const std::string &func)
    {
        function = func;
    }

    void setVersion(const std::string &ver)
    {
        version = ver;
    }

    // Getters
    std::string getUtilityName() const
    {
        return utilityName;
    }

    std::string getFunction() const
    {
        return function;
    }

    std::string getVersion() const
    {
        return version;
    }

    void execute() override
    {
        printf("Utility executed\n");
    }

    void terminate() override
    {
        printf("Utility terminated\n");
    }

    bool upgrade() override
    {
        printf("Utility upgraded\n");
        return true;
    }

    bool downgrade() override
    {
        printf("Utility downgraded\n");
        return true;
    }
};
