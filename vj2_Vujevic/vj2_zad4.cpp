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

Matrica operatori(const Matrica& mat1, const Matrica& mat2, char operacija) {
    Matrica rez;

    if (operacija == '+' || operacija == '-') {
        if (mat1.row != mat2.row || mat1.col != mat2.col) {
            cout << "matrice ne odgovaraju" << endl;
            exit(1);
        }
        rez.col = mat1.col;
        rez.row = mat1.row;
        rez.data = new float* [rez.row];

        for (int i = 0; i < rez.row; i++) {
            rez.data[i] = new float[rez.col];
            for (int j = 0; j < rez.col; j++) {
                if (operacija == '+') {
                    rez.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
                }
                else if (operacija == '-') {
                    rez.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
                }
            }
        }
    }
    else if (operacija == '*') {
        if (mat1.col != mat2.row) {
            cout << "matrice ne odgovaraju" << endl;
            exit(1);
        }
        rez.row = mat1.row;
        rez.col = mat2.col;
        rez.data = new float* [rez.row];

        for (int i = 0; i < rez.row; i++) {
            rez.data[i] = new float[rez.col];
            for (int j = 0; j < rez.col; j++) {
                rez.data[i][j] = 0;
                for (int k = 0; k < mat1.col; k++) {
                    rez.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
                }
            }
        }
    }
    else {
        exit(1);
    }

    return rez;
}

Matrica transponiranje(const Matrica& mat1) {
    Matrica tMat;
    tMat.row = mat1.col;
    tMat.col = mat1.row;
    tMat.data = new float* [tMat.row];

    for (int i = 0; i < tMat.row; i++) {
        tMat.data[i] = new float[tMat.col];
        for (int j = 0; j < tMat.col; j++)
            tMat.data[i][j] = mat1.data[j][i];
    }

    return tMat;
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

	Matrica zbroj = operatori(m1, m2, '+');
    Matrica razlika = operatori(m1, m2, '-');
    Matrica umnozak = operatori(m1, m2, '*');

	cout << "zbroj matrica je; " << endl;
	ispisMatrice(zbroj);

    cout << "razlika matrica je: " << endl;
    ispisMatrice(razlika);

    cout << "umnozak je: " << endl;
    ispisMatrice(umnozak);

    Matrica tm1 = transponiranje(m1);
    Matrica tm2 = transponiranje(m2);

    cout << "transponirana prva matrica: " << endl;
    ispisMatrice(tm1);

    cout << "transponirana prva matrica: " << endl;
    ispisMatrice(tm2);
	
	return 0;
}