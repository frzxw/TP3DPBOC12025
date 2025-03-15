#pragma once
#include <bits/stdc++.h>

class Software
{
protected:
    std::string version;
    std::string licenseKey;
    double sizeMB;

public:
    // Constructors
    Software() : version(""), licenseKey(""), sizeMB(0.0) {}
    Software(const std::string &ver, const std::string &key, double size) : version(ver), licenseKey(key), sizeMB(size) {}

    // Destructor
    virtual ~Software() {}

    // Setters
    void setVersion(const std::string &ver)
    {
        version = ver;
    }

    void setLicenseKey(const std::string &key)
    {
        licenseKey = key;
    }

    void setSizeMB(double size)
    {
        sizeMB = size;
    }

    // Getters
    std::string getVersion() const
    {
        return version;
    }

    std::string getLicenseKey() const
    {
        return licenseKey;
    }

    double getSizeMB() const
    {
        return sizeMB;
    }
};