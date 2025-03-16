#include <iostream>
#include <vector>

using namespace std;


int main() {

	int a = 11;
	double b = 3; // если будет int то результат булет целый

	cout << a / b << endl;

	int x = 5;
	x += 2;
	x -= 2;
	x *= 2;
	x /= 2;
	x++;
	++x;
	cout << x << endl;

	int q = x++;
	int d = ++x;
	cout << "q=" << q << endl;
	cout << "d=" << d << endl;

	return 0;
}