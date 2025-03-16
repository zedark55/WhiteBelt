/*

���������

�������� �������, �������
���������� IsPalindrom
���������� bool
��������� �������� ���� string � ����������, �������� �� ���������� ������ �����������

��������� - ��� ����� ��� �����, ������� ��������� �������� ����� ������� � ������ ������. ������ ������ �������� �����������.

�������� �������	���������
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
	// ���������: ����� ���������� ���� �� ������������ ����� ��� size_t ������
	// int � �������� �� ������� �� Ƹ���� �����
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