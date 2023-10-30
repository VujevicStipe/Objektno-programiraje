//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//
//using namespace std;
//
//int main() {
//	vector<int> vektor = {4, 2, 7, 5};
//
//	sort(vektor.begin(), vektor.end());
//
//	auto minEl = min_element(vektor.begin(), vektor.end());
//	vektor.insert(minEl, 0);
//
//	auto maxEl = max_element(vektor.begin(), vektor.end());
//	
//	int suma = accumulate(maxEl + 1, vektor.end(), 0);
//
//	for (int each : vektor)
//		cout << each << endl;
//
//	cout << "suma je: " << suma << endl;
//
//	return 0;
//}