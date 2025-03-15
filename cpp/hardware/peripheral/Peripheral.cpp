#pragma once
#include <bits/stdc++.h>

#include "../../component/Component.cpp"
#include "../../component/Hardware.cpp"
#include "../../interfaces/Connectable.cpp"

class Peripheral : public Hardware, public Connectable, public Component
{
private:
    std::string name;
    std::string connectionType;
    bool wireless;

public:
    // Constructor
    Peripheral() : Hardware(), Component(), connectionType(""), wireless(false), name("") {}
    Peripheral(std::string serialNumber, Date installationDate, bool physicallyInstalled, std::string connectionType, bool wireless, std::string name, std::string id, std::string manufacturer, std::string model, double price)
        : Hardware(serialNumber, installationDate, physicallyInstalled), Component(id, manufacturer, model, price), connectionType(connectionType), wireless(wireless), name(name) {}

    // Destructor
    ~Peripheral() {}

    // Setters
    void setConnectionType(const std::string &connectionType)
    {
        this->connectionType = connectionType;
    }

    void setWireless(bool wireless)
    {
        this->wireless = wireless;
    }

    void setName(const std::string &name)
    {
        this->name = name;
    }

    // Getters
    std::string getConnectionType() const
    {
        return connectionType;
    }

    bool isWireless() const
    {
        return wireless;
    }

    std::string getName() const
    {
        return name;
    }

    bool connect() override
    {
        printf("Peripheral connected\n");
        return true;
    }

    bool disconnect() override
    {
        printf("Peripheral disconnected\n");
        return true;
    }
};