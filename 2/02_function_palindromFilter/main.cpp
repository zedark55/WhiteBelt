/*

Напишите функцию, которая

называется PalindromFilter
возвращает vector
принимает vector words и int minLength и возвращает все строки из вектора words, которые являются палиндромами и имеют длину не меньше minLength
Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.

Примеры
words	minLength	результат
abacaba, aba	5	abacaba
abacaba, aba	2	abacaba, aba
weew, bro, code	4	weew
На проверку пришлите файл с реализацией функции PalindromFilter. Ваш файл может содержать и другие функции, если они вам необходимы. 
В этой задаче ваша программа не обязана что-то считывать из stdin и записывать в stdout — тестирующая система будет вызывать вашу функцию PalindromFilter напрямую.

*/

#include<iostream>
#include<vector>

using namespace std;

bool isPalindrom(const string& str) {

	for (int i = 0; i < str.size() / 2; ++i) {
		if (str[i] != str[str.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

vector<string> PalindromFilter(const vector<string>& vec, const int& lenght) {

	vector<string> result;

	for (string i : vec) {

		if (isPalindrom(i) && i.size() >= lenght) {
			result.push_back(i);
		}
	}

	return result;

}

int main() {

	vector<string> vec1 = { "abacaba","aba" };
	vector<string> vec2 = { "weew", "bro", "code" };

	for (auto i : PalindromFilter(vec1, 5)) {
		cout << i << endl;
	}
	for (auto i : PalindromFilter(vec1, 2)) {
		cout << i << endl;
	}
	for (auto i : PalindromFilter(vec2, 4)) {
		cout << i << endl;
	}
	return 0;
}