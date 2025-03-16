/*

Максимизатор
Напишите функцию UpdateIfGreater, которая принимает два целочисленных аргумента: first и second. Если first оказался больше second, 
Ваша функция должна записывать в second значение параметра first. 
При этом указанная функция не должна ничего возвращать, а изменение параметра second должно быть видно на вызывающей стороне.

Пример
3 4

Замечание
В данной задаче вам нужно самостоятельно выбрать типы для параметров функции UpdateIfGreater. 
Подумайте, какой из них обязан быть ссылкой, а какой может быть просто int. При этом учтите разные варианты вызова функции:

UpdateIfGreater(x, y);
UpdateIfGreater(5, y)

*/

#include <iostream>



using namespace std;


void UpdateIfGreater(const int& x, int& y) {
	if (x > y) {
		y = x;
		cout << " Y changed "<<y<<endl;
	}
}

int main() {
	
	int x = 5;
	int y = 0;

	UpdateIfGreater(4, y);

	UpdateIfGreater(x, y);
	
	return 0;
}