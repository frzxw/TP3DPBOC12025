#pragma once
#include <bits/stdc++.h>

#include "../../component/Component.cpp"
#include "../../component/Hardware.cpp"
#include "../../interfaces/Upgradable.cpp"

class RAM : public Hardware, public Upgradable, public Component
{
private:
    int capacityGB;
    std::string type;
    int speedMHz;
    bool isECC;

public:
    // Constructor
    RAM() : Hardware(), Component(), capacityGB(0), type(""), speedMHz(0), isECC(false) {}
    RAM(int capacity, const std::string &ramType, int speed, bool ecc, const std::string &serial, const Date &installDate, bool installed, const std::string &id, const std::string &manufacturer, const std::string &model, double price)
        : Hardware(serial, installDate, installed), Component(id, manufacturer, model, price), capacityGB(capacity), type(ramType), speedMHz(speed), isECC(ecc) {}

    // Destructor
    ~RAM() {}

    // Setters
    void setCapacityGB(int capacity)
    {
        capacityGB = capacity;
    }

    void setType(const std::string &ramType)
    {
        type = ramType;
    }

    void setSpeedMHz(int speed)
    {
        speedMHz = speed;
    }

    void setIsECC(bool ecc)
    {
        isECC = ecc;
    }

    // Getters
    int getCapacityGB() const
    {
        return capacityGB;
    }

    std::string getType() const
    {
        return type;
    }

    int getSpeedMHz() const
    {
        return speedMHz;
    }

    bool getIsECC() const
    {
        return isECC;
    }

    bool upgrade() override
    {
        printf("RAM upgraded\n");
        return true;
    }

    bool downgrade() override
    {
        printf("RAM downgraded\n");
        return true;
    }
};