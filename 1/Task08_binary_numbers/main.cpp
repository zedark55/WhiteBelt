/*

�������� �����
�� ���� ���� ����� ������������� ����� N. �������� ��� � �������� ������� ��������� ��� ������� �����.

������
stdin	stdout
5		101
32		100000
1		1
���������
����� N ����� ��������� � ���������� ���� int

�������� �������� �� ���������� ������� ��������� � ��������, ����� ���� ������, ��������, �����:
https://www.yaklass.ru/p/informatika/7-klass/informatciia-i-informatcionnye-protcessy-14542/tcifrovye-dannye-dvoichnoe-kodirovanie-teksty-izobrazheniia-13124/re-3a0a87ac-1664-460c-8e45-95e4e4ba543d

� ���� ������ ��� ����� ����������� ��������� vector; ����������, ��� ���������� �������� x � ����� ������� v �������� ���: v.push_back(x);

*/

#include <iostream>
#include <vector>

using namespace std;


int main() {
	
	int N;
	vector <int> binary;
	cin >> N;

	while (N > 0) {
		binary.push_back(N % 2);
		N /= 2;
	}

	for (int i = binary.size() - 1; i >= 0; --i) {
		cout << binary[i];
	}

	
	return 0;
}