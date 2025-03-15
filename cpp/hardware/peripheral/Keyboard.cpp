#pragma once
#include <bits/stdc++.h>

#include "Peripheral.cpp"

class Keyboard : public Peripheral
{
private:
    bool mechanical;
    std::string layoutType;
    bool hasBacklight;

public:
    // Constructor
    Keyboard() : Peripheral(), mechanical(false), layoutType(""), hasBacklight(false) {}
    Keyboard(bool mechanical, std::string layoutType, bool hasBacklight, std::string serialNumber, Date installationDate, bool physicallyInstalled, std::string connectionType, bool wireless, std::string name, std::string id, std::string manufacturer, std::string model, double price)
        : Peripheral(serialNumber, installationDate, physicallyInstalled, connectionType, wireless, name, id, manufacturer, model, price), mechanical(mechanical), layoutType(layoutType), hasBacklight(hasBacklight) {}

    // Destructor
    ~Keyboard() {}

    // Setters
    void setMechanical(bool mechanical)
    {
        this->mechanical = mechanical;
    }

    void setLayoutType(const std::string &layoutType)
    {
        this->layoutType = layoutType;
    }

    void setHasBacklight(bool hasBacklight)
    {
        this->hasBacklight = hasBacklight;
    }

    // Getters
    bool isMechanical() const
    {
        return mechanical;
    }

    std::string getLayoutType() const
    {
        return layoutType;
    }

    bool hasBacklightFeature() const
    {
        return hasBacklight;
    }

    bool connect() override
    {
        printf("Keyboard connected\n");
        return true;
    }

    bool disconnect() override
    {
        printf("Keyboard disconnected\n");
        return true;
    }
};
