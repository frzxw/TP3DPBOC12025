#pragma once
#include "../../component/Component.cpp"
#include "../../component/Hardware.cpp"
#include "../../interfaces/Bootable.cpp"

class Cooling : public Hardware, public Component, public Bootable
{
protected:
    int maxThermalDissipation;

public:
    // Constructor
    Cooling() : Hardware(), Component(), maxThermalDissipation(0) {}
    Cooling(int thermalDissipation) : Hardware(), Component(), maxThermalDissipation(thermalDissipation) {}
    Cooling(const std::string &serialNumber, const Date &installationDate, bool physicallyInstalled, int thermalDissipation, const std::string &id, const std::string &manufacturer, const std::string &model, double price)
        : Hardware(serialNumber, installationDate, physicallyInstalled), Component(id, manufacturer, model, price), maxThermalDissipation(thermalDissipation) {}

    // Destructor
    virtual ~Cooling();

    // Setters
    void setMaxThermalDissipation(int maxThermalDissipation);

    // Getters
    int getMaxThermalDissipation() const;
};