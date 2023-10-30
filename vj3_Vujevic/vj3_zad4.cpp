#include <iostream>
#include <vector>

using namespace std;

void removeEl(vector<int> &vektor, int el) {
	
	for (int &each : vektor) {
		if (each == el) {
			each = vektor.back();
			vektor.pop_back();
		}
	}
}

int main() {
	vector<int> vektor = {5, 6, 7, 8};

	removeEl(vektor ,6);

	for (int each : vektor)
		cout << each << " ";

	return 0;
}