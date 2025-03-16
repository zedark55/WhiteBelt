#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {

	string s = "abcfg";

	for (char c : s) {
		cout << c << ",";
	}

	cout << endl;

	vector<int> nums = { 1,2,3,4,5 };
	for (int c : nums) {
		cout << c << ",";
	}

	cout << endl;

	vector<string> nums_string = { "1","2","3","4","5_5"};
	for (auto c : nums_string) {
		cout << c << ",";
	}

	cout << endl;

	int quantity = 0;
	for (auto c : nums) {
		if (c == 5) {
			quantity += 1;
		}
	}
	cout << "There are " << quantity << " fives"<<endl;

	quantity = count(begin(nums), end(nums), 5);
	cout << quantity; 

	sort(begin(nums), end(nums));

	return 0;
}