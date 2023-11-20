#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Karta {
public:
	int broj;
	string zog;

	Karta(int broj, const string& zog) : broj(broj), zog(zog) {};
};

class Igrac {
public:
	string ime;
	vector<Karta> karteIgraca;
	int brojBodova = 0;

	vector<Karta> akuzaSpade;
	vector<Karta> akuzaBastoni;
	vector<Karta> akuzaDinari;
	vector<Karta> akuzaKupe;

	Igrac(string ime, int brojBodova) : ime(ime), brojBodova(brojBodova) {};

	void akuza() {
		akuzaSpade.clear();
		akuzaBastoni.clear();
		akuzaDinari.clear();
		akuzaKupe.clear();

		for (const Karta& karte : karteIgraca) {
			if (karte.zog == "Spade")  {
				if (karte.broj == 1 || karte.broj == 2 || karte.broj == 3) {
					akuzaSpade.push_back(karte);
				}
				if (akuzaSpade.size() == 3) {
					brojBodova += 3;
				}
			}
			if (karte.zog == "Bastoni") {
				if (karte.broj == 1 || karte.broj == 2 || karte.broj == 3) {
					akuzaBastoni.push_back(karte);
				}
				if (akuzaBastoni.size() == 3) {
					brojBodova += 3;
				}
			}
			if (karte.zog == "Dinari") {
				if (karte.broj == 1 || karte.broj == 2 || karte.broj == 3) {
					akuzaDinari.push_back(karte);
				}
				if (akuzaDinari.size() == 3) {
					brojBodova += 3;
				}
			}
			if (karte.zog == "Kupe") {
				if (karte.broj == 1 || karte.broj == 2 || karte.broj == 3) {
					akuzaKupe.push_back(karte);
				}
				if (akuzaKupe.size() == 3) {
					brojBodova += 3;
				}
			}
		}

		int brojacJedinice = 0;
		int brojacDvice = 0;
		int brojacTrice = 0;

		for (const Karta& karte : karteIgraca) {
			if (karte.broj == 1)
				brojacJedinice++;
			else if (karte.broj == 2)
				brojacDvice++;
			else if (karte.broj == 3)
				brojacTrice++;
		}
		if (brojacJedinice == 3) {
			brojBodova += 3;
			brojacJedinice = 0;
		}
		else if (brojacJedinice > 3)
			brojBodova += 1;

		if (brojacDvice == 3) {
			brojBodova += 3;
			brojacDvice = 0;
		}
		else if (brojacDvice > 3)
			brojBodova += 1;

		if (brojacTrice == 3) {
			brojBodova += 3;
			brojacTrice = 0;
		}
		else if (brojacTrice > 3)
			brojBodova += 1;
	}
};

class Mac {
public:
	vector<Karta> karte;

	Mac() {
		for (int j = 0; j < 4; j++) {
			for (int i = 1; i < 11; i++) {
				if (j == 0)
					karte.push_back(Karta(i, "Spade"));
				else if (j == 1)
					karte.push_back(Karta(i, "Kupe"));
				else if (j == 2)
					karte.push_back(Karta(i, "Bastoni"));
				else if (j == 3)
					karte.push_back(Karta(i, "Dinari"));
			}
		}
	}

	void promijesaj() {
		srand(static_cast<unsigned>(std::time(0)));
		random_shuffle(karte.begin(), karte.end());
	}

	void podijeliKarte(Igrac& igrac) {
		for (int i = 0; i < 10; i++) {
			igrac.karteIgraca.push_back(karte.back());
			karte.pop_back();
		}
	}
};

int main() {
	int brojIgraca;
	cout << "unesite broj igraca 2 ili 4" << endl;
	cin >> brojIgraca;

	vector<Igrac> igraci;

	if (brojIgraca == 2) {
		igraci.clear();
		cout << "unesite imena igraca" << endl;
		for (int i = 0; i < brojIgraca; i++) {
			string ime;
			cin >> ime;
			Igrac noviIgrac(ime, 0);
			igraci.push_back(noviIgrac);
		}
	}
	else if (brojIgraca == 4) {
		igraci.clear();
		cout << "unesite imena igraca" << endl;
		for (int i = 0; i < brojIgraca; i++) {
			string ime;
			cin >> ime;
			Igrac noviIgrac(ime, 0);
			igraci.push_back(noviIgrac);
		}
	}
	else {
		cout << "unijeli ste nedozvoljen broj igraca" << endl;
		return 1;
	}

	Mac mac;

	cout << "promijesane karte" << endl;

	mac.promijesaj();
	for (const Karta& karta : mac.karte)
		cout << karta.broj << " " << karta.zog << endl;

	for (int i = 0; i < brojIgraca; i++) {
		mac.podijeliKarte(igraci[i]);
	}

	cout << endl;

	for (int i = 0; i < brojIgraca; i++) {
		cout << "karte igraca " << igraci[i].ime << endl;
		for (const Karta& karte : igraci[i].karteIgraca)
			cout << karte.broj << " " << karte.zog << endl;

		igraci[i].akuza();
		/*cout << "spade" << endl;
		for (const Karta& karte : igraci[i].akuzaSpade)
			cout << karte.broj << " " << karte.zog << endl;
		cout << "bastoni" << endl;
		for (const Karta& karte : igraci[i].akuzaBastoni)
			cout << karte.broj << " " << karte.zog << endl;
		cout << "dinari" << endl;
		for (const Karta& karte : igraci[i].akuzaDinari)
			cout << karte.broj << " " << karte.zog << endl;
		cout << "kupe" << endl;
		for (const Karta& karte : igraci[i].akuzaKupe)
			cout << karte.broj << " " << karte.zog << endl;*/

		cout << endl;
		cout << "broj bodova igraca " << igraci[i].ime << " je " << igraci[i].brojBodova << endl;
		cout << endl;
	}

	int temp = 0;
	for (int i = 0; i < brojIgraca; i++) {
		if (igraci[i].brojBodova > temp)
			temp = igraci[i].brojBodova;
	}

	for (int i = 0; i < brojIgraca; i++) {
		if (igraci[i].brojBodova == temp)
			cout << "pobijedio je igrac " << igraci[i].ime << endl;
	}


	return 0;
}