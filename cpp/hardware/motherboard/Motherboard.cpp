#pragma once
#include <bits/stdc++.h>
#include "../../component/Component.cpp"
#include "../../component/Hardware.cpp"
#include "../processor/CPU.cpp"
#include "../memory/RAM.cpp"
#include "../expansion/ExpansionCard.cpp"
#include "../expansion/GraphicsCard.cpp"
#include "../expansion/NetworkCard.cpp"
#include "../expansion/SoundCard.cpp"
#include "../storage/StorageDevice.cpp"
#include "../storage/SSD.cpp"
#include "../storage/HDD.cpp"

class Motherboard : public Component, public Hardware
{
private:
    std::string chipset;
    std::string formFactor; // ATX, Micro-ATX, Mini-ITX
    int ramSlotsCount;
    int pcieSlotsCount;
    int sataPortsCount;
    bool hasIntegratedGPU;
    std::vector<std::string> supportedCPUs;

    CPU *cpu;                                    // One CPU per motherboard
    std::vector<RAM *> ramSlots;                 // Multiple RAM sticks
    std::vector<ExpansionCard *> expansionSlots; // All expansion cards (GPU, network, sound)
    std::vector<StorageDevice *> storageSlots;   // All storage devices (SSD, HDD)

    // Specific expansion card tracking
    GraphicsCard *gpu;
    NetworkCard *networkCard;
    SoundCard *soundCard;

public:
    // Constructor
    Motherboard(std::string id, std::string manufacturer, std::string model, double price,
                std::string serialNumber, Date installationDate, bool physicallyInstalled,
                std::string chipset, std::string formFactor, int ramSlotsCount,
                int pcieSlotsCount, int sataPortsCount, bool hasIntegratedGPU)
        : Component{id, manufacturer, model, price},
          Hardware{serialNumber, installationDate, physicallyInstalled},
          chipset(chipset), formFactor(formFactor), ramSlotsCount(ramSlotsCount),
          pcieSlotsCount(pcieSlotsCount), sataPortsCount(sataPortsCount),
          hasIntegratedGPU(hasIntegratedGPU), cpu(nullptr), gpu(nullptr),
          networkCard(nullptr), soundCard(nullptr) {}

    // Setters
    void setChipset(const std::string &chipset) { this->chipset = chipset; }
    void setFormFactor(const std::string &formFactor) { this->formFactor = formFactor; }
    void setRamSlotsCount(int count) { this->ramSlotsCount = count; }
    void setPcieSlotsCount(int count) { this->pcieSlotsCount = count; }
    void setSataPortsCount(int count) { this->sataPortsCount = count; }
    void setHasIntegratedGPU(bool hasIntegratedGPU) { this->hasIntegratedGPU = hasIntegratedGPU; }
    void setSupportedCPUs(const std::vector<std::string> &cpus) { this->supportedCPUs = cpus; }
    void setCPU(CPU *cpu) { this->cpu = cpu; }
    void setRamSlots(const std::vector<RAM *> &ramSlots) { this->ramSlots = ramSlots; }
    void setExpansionSlots(const std::vector<ExpansionCard *> &expansionSlots) { this->expansionSlots = expansionSlots; }
    void setStorageSlots(const std::vector<StorageDevice *> &storageSlots) { this->storageSlots = storageSlots; }
    void setGPU(GraphicsCard *gpu) { this->gpu = gpu; }
    void setNetworkCard(NetworkCard *networkCard) { this->networkCard = networkCard; }
    void setSoundCard(SoundCard *soundCard) { this->soundCard = soundCard; }

    // Getters
    std::string getChipset() const { return chipset; }
    std::string getFormFactor() const { return formFactor; }
    int getRamSlotsCount() const { return ramSlotsCount; }
    int getPcieSlotsCount() const { return pcieSlotsCount; }
    int getSataPortsCount() const { return sataPortsCount; }
    bool getHasIntegratedGPU() const { return hasIntegratedGPU; }
    std::vector<std::string> getSupportedCPUs() const { return supportedCPUs; }
    CPU *getCPU() const { return cpu; }
    std::vector<RAM *> getRamSlots() const { return ramSlots; }
    std::vector<ExpansionCard *> getExpansionSlots() const { return expansionSlots; }
    std::vector<StorageDevice *> getStorageSlots() const { return storageSlots; }
    GraphicsCard *getGPU() const { return gpu; }
    NetworkCard *getNetworkCard() const { return networkCard; }
    SoundCard *getSoundCard() const { return soundCard; }

