/*

Палиндром

Напишите функцию, которая
называется IsPalindrom
возвращает bool
принимает параметр типа string и возвращает, является ли переданная строка палиндромом

Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево. Пустая строка является палиндромом.

Аргумент функции	Результат
madam				true
gentleman			false
X					true

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(const string& str) {
	string strReverse;
	for (auto i = str.size(); i > 0; --i) {
		strReverse += str[i - 1];
	}
	if (strReverse == str) {
		return true;
	}
	else {
		return false;
	}
}

bool IsPalindrom_another(string s) {
	// Замечание: более правильным было бы использовать здесь тип size_t вместо
	// int О причинах Вы узнаете на Жёлтом поясе
	for (int i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {

	string str;
	cin >> str;
	cout << IsPalindrom(str)<<endl;
	cout << IsPalindrom_another(str) << endl;

	return 0;
}