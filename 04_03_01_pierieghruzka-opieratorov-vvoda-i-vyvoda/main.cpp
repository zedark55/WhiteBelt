#include <iostream>
#include <iomanip>
#include <sstream>


using namespace std;

struct Duration {
	int hour;
	int min;

	Duration(int h = 0, int m = 0) {
		hour = h;
		min = m;
	}
};

Duration ReadDuration(istream& stream) { // после перегрузки >> больше не нужна
	int h = 0;
	int m = 0;
	stream >> h;
	stream.ignore(1);
	stream >> m;
	return Duration{ h,m };
}

void PrintDuration(ostream& stream, const Duration& duration) { // после перегрузки << больше не нужна
	stream << setfill('0') << setw(2) << duration.hour << ':'
		<< setw(2) << duration.min;
}

ostream& operator<<(ostream& stream, const Duration& duration) {

	stream << setfill('0') << setw(2) << duration.hour << ':'
		<< setw(2) << duration.min;
	return stream;
}

istream& operator>>(istream& stream, Duration& duration) {
	stream >> duration.hour;
	stream.ignore(1);
	stream >> duration.min;
	return stream;
}

int main() {
	
	stringstream dur_ss("01:50");
	Duration dur1;
	dur_ss >> dur1;
	//Duration dur1 = ReadDuration(dur_ss);
	//PrintDuration(cout, dur1);
	cout << dur1<<endl;
	operator<<(operator<<(cout, "hello"), " world"); // отсюда вывод что << должен возвращать не void а ссылку на поток
	
	return 0;
}