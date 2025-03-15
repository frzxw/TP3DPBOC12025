#pragma once
#include <bits/stdc++.h>

#include "Peripheral.cpp"

class Monitor : public Peripheral
{
private:
    double screenSizeInches;
    int resolutionWidth;
    int resolutionHeight;
    int refreshRate;
    std::string panelType;

public:
    // Constructor
    Monitor() : Peripheral(), screenSizeInches(0.0), resolutionWidth(0), resolutionHeight(0), refreshRate(0), panelType("") {}
    Monitor(double size, int width, int height, int refresh, const std::string &type, std::string serialNumber, Date installationDate, bool physicallyInstalled, std::string connectionType, bool wireless, std::string name, std::string id, std::string manufacturer, std::string model, double price)
        : Peripheral(serialNumber, installationDate, physicallyInstalled, connectionType, wireless, name, id, manufacturer, model, price), screenSizeInches(size), resolutionWidth(width), resolutionHeight(height), refreshRate(refresh), panelType(type) {}

    // Destructor
    ~Monitor() {}

    // Setters
    void setScreenSizeInches(double size)
    {
        screenSizeInches = size;
    }

    void setResolutionWidth(int width)
    {
        resolutionWidth = width;
    }

    void setResolutionHeight(int height)
    {
        resolutionHeight = height;
    }

    void setRefreshRate(int refresh)
    {
        refreshRate = refresh;
    }

    void setPanelType(const std::string &type)
    {
        panelType = type;
    }

    // Getters
    double getScreenSizeInches() const
    {
        return screenSizeInches;
    }

    int getResolutionWidth() const
    {
        return resolutionWidth;
    }

    int getResolutionHeight() const
    {
        return resolutionHeight;
    }

    int getRefreshRate() const
    {
        return refreshRate;
    }

    std::string getPanelType() const
    {
        return panelType;
    }

    bool connect() override
    {
        printf("Monitor connected\n");
        return true;
    }

    bool disconnect() override
    {
        printf("Monitor disconnected\n");
        return true;
    }
};