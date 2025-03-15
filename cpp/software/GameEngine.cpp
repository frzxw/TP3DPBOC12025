#pragma once
#include <bits/stdc++.h>

#include "Application.cpp"

class GameEngine : public Application
{
private:
    std::string engineName;
    std::string version;
    std::string supportedPlatforms;
    bool isOpenSource;

public:
    // Constructors
    GameEngine()
        : Application(), engineName(""), version(""), supportedPlatforms(""), isOpenSource(false) {}

    GameEngine(std::string name, std::string ver, std::string platforms, bool openSource,
               std::string appName, std::string developer,
               std::string supportedOS, std::string softwareVersion, std::string licenseKey,
               double sizeMB)
        : Application(appName, developer, supportedOS, softwareVersion, licenseKey, sizeMB),
          engineName(name), version(ver), supportedPlatforms(platforms), isOpenSource(openSource) {}

    // Destructor
    ~GameEngine() {}

    // Setters
    void setEngineName(const std::string &name)
    {
        engineName = name;
    }

    void setVersion(const std::string &ver)
    {
        version = ver;
    }

    void setSupportedPlatforms(const std::string &platforms)
    {
        supportedPlatforms = platforms;
    }

    void setIsOpenSource(bool openSource)
    {
        isOpenSource = openSource;
    }

    // Getters
    std::string getEngineName() const
    {
        return engineName;
    }

    std::string getVersion() const
    {
        return version;
    }

    std::string getSupportedPlatforms() const
    {
        return supportedPlatforms;
    }

    bool getIsOpenSource() const
    {
        return isOpenSource;
    }
};