/*

����������� �����
�������� ������� MoveStrings, ������� ��������� ��� ������� �����, source � destination, � ���������� ��� ������ �� ������� ������� � ����� �������. 
����� ���������� ������� ������ source ������ ��������� ������.

����� �������� ���������� �������, ���� ������� � ���� ����� clear:

vector<string> words = {"hey", "hi"};
words.clear();
// ������ ������ words ����

������
vector<string> source = {"a", "b", "c"};
vector<string> destination = {"z"};
MoveStrings(source, destination);
// source ������ ��������� ������
// destination ������ ��������� ������ "z", "a", "b", "c" ������ � ����� �������

*/

#include <iostream>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& vec1, vector<string>& vec2) {

	for (auto i : vec1) {
		vec2.push_back(i);
	}

	vec1.clear();

}

int main() {
	
	vector<string> source = { "a","b","c" };
	vector<string> destination = { "z" };
	MoveStrings(source, destination);
	for (auto i : destination) {
		cout << i << " ";
	}
	
	return 0;
}