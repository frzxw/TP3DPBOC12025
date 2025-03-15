#pragma once
#include <bits/stdc++.h>

#include "ExpansionCard.cpp"

class NetworkCard : public ExpansionCard
{
private:
    std::string macAddress;
    int maxSpeedMbps;
    bool supportsWifi;
    bool supportsBluetooth;

public:
    // Constructors
    NetworkCard() : ExpansionCard(), macAddress(""), maxSpeedMbps(0), supportsWifi(false), supportsBluetooth(false) {}
    NetworkCard(const std::string &type, const std::string &serial, const Date &date, bool installed, const std::string &id, const std::string &manufacturer, const std::string &model, double price, std::string mac, int speed, bool wifi, bool bluetooth)
        : ExpansionCard(type, serial, date, installed, id, manufacturer, model, price), macAddress(mac), maxSpeedMbps(speed), supportsWifi(wifi), supportsBluetooth(bluetooth) {}

    // Destructor
    ~NetworkCard() {}

    // Setters
    void setMacAddress(const std::string &mac)
    {
        macAddress = mac;
    }

    void setMaxSpeedMbps(int speed)
    {
        maxSpeedMbps = speed;
    }

    void setSupportsWifi(bool wifi)
    {
        supportsWifi = wifi;
    }

    void setSupportsBluetooth(bool bluetooth)
    {
        supportsBluetooth = bluetooth;
    }

    // Getters
    std::string getMacAddress() const
    {
        return macAddress;
    }

    int getMaxSpeedMbps() const
    {
        return maxSpeedMbps;
    }

    bool isWifiSupported() const
    {
        return supportsWifi;
    }

    bool isBluetoothSupported() const
    {
        return supportsBluetooth;
    }

    bool connect() override
    {
        printf("Network card connected\n");
        return true;
    }

    bool disconnect() override
    {
        printf("Network card disconnected\n");
        return true;
    }
};