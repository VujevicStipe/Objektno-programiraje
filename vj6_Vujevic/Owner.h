#ifndef OWNER_H
#define OWNER_H

#include "VirtualPet.h"
#include <vector>

using namespace std;

class Owner {
public:
    Owner(const string& name);
    Owner(const Owner& other);
    Owner(Owner&& other) noexcept;

    void addPet(VirtualPet* pet);
    void performActions();

    const string& getName() const;
    const vector<VirtualPet*>& getPets() const;

private:
    string name;
    vector<VirtualPet*> pets;
};

#endif
