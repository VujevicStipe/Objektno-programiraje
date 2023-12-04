#include "VirtualPet.h"
#include <iostream>

using namespace std;

VirtualPet::VirtualPet(const string& name, const string& type, int happiness, int hunger, bool awake)
    : name(name), type(type), happiness(happiness), hunger(hunger), awake(awake) {}

void VirtualPet::eat() {
    cout << name << " jede \n";
    happiness += 10;
    hunger -= 20;
}

void VirtualPet::sleep() {
    cout << name << " spava \n";
    happiness += 15;
    hunger += 10;
}

void VirtualPet::play() {
    cout << name << " se igra \n";
    happiness += 20;
    hunger += 10;
}

const string& VirtualPet::getName() const {
    return name;
}

const string& VirtualPet::getType() const {
    return type;
}

int VirtualPet::getHappiness() const {
    return happiness;
}

int VirtualPet::getHunger() const {
    return hunger;
}

bool VirtualPet::isAwake() const {
    return awake;
}
