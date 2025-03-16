/*

# ���������

����� ���������� ����������� ���� �����, ���� ���� �� ��� ����� �������� ������������� ���� � ������. 
��������, ����� �eat� ����� �������� ������������� ���� ����� �tea�, ������� ��� ����� �������� ����������� ���� �����. 
���� ���� ����, ��������� ��� ������ �� ���, �������� �� ����� ���� ���� ����������� ���� �����.

��������

���� �� �������� �������� ����, �������� �� ����� ����������� ���� �����, ����������� � ���������. 
��� ������� ����� � ������� ������� ����������, ������� ��� � �� ����������� ������ �����. 
���� ��� ����� ���� ��� ������� ����� (� ��� ����������� � ������� �������� ��������� ==), �� ����� �������� ����������� ���� �����, � ��������� ������ �� ��������.

��� ���� ���������� ������ ������� �� ����� ������ ������� � ��������� ������� BuildCharCounters.

## ������ �����

������� ���� ����� ��� ���� N, ����� � N ������� ���������� ���� ����, ������� ���������� ���������. 
�������������, ��� ��� ����� ������� ���� �� �������� ��������� ����.

## ������ ������

�������� N �����: ��� ������ �������� ���� ���� YES, ���� ��� ����� �������� �����������, � NO � ��������� ������.

## ������

����
3
eat tea
find search
master stream

�����
YES
NO
YES

*/

#include<iostream>
#include<map>
#include<vector>


using namespace std;

map<char, int> Build_char_counters(const string& w1) {
	map<char, int> char_counters;
	for (const auto& word : w1) {
		++char_counters[word];
	}
	return char_counters;
}

void print_result(const vector<string>& vec) {
	for (const auto& answer : vec) {
		cout << answer << endl;
	}
}


int main(int argc, char *argv[]) {
	int n = 0;
	vector<string>result;
	string w1, w2;
	cin >> n;
	while (n > 0) {
		cin >> w1 >> w2;
		if (Build_char_counters(w1) == Build_char_counters(w2)) {
			result.push_back("YES");
		}
		else {
			result.push_back("NO");
		}
		--n;
	}
	print_result(result);


	return 0;
}