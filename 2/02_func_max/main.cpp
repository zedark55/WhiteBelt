/*

������������
�������� ������� UpdateIfGreater, ������� ��������� ��� ������������� ���������: first � second. ���� first �������� ������ second, 
���� ������� ������ ���������� � second �������� ��������� first. 
��� ���� ��������� ������� �� ������ ������ ����������, � ��������� ��������� second ������ ���� ����� �� ���������� �������.

������
3 4

���������
� ������ ������ ��� ����� �������������� ������� ���� ��� ���������� ������� UpdateIfGreater. 
���������, ����� �� ��� ������ ���� �������, � ����� ����� ���� ������ int. ��� ���� ������ ������ �������� ������ �������:

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