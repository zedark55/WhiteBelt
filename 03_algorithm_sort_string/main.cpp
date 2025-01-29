/*
� ����������� ������ ���� ���� ������, ��������� �� ����� N � ��������� �� ��� N ����� S. ����� ����� ����� � ������ ��������� ��������.

������������ ������ S � ������������������ ������� �� �����������, ��������� ������� ����, � �������� �� � ����������� ����� ������.

�����������
0 <= N <= 1000
1 <= |S| <= 15
������ ������ S[i] ����� �������� �� ��������� ��������: [0-9,a-z,A-Z]
�������

stdin		stdout
2 q A		A q
3 a C b		a b C

���������
�������� �������� �� ������� tolower.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void GetSybol(vector<string>& vec) {

	for (auto& i : vec) {
		cin >> i;
	}
}

int main() {

	int N = 0;
	cin >> N;
	vector<string> vec(N);

	GetSybol(vec);

	sort(begin(vec), end(vec), [](const string& i, const string& j) {
		return lexicographical_compare(begin(i), end(i), begin(j), end(j), [](char ci, char cj) {
			return tolower(ci) < tolower(cj);
			});
		});

	for (const auto& i : vec) cout << " " << i;

	return 0;
}