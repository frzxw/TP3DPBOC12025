#pragma once
#include <bits/stdc++.h>

#include "../../component/Component.cpp"
#include "../../component/Hardware.cpp"
#include "../../interfaces/Connectable.cpp"

class StorageDevice : public Hardware, public Connectable, public Component
{
protected:
    int capacityGB;
    int readSpeedMBs;
    int writeSpeedMBs;

public:
    // Constructor
    StorageDevice() : Hardware(), Component(), capacityGB(0), readSpeedMBs(0), writeSpeedMBs(0) {}
    StorageDevice(const std::string &serial, const Date &installDate, bool installed, int capacity, int readSpeed, int writeSpeed, const std::string &id, const std::string &manufacturer, const std::string &model, double price)
        : Hardware(serial, installDate, installed), Component(id, manufacturer, model, price), capacityGB(capacity), readSpeedMBs(readSpeed), writeSpeedMBs(writeSpeed) {}

    // Destructor
    ~StorageDevice() {}

    // Setters
    void setCapacityGB(int capacity)
    {
        capacityGB = capacity;
    }

    void setReadSpeedMBs(int readSpeed)
    {
        readSpeedMBs = readSpeed;
    }

    void setWriteSpeedMBs(int writeSpeed)
    {
        writeSpeedMBs = writeSpeed;
    }

    // Getters
    int getCapacityGB() const
    {
        return capacityGB;
    }

    int getReadSpeedMBs() const
    {
        return readSpeedMBs;
    }

    int getWriteSpeedMBs() const
    {
        return writeSpeedMBs;
    }

    bool connect() override
    {
        printf("Storage device connected\n");
        return true;
    }

    bool disconnect() override
    {
        printf("Storage device disconnected\n");
        return true;
    }
};
