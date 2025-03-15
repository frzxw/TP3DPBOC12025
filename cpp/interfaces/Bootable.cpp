#pragma once
#include <bits/stdc++.h>

class Bootable
{
public:
    // Constructor
    Bootable() {}

    // Destructor
    virtual ~Bootable() {}

    virtual bool boot() = 0;
    virtual void shutdown() = 0;
    virtual void restart() = 0;
};
