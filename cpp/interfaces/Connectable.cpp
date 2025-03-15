#pragma once
#include <bits/stdc++.h>

class Connectable
{
public:
    // Constructor
    Connectable() {}

    // Destructor
    virtual ~Connectable() {}

    virtual bool connect() = 0;
    virtual bool disconnect() = 0;
};