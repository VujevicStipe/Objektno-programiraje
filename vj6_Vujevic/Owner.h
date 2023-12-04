#ifndef OWNER_H
#define OWNER_H

#include "VirtualPet.h"
#include <vector>
#include <memory>

using namespace std;

class Owner {
public:
    Owner(const string& name);
    Owner(const Owner& other);
    Owner(Owner&& other) noexcept; 

    void addPet(unique_ptr<VirtualPet> pet);
    void performActions();

    const string& getName() const;
    const vector<unique_ptr<VirtualPet>>& getPets() const;

private:
    string name;
    vector<unique_ptr<VirtualPet>> pets;
};

#endif

