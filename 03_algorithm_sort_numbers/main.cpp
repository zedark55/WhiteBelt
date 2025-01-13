/*
� ����������� ������ ���� ���� ������, ��������� �� N + 1 ����� �����. 
������ ������ ��� ���� ����� N. ����� ������� ��� N �����, ��������� �� �� ������ A. ����� ����� ����� ��������� ��������.

������������ ������ � �� ������ � �������� ��� � ����������� �����. 

�����������
0 <= N <= 1000
-1000000 <= A[i] <= 1000000

�������
stdin		stdout
2 -4 3		3 -4
3 1 -3 2	1 2 -3

���������
������� sort ������������� ��������� ������ ��������

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;

void Print(const vector<int>& vec) {
	for (const auto& i : vec) {
		cout << i << " ";
	}
}

int main () {

	int N = 0;
	cin >> N;
	vector<int> nums;

	for (int i = 0; i < N; ++i) {
		long num;
		cin >> num;
		nums.push_back(num);
	}

	sort(begin(nums), end(nums), [nums](long i, long j) {
		return abs(i) < abs(j);
		}
	);

	Print(nums);
	return 0;
}