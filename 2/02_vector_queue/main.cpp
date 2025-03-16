/*

�������
���� ����� � �������, �� ������� �� ������ �� � ������, ���� ����� ��������� � ����� � ������� ������. 
����� ����, ������ ��������� ���� ����� ���������� � �������� ������������ ��-�� ����, ��� ������� �� ������������.

����� �������, ��� ���� � ������� ���������� ������ �������, ������� � 0.

���������� ��������� ��������� �������� ��� ��������:

WORRY i: �������� i-�� �������� � ������ ������� ��� ��������������;
QUIET i: �������� i-�� �������� ��� ��������������;
COME k: �������� k ��������� ������� � ����� �������;
COME -k: ������ k ������� �� ����� �������;
WORRY_COUNT: ������ ���������� ������������� ����� � �������.
���������� ������� �����.

������ �����
���������� �������� Q, ����� �������� ��������.

��� ������ �������� WORRY i � QUIET i �������������, ��� ������� � ������� i ���������� � ������� �� ������ ��������.

��� ������ �������� COME -k �������������, ��� k �� ������ �������� ������� �������.

������ ������
��� ������ �������� WORRY_COUNT �������� ���� ����� ����� � ���������� ������������� ����� � �������.

������
����	�����
8	    1
COME 5	2
WORRY 1
WORRY 4
COME -2
WORRY_COUNT
COME 3
WORRY 3
WORRY_COUNT

��������
��� ����������� ���� ��������� ������� v2 � ����� ������� v1 ������ ������������ ����� insert:

v1.insert(end(v1), begin(v2), end(v2));
����� ����, ��������� ������� ����� ���� ����� ���, � ��� ����� � ������ ������. 
��������, ```vector<vector> � ��� ������, ���������� �������� �������� ������� ����� ����� (�� ���� ��������� ������). 
������ �������������:

vector<vector<int>> m(10); // ������ ������ �� ������ �������� ����� �����
m[0].push_back(5);  // ��������� �������� � ������ ������
m[0].push_back(15);
cout << m[0][1]; // ������� 15 � ������ ������� ������� �������

m[1].push_back(3);
for (int x : m[1]) {
    // ���������� ��� �������� �������
}

*/

#include <iostream>
#include <vector>


using namespace std;

void WORRY(vector<vector<string>>& vec, const int& person) {
    vec[person][0] = "worry";
}

void QUIET(vector<vector<string>>& vec, const int& person) {
    vec[person][0] = "quiet";
}

void COME(vector<vector<string>>& vec, const int& person) {
    if (person > 0) {
        vector<string> one_person = { "quiet" };
        for (int i = 0; i < person; ++i) {
            vec.push_back(one_person);
        }
    }
    else {
        for (int i = person; i < 0; ++i) {
            vec.pop_back();
        }
    }
}

int WORRY_COUNT(const vector<vector<string>>& vec) {
    int worry_count = 0;
    for (auto i : vec) {
        if (i[0] == "worry") {
            worry_count++;
        }
    }
    return worry_count;
}


int main(int argc, char* argv[])
{
    vector<vector<string>> vec;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string cmd = "";
        int person = 0;
        cin >> cmd;

        if (cmd == "WORRY")
        {
            cin >> person;
            WORRY(vec, person);
        }
        else if (cmd == "QUIET")
        {
            cin >> person;
            QUIET(vec, person);
        }
        else if (cmd == "COME")
        {
            cin >> person;
            COME(vec, person);
        }
        else if (cmd == "WORRY_COUNT") {
            cout << WORRY_COUNT(vec);
        }
        else cout << "Uknown Command";

    }
    return 0;
}