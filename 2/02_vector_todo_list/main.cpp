/*

����������� ����
� ������� �� ��� ���� ������������� ����������� ����, ������ �� ������� ����� ��������� � ���������� ���� ������� ������: 
������ ������ �� �������������, ����������� ����� �� ����� � ��. 
��� ����� ����������� ������ �� ������� ����� ��� �� �����, � ������, ����������� ����� ��������� ��������:

ADD i s
��������� ���� � ��������� s �� ���� i �������� ������.

DUMP i
������� ��� ����, ��������������� �� ���� i �������� ������.

NEXT
������� � ������ ��� �� ����� �����. 
��� ���������� ������ ������� ������ �������� (�������) ������ ��� �� ������� ����� �������� � ���������� �������� (�����) ������ ��� �� ��������� �����: 
��� ���� �� ������� ������ ��� ���������� � ����� ������. 
����� ���������� ������ ������� ����� ������ ��� � ��������� ����� ���������� ��������, � ������ �� ������ ������� ��� ������������. 
��� �������� � ������ ������ ���������� �������� �������� �� ������ ���������� ���� � �������:

���� ��������� ����� ����� ������ ����, ��� �������, ��������������� ��� ���������� �������� ������� (�� ����������� ���);
���� ��������� ����� ����� ������ ����, ��� �������, ���� �� ���� �������� ���� ���������� ����������� �� ��������� ���� ���������� ������.

���������

������� ������� ��� ������� �� ���������, ������ ������� ������ � ������� ������� ��� �������� ������. 
����� ����, ��� �������� ������ ��� �� ��������� �����, �� ����������� ���������� ������.
�������� ��������, ��� ���������� ������ NEXT � ����� ������������������ ������ ��� ������ �� ������� ��� ����� ��������� 11.
��������� ������� ������� ��������� ������.
���������� ���� � ������� ������������� �������������� ��������� � ��� ���� ��������, ��� � ������� ������ 28 ����.
������ �����
������� ����� �������� Q, ����� �������� ��������.

�������� ��� s ��������� � ������� ������ �� ��������� ����, ���� � �������� �������������. 
������ ���� i �������� ������ ������� � ���������� �� 1 �� ������� �������� ������. 

������ ������

��� ������ �������� ���� DUMP � ��������� ������ �������� ���������� ��� � ��������������� ����, � ����� �� ��������, �������� �� ��������. 
������� ������ ��� � ������ ������ �������� �������� �� �����.

������
����							
12									
ADD 5 Salary						
ADD 31 Walk							
ADD 30 WalkPreparations				
NEXT								
DUMP 5								
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28

�����
1 Salary
2 WalkPreparations Walk
0
0
2 WalkPreparations Walk
3 WalkPreparations Walk Payment


*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> days_in_month = { 31,28,31,31,30,31,30,31,30,31,30,31 };

void ADD(const int& i, const string& s, vector<vector<string>>& todo_list) {
	todo_list[i - 1].push_back(s);
}

void DUMP(const int& i, const vector<vector<string>> &todo_list) {
	int count_do = todo_list[i - 1].size();
	cout << count_do<<" ";
	for (auto i : todo_list[ i- 1]) {
		cout << i <<" ";
	}
	cout << endl;
}

void NEXT(int& current_month,const vector<int> &days_in_month, vector<vector<string>>& todo_list) {
	
	int last_days = days_in_month[current_month];
	
	if (current_month == 11) {
		current_month = 0;
	}
	else {
		++current_month;
	}

	int current_days = days_in_month[current_month];

	vector<vector<string>> tmp = todo_list;

	todo_list.resize(current_days);

	if (last_days > current_days) {
		int r = last_days - current_days;
		for (auto i = 0; i < r; ++i) {
			for (size_t j = 0; j < tmp[last_days - 1 - i].size(); ++j) {
				string todo = tmp[last_days - 1 - i][j];
				todo_list[current_days - 1].push_back(todo);
			}
		}
	}
	
}


int main(int argc, char* argv[]) {
	int current_month = 0;
	int n,i = 0;
	string cmd,s = "";
	cin >> n;
	vector<vector<string>> todo_list(days_in_month[current_month]);
	while (n > 0) {
		cin >> cmd;
		if (cmd == "ADD") {
			cin >> i >> s;
			ADD(i, s, todo_list);
		}
		else if (cmd == "DUMP") {
			cin >> i;
			DUMP(i, todo_list);
		}
		else if (cmd == "NEXT") {
			NEXT(current_month, days_in_month, todo_list);
		}
		else {
			cout << "Uknown command";
		}
		--n;
	}
	
	
	return 0;
}