#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream input("04_02.txt");
	string str;
	if (input.is_open()) {
		while (getline(input, str)) {
			cout << str << endl;
		}
		cout << "Done!";
	}
	else {
		cout << "Error!";
	}
	return 0;
}