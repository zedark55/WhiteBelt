#include <iostream>
#include <vector>

using namespace std;	


int main() {

	vector<int> nums = { 1,2,3,4 };
	for (auto x : nums) {
		cout << x << endl;
	}

	int n = 5;
	int sum = 0;
	int h = 1;

	for (auto i = 0; i < n; ++i) {
		cout << i << endl;
	}

	while (h <= n) {

		sum += h;
		h++;
	}

	cout << sum << endl;

	return 0;
}