#pragma once
#include <bits/stdc++.h>

#include "Peripheral.cpp"

class Mouse : public Peripheral {
private:
    int buttonCount;
    bool hasScrollWheel;
    int dpi;

public:
    // Constructor
    Mouse() : Peripheral(), buttonCount(0), hasScrollWheel(false), dpi(0) {}
    Mouse(int buttonCount, bool hasScrollWheel, int dpi, std::string serialNumber, Date installationDate, bool physicallyInstalled, std::string connectionType, bool wireless, std::string name, std::string id, std::string manufacturer, std::string model, double price)
        : Peripheral(serialNumber, installationDate, physicallyInstalled, connectionType, wireless, name, id, manufacturer, model, price), buttonCount(buttonCount), hasScrollWheel(hasScrollWheel), dpi(dpi) {}

    // Destructor
    ~Mouse() {}

    // Setters
    void setButtonCount(int buttonCount) {
        this->buttonCount = buttonCount;
    }

    void setHasScrollWheel(bool hasScrollWheel) {
        this->hasScrollWheel = hasScrollWheel;
    }

    void setDPI(int dpi) {
        this->dpi = dpi;
    }

    // Getters
    int getButtonCount() const {
        return buttonCount;
    }

    bool getHasScrollWheel() const {
        return hasScrollWheel;
    }

    int getDPI() const {
        return dpi;
    }

    bool connect() override {
        printf("Mouse connected\n");
        return true;
    }

    bool disconnect() override {
        printf("Mouse disconnected\n");
        return true;
    }
};
