#include <iostream>
#include <string>

using namespace std;

class Food {
private:
    int static counter;

public:
    Food() {}

    void dodajHranu() {
        counter++;
    }
    void makniHranu() {
        counter--;
    }

    void ispis() {
        cout << "broj dostupne hrane je: " << counter << endl;
    }

    static int get_counter() {
        return counter;
    }

    static void umanjiCounter() {
        counter--;
    }
};

int Food::counter = 4;

int get_counter() {
    return Food::get_counter();
}

class VirtualPet {
private:
    string ime;
    string vrsta;
    int bodovi = 0;
    string status;
    int brojPorcija = 0;

public:
    VirtualPet(string ime, string vrsta, string status, int bodovi = 0) : ime(ime), vrsta(vrsta), status(status), bodovi(bodovi) {}

    bool operator==(const VirtualPet& drugi) const {
        return (ime == drugi.ime) && (vrsta == drugi.vrsta) && (bodovi == drugi.bodovi) && (status == drugi.status);
    }

    bool operator!=(const VirtualPet& drugi) const {
        return !(ime == drugi.ime) && (vrsta == drugi.vrsta) && (bodovi == drugi.bodovi) && (status == drugi.status);
    }

    VirtualPet operator+(const VirtualPet& drugi) {
        return *this = drugi;
    }

    VirtualPet operator++() {
        brojPorcija++;
        bodovi -= 5;

        Food::umanjiCounter();

        return *this;
    }

    VirtualPet operator++(int) {
        return ++(*this);
    }

    bool operator<(const VirtualPet& drugi) {
        return bodovi < drugi.bodovi;
    }

    bool operator<=(const VirtualPet& drugi) {
        return bodovi <= drugi.bodovi;
    }

    bool operator>(const VirtualPet& drugi) {
        return bodovi > drugi.bodovi;
    }

    bool operator>=(const VirtualPet& drugi) {
        return bodovi >= drugi.bodovi;
    }

    friend ostream& operator<<(ostream& os, const VirtualPet drugi) {
        os << drugi.ime << " - " << drugi.vrsta << " - bodovi:" << drugi.bodovi << " - " << drugi.status << " - broj porcija:" << drugi.brojPorcija << endl;
        return os;
    }

};

int main() {
    VirtualPet pet1("mjaumjau", "domaca macka", "sritna", 50);
    VirtualPet pet2("lav", "sibirski sokol", "usamljen", 40);
    VirtualPet pet3 = pet2;

    cout << "dostupno je:" << Food::get_counter() << " porcija hrane" << endl;

    pet1++;

    if (pet2 == pet3) {
        cout << "ljubimci su jednaki\n" << endl;
    }
    
    if (pet2 != pet3) {
        cout << "ljubimci su razliciti\n" << endl;
    }

    ++pet3;

    cout << pet1;
    cout << pet2;
    cout << pet3;

    if (pet1 < pet2 && pet2 < pet3) {
        std::cout << "Ljubimac s najviše bodova:\n " << pet3 << std::endl;
    }
    else if (pet2 < pet1 && pet1 < pet3) {
        std::cout << "Ljubimac s najviše bodova:\n " << pet3 << std::endl;
    }
    else if (pet3 < pet1 && pet1 < pet2) {
        std::cout << "Ljubimac s najviše bodova:\n " << pet2 << std::endl;
    }

    cout << "preostalo je:" << Food::get_counter() << " porcije hrane" << endl;

	return 0;
}