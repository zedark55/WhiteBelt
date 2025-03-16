#include<iostream>
#include<vector>

using namespace std;

int main() {

	int x = 4;
	string y = "hello";

	cout << x << ' ' << y << endl;

	vector<int> d = { 1,3 }; // вывести такой вектор нельзя 
	// cout<<d;

	int a, b;
	cin >> a >> b;
	cout << a + b;

	string name, surname;
	cin >> name >> surname;
	cout << "Hello" << name << ' ' << surname;


	return 0;
}