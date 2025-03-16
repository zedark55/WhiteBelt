/*

Перемещение строк
Напишите функцию MoveStrings, которая принимает два вектора строк, source и destination, и дописывает все строки из первого вектора в конец второго. 
После выполнения функции вектор source должен оказаться пустым.

Чтобы очистить содержимое вектора, надо вызвать у него метод clear:

vector<string> words = {"hey", "hi"};
words.clear();
// Теперь вектор words пуст

Пример
vector<string> source = {"a", "b", "c"};
vector<string> destination = {"z"};
MoveStrings(source, destination);
// source должен оказаться пустым
// destination должен содержать строки "z", "a", "b", "c" именно в таком порядке

*/

#include <iostream>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& vec1, vector<string>& vec2) {

	for (auto i : vec1) {
		vec2.push_back(i);
	}

	vec1.clear();

}

int main() {
	
	vector<string> source = { "a","b","c" };
	vector<string> destination = { "z" };
	MoveStrings(source, destination);
	for (auto i : destination) {
		cout << i << " ";
	}
	
	return 0;
}