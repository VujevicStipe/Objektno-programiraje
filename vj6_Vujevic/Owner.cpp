#include "Owner.h"
#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

Owner::Owner(const string& name) : name(name) {}

Owner::Owner(const Owner& other) : name(other.name) {
    for (const auto& pet : other.pets) {
        pets.push_back(new VirtualPet(*pet));
    }
}

void Owner::addPet(VirtualPet* pet) {
    pets.push_back(pet);
}

void Owner::performActions() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 2);

    for (auto& pet : pets) {
        switch (dis(gen)) {
        case 0:
            pet->eat();
            break;
        case 1:
            pet->sleep();
            break;
        case 2:
            pet->play();
            break;
        }
    }
}

const string& Owner::getName() const {
    return name;
}

const vector<VirtualPet*>& Owner::getPets() const {
    return pets;
}
