//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//void unosStringova(vector<string>& vektor, int n) {
//    cout << "Unesi stringove:" << endl;
//    cin.ignore();
//
//    for (int i = 0; i < n; i++) {
//        string str;
//        getline(cin, str);
//        reverse(str.begin(), str.end());
//        vektor.push_back(str);
//    }
//
//    sort(vektor.begin(), vektor.end());
//}
//
//int main() {
//    vector<string> vektor;
//    int n;
//
//    cout << "unesi broj stringova: ";
//    cin >> n;
//
//    unosStringova(vektor, n);
//
//    cout << "obrnuti string je: ";
//
//    for (const string& str : vektor)
//        cout << str << " ";
//
//    return 0;
//}
