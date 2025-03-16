/*

Реализуйте функцию vector<int> Reversed(const vector<int>& v), возвращающую копию вектора v, в которой числа переставлены в обратном порядке.

Пример
Вектор v	Результат функции
1, 5, 3, 4, 2	2, 4, 3, 5, 1

*/

#include <iostream>
#include <vector>


using namespace std;

vector<int> Reversed(vector<int> vec) {
	for (int i = 0; i < vec.size() / 2; ++i) {
		int tmp = vec[i];
		vec[i] = vec[vec.size() - i - 1];
		vec[vec.size() - i - 1] = tmp;
	}
	return vec;
}

vector<int> Reversed2(const vector<int>& vec) {
	vector<int> reverse_vec;
	for (int i = vec.size() - 1; i >= 0; --i) {
		reverse_vec.push_back(vec[i]);
	}
	return reverse_vec;
}

int main() {
	
	vector<int> vec = { 1,5,3,4,2 };
	for (auto i : Reversed(vec)) {
		cout << i << " ";
	}
	
	return 0;
}