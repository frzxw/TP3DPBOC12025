#pragma once
#include <bits/stdc++.h>

#include "../../component/Component.cpp"
#include "../../component/Hardware.cpp"
#include "../../interfaces/Connectable.cpp"
#include "../../interfaces/Upgradable.cpp"

class ExpansionCard : public Hardware, public Connectable, public Component
{
protected:
    std::string interfaceType;

public:
    // Constructor
    ExpansionCard() : Hardware(), Component(), interfaceType("") {}
    ExpansionCard(const std::string &type, const std::string &serial, const Date &date, bool installed, const std::string &id, const std::string &manufacturer, const std::string &model, double price)
        : Hardware(serial, date, installed), Component(id, manufacturer, model, price), interfaceType(type) {}

    // Destructor
    ~ExpansionCard() {}

    // Getters
    std::string getInterfaceType() const
    {
        return interfaceType;
    }

    // Setters
    void setInterfaceType(const std::string &type)
    {
        interfaceType = type;
    }

    bool connect() override
    {
        printf("Expansion card connected\n");
        return true;
    }

    bool disconnect() override
    {
        printf("Expansion card disconnected\n");
        return true;
    }
};