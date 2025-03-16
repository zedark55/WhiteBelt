/*

Ќаибольший общий делитель

¬ stdin даны два натуральных числа. ¬ыведите в stdout их наибольший общий делитель.

ѕример
stdin	stdout
25 27	1
12 16	4
13 13	13

*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;


int main() {

	int num1, num2;
	int nod = 1;
	vector <int> vec_num1, vec_num2,sum;

	cin >> num1 >> num2;

	//while (num1 > 1)
	//{
	//	if (num1 % 2 == 0) {
	//		num1 = num1 / 2;
	//		vec_num1.push_back(2);
	//	}
	//	else if (num1 % 3 == 0) {
	//		num1 = num1 / 3;
	//		vec_num1.push_back(3);
	//	}
	//	else if (num1 % 5 == 0) {
	//		num1 = num1 / 5;
	//		vec_num1.push_back(5);
	//	}
	//	else break;

	//}

	//while (num2 > 1)
	//{
	//	if (num2 % 2 == 0) {
	//		num2 = num2 / 2;
	//		vec_num2.push_back(2);
	//	}
	//	else if (num2 % 3 == 0) {
	//		num2 = num2 / 3;
	//		vec_num2.push_back(3);
	//	}
	//	else if (num2 % 5 == 0) {
	//		num2 = num2 / 5;
	//		vec_num2.push_back(5);
	//	}
	//	else break;

	//}

	//set_intersection(vec_num1.begin(), vec_num1.end(),
	//	vec_num2.begin(), vec_num2.end(),
	//	back_inserter(sum));


	//if (sum.size() > 0) {
	//	for (auto i : sum) {
	//		nod *= i;
	//	}
	//}
	//cout << nod<<endl;

	//============================================================= другое решение алгоритмом евклида

	  // пока оба числа положительны, будем их уменьшать, не мен€€ их Ќќƒ
	while (num1 > 0 && num2 > 0) {
		// возьмЄм большее из чисел и заменим его остатком от делени€ на второе
		// действительно, если a и b дел€тс€ на x, то a - b и b дел€тс€ на x
		// тогда и a % b и b дел€тс€ на x, так что можно a заменить на a % b
		if (num1 > num2) {
			num1 %= num2;
		}
		else {
			num2 %= num1;
		}
	}

	// если одно из чисел оказалось равно нулю, значит, на последней итерации
	// большее число разделилось на меньшее
	cout << num1 + num2;

	return 0;
}