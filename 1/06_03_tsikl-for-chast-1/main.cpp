#include <iostream>
#include <vector>
#include <map>


using namespace std;


int main() {
	vector<int> vec = { 2,4,6,7,8,10 };
	map<string, int> map = { {"a",1},{"b",2},{"c",3} };
	string str = "sfagasdasda";


	int sum_vec = 0;
	int sum_map = 0;
	int find = 0;
	string concat;

	for (auto i : vec) {
		sum_vec += i;
	}

	for (auto j : map) {
		concat += j.first;
		sum_map += j.second;
	}

	for (auto s : str) {
		if (s == 'a') {
			cout <<"Find "<<find << endl;
		}
		++find;
	}

	for (auto i = 0; i < str.size(); ++i) {
		if (str[i] == 'a') {
			cout<<i;
		}
	}

	cout << sum_vec<<endl;
	cout << sum_map<<endl;
	cout << concat<<endl;

	for (auto i = 0; i < str.size(); ++i) {
		if (str[i] == 'a') {
			cout<<i;
			break;
		}
	}

	return 0;
}