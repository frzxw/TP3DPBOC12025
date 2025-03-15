#pragma once
#include <bits/stdc++.h>

#include "../../component/Component.cpp"
#include "../../component/Hardware.cpp"
#include "../../interfaces/Upgradable.cpp"

class PowerSupply : public Hardware, public Component
{
private:
    int wattage;
    std::string certification;
    bool modular;

public:
    // Constructors
    PowerSupply() : Hardware(), Component(), wattage(0), certification(""), modular(false) {}
    PowerSupply(int wattage, const std::string &certification, bool modular, const std::string &id, const std::string &manufacturer, const std::string &model, double price, const std::string &serialNumber, const Date &installationDate, bool physicallyInstalled)
        : Hardware(serialNumber, installationDate, physicallyInstalled), Component(id, manufacturer, model, price), wattage(wattage), certification(certification), modular(modular) {}

    // Destructor
    ~PowerSupply() {}

    // Setters
    void setWattage(int wattage)
    {
        this->wattage = wattage;
    }

    void setCertification(const std::string &certification)
    {
        this->certification = certification;
    }

    void setModular(bool modular)
    {
        this->modular = modular;
    }

    // Getters
    int getWattage() const
    {
        return wattage;
    }

    std::string getCertification() const
    {
        return certification;
    }

    bool isModular() const
    {
        return modular;
    }
};
