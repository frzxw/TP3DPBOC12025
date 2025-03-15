#pragma once
#include <bits/stdc++.h>

#include "ExpansionCard.cpp"

class SoundCard : public ExpansionCard
{
private:
    int channels;
    int bitDepth;
    int sampleRate;

public:
    // Constructor
    SoundCard() : ExpansionCard("", "", Date(), false, "", "", "", 0.0), channels(0), bitDepth(0), sampleRate(0) {}
    SoundCard(int channels, int bitDepth, int sampleRate, const std::string &interfaceType, const std::string &serial, const Date &date, bool installed, const std::string &id, const std::string &manufacturer, const std::string &model, double price)
        : ExpansionCard(interfaceType, serial, date, installed, id, manufacturer, model, price), channels(channels), bitDepth(bitDepth), sampleRate(sampleRate) {}

    // Destructor
    ~SoundCard() {}

    // Setters
    void setChannels(int channels)
    {
        this->channels = channels;
    }

    void setBitDepth(int bitDepth)
    {
        this->bitDepth = bitDepth;
    }

    void setSampleRate(int sampleRate)
    {
        this->sampleRate = sampleRate;
    }

    // Getters
    int getChannels() const
    {
        return channels;
    }

    int getBitDepth() const
    {
        return bitDepth;
    }

    int getSampleRate() const
    {
        return sampleRate;
    }

    bool connect() override
    {
        printf("Sound card connected\n");
        return true;
    }

    bool disconnect() override
    {
        printf("Sound card disconnected\n");
        return true;
    }
};