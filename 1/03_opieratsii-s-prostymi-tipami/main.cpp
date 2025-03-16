#include <iostream>

using namespace std;

int main () {

	int x = 4;
	int y = 5;
	cout << (x + y) * (x - y)<<endl;
	if (x == y) {
		cout << "equal" << endl;
	}
	else {
		cout << "not equal" << endl;
	}

	string a = "abc";
	string b = "def";
	if (a < b) {
		cout << "less" << endl;
	}
	else {
		cout << "not less" << endl;
	}



	return 0;
}