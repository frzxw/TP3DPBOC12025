#pragma once
#include <bits/stdc++.h>

#include "../../component/Hardware.cpp"
#include "../../component/Component.cpp"

class CPU : public Hardware, public Component
{
private:
    double clockSpeedGHz;
    int cores;
    int threads;
    std::string architecture;
    double cacheSize;
    bool hyperthreading;
    std::string socketType;

public:
    // Constructor
    CPU() : Hardware(), Component(), clockSpeedGHz(0.0), cores(0), threads(0), architecture(""), cacheSize(0.0), hyperthreading(false), socketType("") {}
    CPU(const std::string &serial, const Date &installDate, bool installed, double clockSpeed, int coreCount, int threadCount, const std::string &arch, double cache, bool hyper, const std::string &id, const std::string &manufacturer, const std::string &model, double price, const std::string &socket)
        : Hardware(serial, installDate, installed), Component(id, manufacturer, model, price), clockSpeedGHz(clockSpeed), cores(coreCount), threads(threadCount), architecture(arch), cacheSize(cache), hyperthreading(hyper), socketType(socket) {}

    // Destructor
    ~CPU() {}

    // Setters
    void setClockSpeedGHz(double clockSpeed)
    {
        clockSpeedGHz = clockSpeed;
    }

    void setCores(int coreCount)
    {
        cores = coreCount;
    }

    void setThreads(int threadCount)
    {
        threads = threadCount;
    }

    void setArchitecture(const std::string &arch)
    {
        architecture = arch;
    }

    void setCacheSize(double cache)
    {
        cacheSize = cache;
    }

    void setHyperthreading(bool hyper)
    {
        hyperthreading = hyper;
    }

    void setSocketType(const std::string &socket)
    {
        socketType = socket;
    }

    // Getters
    double getClockSpeedGHz() const
    {
        return clockSpeedGHz;
    }

    int getCores() const
    {
        return cores;
    }

    int getThreads() const
    {
        return threads;
    }

    std::string getArchitecture() const
    {
        return architecture;
    }

    double getCacheSize() const
    {
        return cacheSize;
    }

    bool isHyperthreading() const
    {
        return hyperthreading;
    }

    std::string getSocketType() const
    {
        return socketType;
    }
};