#pragma once
#include <bits/stdc++.h>

#include "../component/Software.cpp"
#include "../interfaces/Executable.cpp"
#include "../interfaces/Upgradable.cpp"

class Application : public Software, public Executable, public Upgradable
{
protected:
    std::string appName;
    std::string developer;
    std::string supportedOS;

public:
    // Constructors
    Application() : Software(), appName(""), developer(""), supportedOS("") {}
    Application(std::string appName, std::string developer, std::string supportedOS, std::string softwareVersion, std::string licenseKey, double sizeMB)
        : Software(softwareVersion, licenseKey, sizeMB), appName(appName), developer(developer), supportedOS(supportedOS) {}

    // Destructor
    ~Application() {}

    // Setters
    void setAppName(const std::string &appName)
    {
        this->appName = appName;
    }

    void setDeveloper(const std::string &developer)
    {
        this->developer = developer;
    }

    void setSupportedOS(const std::string &supportedOS)
    {
        this->supportedOS = supportedOS;
    }

    // Getters
    std::string getAppName() const
    {
        return appName;
    }

    std::string getDeveloper() const
    {
        return developer;
    }

    std::string getSupportedOS() const
    {
        return supportedOS;
    }

    void execute() override
    {
        printf("Application %s is running\n", appName.c_str());
    }

    void terminate() override
    {
        printf("Application %s has been terminated\n", appName.c_str());
    }

    bool upgrade() override
    {
        printf("Application %s has been upgraded\n", appName.c_str());
        return true;
    }

    bool downgrade() override
    {
        printf("Application %s has been downgraded\n", appName.c_str());
        return true;
    }
};
