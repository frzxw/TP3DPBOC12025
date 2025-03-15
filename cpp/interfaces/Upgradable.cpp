#pragma once
#include <bits/stdc++.h>

class Upgradable
{
public:
    // Constructor
    Upgradable() {}

    // Destructor
    virtual ~Upgradable() {}

    virtual bool upgrade() = 0;
    virtual bool downgrade() = 0;
};