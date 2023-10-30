#include "ispisVektora.hpp"
#include <iostream>

using namespace std;

void ispisVektora(vector<int>& vektor) {
	cout << "vektor je: " << endl;
	for (int i : vektor)
		cout << i << endl;
}