    // Install CPU
    void installCPU(CPU *newCPU)
    {
        cpu = newCPU;
    }

    // Install RAM
    void installRAM(RAM *newRAM)
    {
        if (ramSlots.size() < ramSlotsCount)
            ramSlots.push_back(newRAM);
        else
            std::cout << "No available RAM slots!" << std::endl;
    }

    // Install Expansion Card
    void installExpansionCard(ExpansionCard *card)
    {
        if (expansionSlots.size() < pcieSlotsCount)
        {
            expansionSlots.push_back(card);

            // Check specific type of expansion card
            if (GraphicsCard *g = dynamic_cast<GraphicsCard *>(card))
            {
                gpu = g;
            }
            else if (NetworkCard *n = dynamic_cast<NetworkCard *>(card))
            {
                networkCard = n;
            }
            else if (SoundCard *s = dynamic_cast<SoundCard *>(card))
            {
                soundCard = s;
            }
        }
        else
        {
            std::cout << "No available PCIe slots!" << std::endl;
        }
    }

    // Install Storage Device (SSD/HDD)
    void installStorage(StorageDevice *storage)
    {
        if (storageSlots.size() < sataPortsCount)
        {
            storageSlots.push_back(storage);
        }
        else
        {
            std::cout << "No available SATA slots!" << std::endl;
        }
    }

    // Remove CPU
    void removeCPU()
    {
        if (cpu)
        {
            cpu = nullptr;
        }
        else
        {
            std::cout << "No CPU installed to remove!" << std::endl;
        }
    }

    // Remove RAM
    void removeRAM(RAM *ram)
    {
        auto it = std::find(ramSlots.begin(), ramSlots.end(), ram);
        if (it != ramSlots.end())
        {
            ramSlots.erase(it);
        }
        else
        {
            std::cout << "RAM not found!" << std::endl;
        }
    }

    // Remove Expansion Card
    void removeExpansionCard(ExpansionCard *card)
    {
        auto it = std::find(expansionSlots.begin(), expansionSlots.end(), card);
        if (it != expansionSlots.end())
        {
            expansionSlots.erase(it);

            // Check specific type of expansion card
            if (GraphicsCard *g = dynamic_cast<GraphicsCard *>(card))
            {
                gpu = nullptr;
            }
            else if (NetworkCard *n = dynamic_cast<NetworkCard *>(card))
            {
                networkCard = nullptr;
            }
            else if (SoundCard *s = dynamic_cast<SoundCard *>(card))
            {
                soundCard = nullptr;
            }
        }
        else
        {
            std::cout << "Expansion card not found!" << std::endl;
        }
    }

    // Remove Storage Device (SSD/HDD)
    void removeStorage(StorageDevice *storage)
    {
        auto it = std::find(storageSlots.begin(), storageSlots.end(), storage);
        if (it != storageSlots.end())
        {
            storageSlots.erase(it);
        }
        else
        {
            std::cout << "Storage device not found!" << std::endl;
        }
    }

    // Display motherboard details
    void displayInfo()
    {
        std::cout << "Motherboard: " << model << " (" << manufacturer << ")\n";
        std::cout << "Chipset: " << chipset << " | Form Factor: " << formFactor << "\n";
        std::cout << "RAM Slots: " << ramSlotsCount << " | PCIe Slots: " << pcieSlotsCount << " | SATA Ports: " << sataPortsCount << "\n";

        // CPU
        if (cpu)
        {
            std::cout << "Installed CPU: " << cpu->getModel() << "\n";
        }
        else
        {
            std::cout << "No CPU installed\n";
        }

        // RAM
        std::cout << "Installed RAM: " << ramSlots.size() << "/" << ramSlotsCount << " slots used\n";

        // Expansion Cards
        std::cout << "Installed Expansion Cards: " << expansionSlots.size() << "/" << pcieSlotsCount << " slots used\n";
        if (gpu)
            std::cout << " - Graphics Card: " << gpu->getModel() << "\n";
        if (networkCard)
            std::cout << " - Network Card: " << networkCard->getModel() << "\n";
        if (soundCard)
            std::cout << " - Sound Card: " << soundCard->getModel() << "\n";

        // Storage
        std::cout << "Installed Storage Devices: " << storageSlots.size() << "/" << sataPortsCount << " slots used\n";
        for (auto &storage : storageSlots)
        {
            std::cout << " - " << storage->getModel() << "\n";
        }
    }
};
