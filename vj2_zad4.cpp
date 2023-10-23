#include <iostream>

using namespace std;

struct Matrica {
	float** data;
	int row;
	int col;
};

void unosMatrice(Matrica& mat) {
	cout << "unesite broj redaka pa stupaca";
	cin >> mat.row >> mat.col;

	mat.data = new float* [mat.row];
	for (int i = 0; i < mat.row; i++) {
		mat.data[i] = new float[mat.col];
		for (int j = 0; j < mat.col; j++) {
			cout << "unesite elemente matrice (" << i << ", " << j << "): ";
			cin >> mat.data[i][j];
		}
	}
}

void ispisMatrice(const Matrica& mat) {
	for (int i = 0; i < mat.row; i++) {
		for (int j = 0; j < mat.col; j++) {
			cout << mat.data[i][j] << ' ';
		}
		cout << endl;
	}
}

Matrica zbrajanjeMatrica(const Matrica& mat1, const Matrica& mat2) {
	if (mat1.row != mat2.row || mat1.col != mat2.col) {
		cout << "matrice istih dimentija se ne mogu zbrajati" << endl;
		exit(1);
	}

	Matrica rez;
	rez.col = mat1.col;
	rez.row = mat1.row;
	rez.data = new float* [rez.row];

	for (int i = 0; i < rez.row; i++) {
		rez.data[i] = new float[rez.col];
		for (int j = 0; j < rez.col; j++)
			rez.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
	}

	return rez;
}

int main() {

	Matrica m1, m2;

	cout << "unos prve matrice" << endl;
	unosMatrice(m1);

	cout << "unos druge matrice" << endl;
	unosMatrice(m2);

	cout << "matrica 1" << endl;
	ispisMatrice(m1);

	cout << "matrica 2" << endl;
	ispisMatrice(m2);

	Matrica sum = zbrajanjeMatrica(m1, m2);

	cout << "zbroj matrica je; " << endl;
	ispisMatrice(sum);
	


	return 0;
}