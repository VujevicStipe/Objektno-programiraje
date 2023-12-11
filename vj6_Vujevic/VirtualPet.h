#ifndef VIRTUALPET_H
#define VIRTUALPET_H

#include <string>

class VirtualPet {
public:
    VirtualPet(const std::string& name, const std::string& type, int happiness = 50, int hunger = 50, bool awake = true);

    void eat();
    void sleep();
    void play();

    const std::string& getName() const;
    const std::string& getType() const;
    int getHappiness() const;
    int getHunger() const;
    bool isAwake() const;

private:
    std::string name;
    std::string type;
    int happiness;
    int hunger;
    bool awake;
};

#endif
