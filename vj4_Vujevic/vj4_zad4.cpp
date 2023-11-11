#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void prevodenje(vector<string>& vektor, int n) {
    cout << "Unesi recenice" << endl;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        vektor.push_back(str);
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    int random = rand() % n;

    cout << "Random broj je: " << random << endl;
    cout << "Random string je: " << vektor[random] << endl;

    auto vektorFinal = vektor[random];

    string dodatakSamoglasnik = "hay";
    string dodatakSuglasnik = "ay";

    string rijec;
    for (size_t i = 0; i < vektorFinal.length(); i++) {
        if (isalpha(vektorFinal[i])) {
            rijec += vektorFinal[i];
        }
        else {
            if (!rijec.empty()) {
                if (strchr("aeiouAEIOU", rijec[0]) != nullptr) {
                    vektorFinal.replace(i - rijec.length(), rijec.length(), rijec + dodatakSamoglasnik);
                    i += dodatakSamoglasnik.length();
                }
                else {
                    vektorFinal.replace(i - rijec.length(), rijec.length(), rijec.substr(1) + rijec[0] + dodatakSuglasnik);
                    i += dodatakSuglasnik.length();
                }
                rijec.clear();
            }
        }
    }
    cout << "Prevedena recenica: " << vektorFinal;
}

int main() {
    vector<string> vektor;
    int n;

    cout << "Unesi broj recenica" << endl;
    cin >> n;

    prevodenje(vektor, n);
    
    return 0;
}
