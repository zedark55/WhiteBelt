/*

���� ��� ����� ����� A � B � ��������� �� 0 �� 1 000 000 ������������. �������� ���������, ������� ��������� ����� ����� �������� �� ������� A �� B.

���� B = 0, �������� "Impossible".

������
stdin	stdout
10 2	5
3 5	    0
11 0	Impossible

*/



#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (b == 0) {
		cout << "Impossible";
	}
	else {
		cout << a / b;
	}

	return 0;
}