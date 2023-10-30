#include "UnosVektoraBrojEl.hpp"
#include <iostream>

using namespace std;

void unosVektoraBrojEl(vector<int> &vektor, int brojEl) {
	int unos;
	cout << "unesite elemente" << endl;

	for (int i = 0; i < brojEl; i++) {
		cin >> unos;
		vektor.push_back(unos);
	}
}