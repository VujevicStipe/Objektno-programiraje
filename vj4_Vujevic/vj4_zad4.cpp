#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void prevodi(vector<string>& vektor, int n) {
    cout << "Unesite rečenice" << endl;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        vektor.push_back(str);
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    int nasumicno = rand() % n;

    cout << "Nasumičan broj je: " << nasumicno << endl;
    cout << "Nasumična rečenica je: " << vektor[nasumicno] << endl;

    auto tempVektor = vektor[nasumicno];
    string dodatakSamoglasnik = "hay";
    string dodatakSuglasnik = "ay";
    string samoglasnici = "aeiouAEIOU";

    char cilj = ' ';
    size_t pozicija = 0;

    while (pozicija != string::npos) {
        string trenutnaRijec = "";
        size_t pocetakRijeci = pozicija;
        while (pozicija != string::npos && isalpha(tempVektor[pozicija])) {
            trenutnaRijec += tempVektor[pozicija];
            pozicija++;
        }

        if (!trenutnaRijec.empty()) {
            char prvoSlovo = tolower(trenutnaRijec[0]);
            if (samoglasnici.find(prvoSlovo) != string::npos) {
                tempVektor.insert(pocetakRijeci, dodatakSamoglasnik);
                pozicija += dodatakSamoglasnik.length();
            }
            else {
                tempVektor.insert(pocetakRijeci, dodatakSuglasnik);
                pozicija += dodatakSuglasnik.length();
            }
        }
        else {
            pozicija = tempVektor.find(cilj, pozicija + 1);
        }
    }

    cout << "Izmijenjeni string: " << tempVektor << endl;
}

int main() {
    vector<string> vektor;
    int n;

    cout << "Unesite broj rečenica" << endl;
    cin >> n;
    cin.ignore();

    prevodi(vektor, n);

    return 0;
}
