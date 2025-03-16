#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
	// чтение всей строки getline()
	{
		ifstream stream("date.txt");
		string year, month, day;
		if (stream) {
			getline(stream, year, '-');
			getline(stream, month, '-');
			getline(stream, day, '-');
		}

		cout << year << '-' << month << '-' << day << endl;
	}

	// использование ignore
	{
		ifstream input("date.txt");
		int year1 = 0;
		int month1 = 0;
		int day1 = 0;
		if (input) {
			input >> year1;
			input.ignore(1);
			input >> month1;
			input.ignore(1);
			input >> day1;
			input.ignore(1);
		}
		cout << year1 << " " << month1 << " " << day1 << endl;
	}

	return 0;
}