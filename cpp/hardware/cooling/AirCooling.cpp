#pragma once
#include "Cooling.cpp"

class AirCooling : public Cooling
{
private:
    int fanCount;
    int fanSpeedRPM;

public:
    // Constructor
    AirCooling() : Cooling(), fanCount(0), fanSpeedRPM(0) {}
    AirCooling(const std::string &serialNumber, const Date &installationDate, bool physicallyInstalled, int thermalDissipation, const std::string &id, const std::string &manufacturer, const std::string &model, double price, int fanCount, int fanSpeedRPM)
        : Cooling(serialNumber, installationDate, physicallyInstalled, thermalDissipation, id, manufacturer, model, price), fanCount(fanCount), fanSpeedRPM(fanSpeedRPM) {}

    // Destructor
    ~AirCooling() {}

    // Setters
    void setFanCount(int fanCount)
    {
        this->fanCount = fanCount;
    }

    void setFanSpeedRPM(int fanSpeedRPM)
    {
        this->fanSpeedRPM = fanSpeedRPM;
    }

    // Getters
    int getFanCount() const
    {
        return fanCount;
    }

    int getFanSpeedRPM() const
    {
        return fanSpeedRPM;
    }
};