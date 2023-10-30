//#include "UnosVektoraBrojEl.hpp"
//#include "ispisVektora.hpp"
//#include "unosVektoraInterval.hpp"
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void mergeVektor(vector<int>& vektor1, vector<int> &vektor2, vector<int> &vektorFinal) {
//	for (int each1 : vektor1) {
//		bool flag = false;
//		for (int each2 : vektor2) {
//			if (each1 == each2) {
//				flag = true;
//				break;
//			}
//		}
//		if (flag == false)
//			vektorFinal.push_back(each1);
//	}
//}
//
//int main() {
//	vector<int> vektor1, vektor2, vektorFinal;
//
//	unosVektoraBrojEl(vektor1, 4);
//	unosVektoraBrojEl(vektor2, 2);
//
//	mergeVektor(vektor1, vektor2, vektorFinal);
//	ispisVektora(vektorFinal);
//
//	return 0;
//}