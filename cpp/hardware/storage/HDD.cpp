#pragma once
#include <bits/stdc++.h>

#include "StorageDevice.cpp"

class HDD : public StorageDevice
{
private:
    int rpm;
    int platterCount;

public:
    // Constructor
    HDD() : StorageDevice(), rpm(0), platterCount(0) {}
    HDD(const std::string &serial, const Date &installDate, bool installed, int capacityGB, int readSpeedMBs, int writeSpeedMBs, int rpm, int platterCount, const std::string &id, const std::string &manufacturer, const std::string &model, double price)
        : StorageDevice(serial, installDate, installed, capacityGB, readSpeedMBs, writeSpeedMBs, id, manufacturer, model, price), rpm(rpm), platterCount(platterCount) {}

    // Destructor
    ~HDD() {}

    // Setters
    void setRpm(int rpm)
    {
        this->rpm = rpm;
    }

    void setPlatterCount(int platterCount)
    {
        this->platterCount = platterCount;
    }

    // Getters
    int getRpm() const
    {
        return rpm;
    }

    int getPlatterCount() const
    {
        return platterCount;
    }

    bool connect() override
    {
        printf("HDD connected\n");
        return true;
    }

    bool disconnect() override
    {
        printf("HDD disconnected\n");
        return true;
    }
};