#include "unosVektoraInterval.hpp"
#include <iostream>

using namespace std;

void unosVektoraInterval(vector<int>& vektor, int gornjaGranica, int donjaGranica) {
	vektor.clear();

	int unos;
	cout << "unesite elemente izmedu" << donjaGranica << " i " << gornjaGranica << endl;

	while (true) {
		cin >> unos;

		if (unos < donjaGranica || unos > gornjaGranica)
			break;

		vektor.push_back(unos);
	}
}