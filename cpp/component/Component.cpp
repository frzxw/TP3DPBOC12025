#pragma once
#include <bits/stdc++.h>

class Component
{
protected:
    std::string id;
    std::string manufacturer;
    std::string model;
    double price;

public:
    // Constructors
    Component() : id(""), manufacturer(""), model(""), price(0.0) {}
    Component(const std::string &id, const std::string &manufacturer, const std::string &model, double price)
        : id(id), manufacturer(manufacturer), model(model), price(price) {}

    // Destructor
    virtual ~Component() {}

    // Setters
    void setId(const std::string &id)
    {
        this->id = id;
    }

    void setManufacturer(const std::string &manufacturer)
    {
        this->manufacturer = manufacturer;
    }

    void setModel(const std::string &model)
    {
        this->model = model;
    }

    void setPrice(double price)
    {
        this->price = price;
    }

    // Getters
    std::string getId() const
    {
        return id;
    }

    std::string getManufacturer() const
    {
        return manufacturer;
    }

    std::string getModel() const
    {
        return model;
    }

    double getPrice() const
    {
        return price;
    }
};