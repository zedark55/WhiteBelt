/*

Средняя температура
Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней. 
Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.

Гарантируется, что среднее арифметическое значений температуры является целым числом.

Формат ввода
Вводится число N, затем N неотрицательных целых чисел — значения температуры в 0-й, 1-й, ... (N−1)-й день.

Формат вывода
Первое число K — количество дней, значение температуры в которых выше среднего арифметического. Затем K целых чисел — номера этих дней.

Пример
Ввод		Вывод
5			3
7 6 3 0 9	0 1 4

*/

#include<iostream>
#include<vector>

using namespace std;

int average_temperature(const vector<int>& vec_days) {
	int average_temperature = 0;
	for (auto i : vec_days) {
		average_temperature += i;
	}
	return average_temperature / vec_days.size();
}



int main() {
	
	int n,tmp,temperature;
	cin >> n;
	vector<int> vec,days;

	for (auto i = 0; i < n; ++i) {
		cin >> tmp;
		vec.push_back(tmp);
	}

	temperature = average_temperature(vec);

	for (size_t i = 0; i < vec.size(); ++i) {
		if (vec[i] > temperature) {
			days.push_back(i);
		}
	}

	cout << days.size()<<endl;

	for (auto i : days) {
		cout << i << " ";
	}

	
	
	return 0;
}