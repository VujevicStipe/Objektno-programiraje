#ifndef VIRTUALPET_H
#define VIRTUALPET_H

#include <string>

using namespace std;

class VirtualPet {
public:
    VirtualPet(const string& name, const string& type, int happiness = 50, int hunger = 50, bool awake = true);

    void eat();
    void sleep();
    void play();

    const string& getName() const;
    const string& getType() const;
    int getHappiness() const;
    int getHunger() const;
    bool isAwake() const;

private:
    string name;
    string type;
    int happiness;
    int hunger;
    bool awake;
};

#endif
