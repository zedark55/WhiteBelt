#include <iostream>
#include <vector>


using namespace std;



int main() {
	int x = 6;
	x = 9;
	cout << x << endl;

	string s = "hello";
	string t = s;

	t += ", world";

	cout << "s = "<< s<< endl;
	cout << "t = " << t << endl;


	vector<string> w = { "a","b","c" };
	vector<string> v;

	v = w;
	v[0] = "d";

	cout << w[0] << " " << w[1] << " " << w[2] << endl;
	cout << v[0] << " " << v[1] << " " << v[2] << endl;




	return 0;
}