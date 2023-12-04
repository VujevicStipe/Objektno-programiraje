#include "VirtualPet.h"
#include "Owner.h"
#include <iostream>

using namespace std;

int main() {
    Owner owner1("Marko");

    owner1.addPet(make_unique<VirtualPet>("Joza", "Macka"));
    owner1.addPet(make_unique<VirtualPet>("Rex", "Pas"));

    Owner owner2("Stipe");

    owner2.addPet(make_unique<VirtualPet>("Mrki", "ribica"));
    owner2.addPet(make_unique<VirtualPet>("MjauMjau", "macka"));

    owner1.performActions();
    owner2.performActions();

    cout << "Vlasnik 1 - " << owner1.getName() << "- ljubimci:\n";
    for (const auto& pet : owner1.getPets()) {
        cout << "  " << pet->getName() << ": Sreca - " << pet->getHappiness() << ", Glad - " << pet->getHunger() << "\n";
    }

    cout << "\nVlasnik 2 - " << owner2.getName() << "- ljubimci:\n";
    for (const auto& pet : owner2.getPets()) {
        cout << "  " << pet->getName() << ": Sreca - " << pet->getHappiness() << ", Glad - " << pet->getHunger() << "\n";
    }

    return 0;
}
