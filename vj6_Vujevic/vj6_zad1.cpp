#include "VirtualPet.h"
#include "Owner.h"
#include <iostream>

using namespace std;

int main() {
    Owner owner1("Marko");

    owner1.addPet(new VirtualPet("Jozo", "Sijamski tvor"));
    owner1.addPet(new VirtualPet("SamDode", "Istarski gonic"));

    Owner owner2("Stipe");

    owner2.addPet(new VirtualPet("Mrki", "ribica"));
    owner2.addPet(new VirtualPet("MjauMjau", "Tigrasta domaca"));

    int n;
    cout << "koliko akcija zelite" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        owner1.performActions();
        owner2.performActions();
    }

    cout << "Vlasnik 1 - " << owner1.getName() << "- ljubimci:\n";
    for (const auto& pet : owner1.getPets()) {
        cout << "  " << pet->getName() << ": Sreca - " << pet->getHappiness() << ", Glad - " << pet->getHunger() << "\n";
    }

    cout << "\nVlasnik 2 - " << owner2.getName() << "- ljubimci:\n";
    for (const auto& pet : owner2.getPets()) {
        cout << "  " << pet->getName() << ": Sreca - " << pet->getHappiness() << ", Glad - " << pet->getHunger() << "\n";
    }

    for (const auto& pet : owner1.getPets()) {
        delete pet;
    }
    for (const auto& pet : owner2.getPets()) {
        delete pet;
    }

    return 0;
}
