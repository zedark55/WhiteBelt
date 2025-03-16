#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {

	int a = 4;
	int b = 6;
	if (a < b) {
		cout << "A is less than b"<<endl;
	}
	else {
		cout << "b is less than a"<<endl;
	}

	string c = "fire";
	string d = "water";
	if (c < d) { // сравнивается лексиграфически
		cout << "c is less than d"<<endl;
	}
	else {
		cout << "d is less than c"<<endl;
	}

	vector<string> q = { "fire","water" };
	vector<string> w = { "air","fog" };
	if (q < w) { 
		cout << "q is less than w" << endl;
	}
	else {
		cout << "w is less than q or they equal" << endl;
	}

	map<string, int> mapa1;
	mapa1["one"] = 1;
	map<string, int> mapa2;
	if (mapa1 < mapa2) {
		cout << "m1 is less than m2" << endl;
	}
	else {
		cout << "m2 is less than m1 or they equal" << endl;
	}

	string string1 = "abc";
	if (!string1.empty() && string1 < "zzz") {
		cout << string1 << endl;
	}


	return 0;
}