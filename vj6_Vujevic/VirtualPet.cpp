#include "VirtualPet.h"
#include <iostream>

VirtualPet::VirtualPet(const std::string& name, const std::string& type, int happiness, int hunger, bool awake)
    : name(name), type(type), happiness(happiness), hunger(hunger), awake(awake) {}

void VirtualPet::eat() {
    std::cout << name << " jede \n";
    happiness += 10;
    hunger -= 20;
}

void VirtualPet::sleep() {
    std::cout << name << " spava \n";
    happiness += 15;
    hunger += 10;
}

void VirtualPet::play() {
    std::cout << name << " se igra \n";
    happiness += 20;
    hunger += 10;
}

const std::string& VirtualPet::getName() const {
    return name;
}

const std::string& VirtualPet::getType() const {
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
