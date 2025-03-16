#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;

struct Duration {
	int hour;
	int min;

	Duration(int h = 0, int m = 0) {
		int total = h * 60 + m;
		hour = total / 60;
		min = total % 60;
	}
};


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

Duration operator+(const Duration& lhs, const Duration& rhs) {
	return Duration{ lhs.hour + rhs.hour,lhs.min + rhs.min };
}

void PrintVector(const vector<Duration>& durs) {
	for (const auto& d : durs) {
		cout << d << ' ';
	}
	cout << endl;
}

bool operator<(const Duration& lhs, const Duration rhs) {
	if (lhs.hour == rhs.hour) {
		return lhs.min < rhs.min;
	}
	else return lhs.hour < rhs.hour;
}

int main() {

	stringstream dur_ss("01:50");
	Duration dur1;
	Duration dur2 = { 0,25 };
	dur_ss >> dur1;
	cout << dur1 << endl;
	cout << dur1 + dur2<<endl;
	Duration dur3 = dur1 + dur2;
	vector<Duration> vec = { dur3,dur1,dur2 };
	sort(begin(vec), end(vec));
	PrintVector(vec);

	return 0;
}