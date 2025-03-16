#include <iostream>


using namespace std;

int main() {

	int n = 0;
	cin >> n;
	if (n >= 0) {
		int sum = 0;
		while (n > 0) {
			sum += n;
			--n;
		}
		cout << sum<<endl;
	}
	else {
		cout << "please enter positive number"<<endl;
	}

	int a = 5;
	int b;

	do {
		cout << "Guess the number: ";
		cin >> b;
	} while (a!=b);

	cout << "You are right";


	return 0;
}