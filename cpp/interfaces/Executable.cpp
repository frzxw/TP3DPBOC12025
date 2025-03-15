#pragma once
#include <bits/stdc++.h>

class Executable
{
public:
    // Constructor
    Executable() {}

    // Destructor
    virtual ~Executable() {}

    virtual void execute() = 0;
    virtual void terminate() = 0;
};
