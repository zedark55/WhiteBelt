/*

������ ��������� ������

�������� ��������� ���������� ��������� ������� ������ � ������ ������. 
���� �������� ��������� ������ ������ A ������, �� �� �� ��������������� ������ � X ���������. 
���� �������� ��������� ������ ������ B ������, �� �� �� ��������������� ������ � Y ���������.

�� ���� ��������� ���� ���� ������������ �����: N, A, B, X, Y (A < B) - ��� N - �������� ��������� ������. 
�������� ��������� ������� ������ � ������ ������.

������
stdin	            stdout
100 110 120 5 10	100
115 110 120 5 10	109.25
150 110 120 5 12.5	131.25

*/



#include <iostream>


using namespace std;

int main() {

	double n, a, b, x, y;
	cin >> n >> a >> b >> x >> y;

	if (n > a && n< b) {
		cout << n * (1 -(x / 100));
	}
	else if (n > b) {
		cout << n * (1 - (y / 100));
	}
	else {
		cout << n;
	}


	return 0;
}