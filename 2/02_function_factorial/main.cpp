/*

Факториал

Напишите функцию, которая
называется Factorial
возвращает int
принимает int и возвращает факториал своего аргумента. Гарантируется, что аргумент функции по модулю не превышает 10. Для отрицательных аргументов функция должна возвращать 1.

Аргумент функции	Результат
1						1
-2						1
4						24

*/

#include <iostream>
#include <chrono>

using namespace std;

int Factorial(const int& num) {
	int factorial = 1;
	if (num > 0) {
		for (auto i = 1; i <= num; ++i) {
			factorial *= i;
		}		
	}
	return factorial;
}

int Factorial_recursia(int num) { // тут рекурсия выполняется быстрее, но циклы должны выигрывать по скорости над рекурсией
	if (num <= 1) {
		return 1;
	}
	else {
		return num * Factorial_recursia(num - 1);
	}
}


int main() {

	int num;
	cin >> num;
	auto start = std::chrono::steady_clock::now();
	cout<<Factorial(num)<<endl;
	auto finish = std::chrono::steady_clock::now();
	cout << "Time Factorial " << chrono::duration_cast<chrono::microseconds>(finish - start).count()<<endl;
	
	start = chrono::steady_clock::now();
	cout << Factorial_recursia(num) << endl;
	finish = chrono::steady_clock::now();
	cout << "Factorial_recursia time " << chrono::duration_cast<chrono::microseconds>(finish - start).count();


	return 0;
}