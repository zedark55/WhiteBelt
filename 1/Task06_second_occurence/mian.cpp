/*

������ ���������

���� ������. ������� � ���� ������ ������ ��������� ����� f � �������� ������ ����� ���������. 
���� ����� f � ������ ������ ����������� ������ ���� ���, �������� ����� -1, � ���� �� ����������� �� ����, �������� ����� -2. 
������� ���������� � ����.

������
stdin	stdout
comfort	-1
coffee	3
car	    -2

*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	string str;
	vector<int> indx;
	cin >> str;

	for (auto i = 0; i < str.size(); ++i) {

		if (str[i] == 'f') {
			indx.push_back(i);
		}
		if (indx.size() == 2) {
			break;
		}
	}

	if (indx.size() == 0) {
		cout << -2;
	}
	else if (indx.size() == 1) {
		cout << -1;
	}
	else {
		cout << indx.back();
	}

	return 0;
}