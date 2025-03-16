/*

�������� ������������������

���������� ������� void Reverse(vector<int>& v), ������� ������������ �������� ������� � �������� �������.

������
vector<int> numbers = {1, 5, 3, 4, 2};
Reverse(numbers);
// numbers ������ ��������� ����� {2, 4, 3, 5, 1}

*/

#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& vec) {
	for (int i = 0; i < vec.size()/2; ++i) {
		int tmp = vec[i];
		vec[i] = vec[vec.size() - i - 1];
		vec[vec.size() - i - 1] = tmp;
	}
}


int main() {
	vector<int> numbers = { 1, 5, 3, 4, 2 };
	Reverse(numbers);
	for (auto i : numbers) {
		cout << i << " ";
	}
	
	return 0;
}