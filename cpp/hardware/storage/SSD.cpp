#pragma once
#include <bits/stdc++.h>

#include "StorageDevice.cpp"

class SSD : public StorageDevice
{
private:
    std::string nandType;
    int tbw; // Total Bytes Written

public:
    // Constructor
    SSD() : StorageDevice(), nandType(""), tbw(0) {}
    SSD(const std::string &serial, const Date &installDate, bool installed, int capacityGB, int readSpeedMBs, int writeSpeedMBs, const std::string &id, const std::string &manufacturer, const std::string &model, double price, std::string nandType, int tbw)
        : StorageDevice(serial, installDate, installed, capacityGB, readSpeedMBs, writeSpeedMBs, id, manufacturer, model, price), nandType(nandType), tbw(tbw) {}

    // Destructor
    ~SSD() {}

    // Setters
    void setNandType(const std::string &nandType)
    {
        this->nandType = nandType;
    }

    void setTbw(int tbw)
    {
        this->tbw = tbw;
    }

    // Getters
    std::string getNandType() const
    {
        return nandType;
    }

    int getTbw() const
    {
        return tbw;
    }

    bool connect() override
    {
        printf("SSD connected\n");
        return true;
    }

    bool disconnect() override
    {
        printf("SSD disconnected\n");
        return true;
    }
};