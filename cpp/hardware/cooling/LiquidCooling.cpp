#pragma once
#include <bits/stdc++.h>

#include "Cooling.cpp"

class LiquidCooling : public Cooling
{
private:
    double fluidVolume;
    std::string fluidType;
    bool hasPump;

public:
    // Constructor
    LiquidCooling() : Cooling(), fluidVolume(0.0), fluidType(""), hasPump(false) {}
    LiquidCooling(const std::string &serialNumber, const Date &installationDate, bool physicallyInstalled, int thermalDissipation, const std::string &id, const std::string &manufacturer, const std::string &model, double price, double volume, const std::string &type, bool pump)
        : Cooling(serialNumber, installationDate, physicallyInstalled, thermalDissipation, id, manufacturer, model, price), fluidVolume(volume), fluidType(type), hasPump(pump) {}

    // Destructor
    ~LiquidCooling() {}

    // Setters
    void setFluidVolume(double volume)
    {
        fluidVolume = volume;
    }

    void setFluidType(const std::string &type)
    {
        fluidType = type;
    }

    void setHasPump(bool pump)
    {
        hasPump = pump;
    }

    // Getters
    double getFluidVolume() const
    {
        return fluidVolume;
    }

    std::string getFluidType() const
    {
        return fluidType;
    }

    bool getHasPump() const
    {
        return hasPump;
    }
};