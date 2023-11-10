//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void fixString(string &str, char &target) {
//	size_t pos = str.find(target);
//
//	while (pos != string::npos) {
//		if (str[pos - 1] == ' ' && str[pos] == ',') {
//			str.replace(pos - 1, 1, ",");
//			if (str[pos + 1] != ' ') {
//				str.replace(pos, 1, " ");
//			}
//			else {
//				str.replace(pos, 1, "");
//			}
//			pos = str.find(target, pos + 1);
//		}
//	}
//}
//
//int main() {
//	string str = "Ja bih ,ako ikako mogu ,ovu recenicu , napisala ispravno.";
//	char target = ',';
//
//	fixString(str, target);
//
//	cout << str << endl;
//
//	return 0;
//}
