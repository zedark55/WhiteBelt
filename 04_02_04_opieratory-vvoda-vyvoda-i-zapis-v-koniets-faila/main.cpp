#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void ReadAll(const string& path) {
	ifstream input(path);
	if (input) {
		string line;
		while (getline(input, line)) {
			cout << line << endl;
		}
	}
}

int main() {
	const string path = "output.txt";
	{ // перезапись файла
		ofstream output(path);
		if (output) {
			output << "Hello"<<endl;
		}

		ReadAll(path);

	}

	{ // добавление данных
		ofstream output(path, ios::app);
		if (output) {
			output << "world";
		}

		ReadAll(path);
	}

	return 0;
}