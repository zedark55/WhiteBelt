/*
В стандартном потоке дана одна строка, состоящая из N + 1 целых чисел. 
Первым числом идёт само число N. Далее следуют ещё N чисел, обозначим их за массив A. Между собой числа разделены пробелом.

Отсортируйте массив А по модулю и выведите его в стандартный поток. 

Ограничения
0 <= N <= 1000
-1000000 <= A[i] <= 1000000

Примеры
stdin		stdout
2 -4 3		3 -4
3 1 -3 2	1 2 -3

Подсказка
Функция sort дополнительно принимает третий аргумент

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;

void Print(const vector<int>& vec) {
	for (const auto& i : vec) {
		cout << i << " ";
	}
}

int main () {

	int N = 0;
	cin >> N;
	vector<int> nums;

	for (int i = 0; i < N; ++i) {
		long num;
		cin >> num;
		nums.push_back(num);
	}

	sort(begin(nums), end(nums), [nums](long i, long j) {
		return abs(i) < abs(j);
		}
	);

	Print(nums);
	return 0;
}