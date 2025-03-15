#pragma once
#include <bits/stdc++.h>

#include "ExpansionCard.cpp"

class GraphicsCard : public ExpansionCard
{
private:
    int vramGB;
    std::string gpuModel;
    int cudaCores;
    int displayPorts;
    int hdmiPorts;

public:
    // Constructor
    GraphicsCard() : ExpansionCard(), vramGB(0), gpuModel(""), cudaCores(0), displayPorts(0), hdmiPorts(0) {}
    GraphicsCard(int vram, const std::string &model, int cuda, int display, int hdmi, const std::string &type, const std::string &serial, const Date &date, bool installed, const std::string &id, const std::string &manufacturer, const std::string &modelName, double price)
        : ExpansionCard(type, serial, date, installed, id, manufacturer, modelName, price), vramGB(vram), gpuModel(model), cudaCores(cuda), displayPorts(display), hdmiPorts(hdmi) {}

    // Destructor
    ~GraphicsCard() {}

    // Setters
    void setVramGB(int vram)
    {
        vramGB = vram;
    }

    void setGpuModel(const std::string &model)
    {
        gpuModel = model;
    }

    void setCudaCores(int cuda)
    {
        cudaCores = cuda;
    }

    void setDisplayPorts(int display)
    {
        displayPorts = display;
    }

    void setHdmiPorts(int hdmi)
    {
        hdmiPorts = hdmi;
    }

    // Getters
    int getVramGB() const
    {
        return vramGB;
    }

    std::string getGpuModel() const
    {
        return gpuModel;
    }

    int getCudaCores() const
    {
        return cudaCores;
    }

    int getDisplayPorts() const
    {
        return displayPorts;
    }

    int getHdmiPorts() const
    {
        return hdmiPorts;
    }

    bool connect() override
    {
        printf("Graphics card connected\n");
        return true;
    }

    bool disconnect() override
    {
        printf("Graphics card disconnected\n");
        return true;
    }
};
