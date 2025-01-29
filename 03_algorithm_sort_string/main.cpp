/*
В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним N строк S. Между собой число и строки разделены пробелом.

Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя регистр букв, и выведите их в стандартный поток вывода.

Ограничения
0 <= N <= 1000
1 <= |S| <= 15
Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]
Примеры

stdin		stdout
2 q A		A q
3 a C b		a b C

Подсказка
Обратите внимание на функцию tolower.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void GetSybol(vector<string>& vec) {

	for (auto& i : vec) {
		cin >> i;
	}
}

int main() {

	int N = 0;
	cin >> N;
	vector<string> vec(N);

	GetSybol(vec);

	sort(begin(vec), end(vec), [](const string& i, const string& j) {
		return lexicographical_compare(begin(i), end(i), begin(j), end(j), [](char ci, char cj) {
			return tolower(ci) < tolower(cj);
			});
		});

	for (const auto& i : vec) cout << " " << i;

	return 0;
}