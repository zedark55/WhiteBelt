/*
# ���������� ��������� - 1

���������� ������� �������� ���������� ���������. ��� ����� ������������ ��������� �������:

* **NEW_BUS bus stop_count stop1 stop2 ...** � �������� ������� �������� � ��������� bus � stop_count ����������� � ���������� stop1, stop2, ...
* **BUSES_FOR_STOP stop** � ������� �������� ���� ��������� ��������, ���������� ����� ��������� stop.
* **STOPS_FOR_BUS bus** � ������� �������� ���� ��������� �������� bus �� ������� ���������, �� ������� ����� ��������� �� ������ �� ���������.
* **ALL_BUSES** � ������� ������ ���� ��������� � �����������.

## ������ �����

� ������ ������ ����� ���������� ���������� �������� Q, ����� � Q ������� ������� �������� ��������.

�������������, ��� ��� �������� ��������� � ��������� ������� ���� �� ��������� ����, ���� � ������ �������������.

��� ������� ������� **NEW_BUS bus stop_count stop1 stop2 ...
** �������������, ��� ������� bus �����������, ���������� ��������� ������ 0, � ����� ����� stop_count ������� ������ ����� ���������� �������� ���������, 
������ ��� �������� � ������ ������ ��������.

## ������ ������

��� ������� �������, ����� **NEW_BUS**, �������� ��������������� ����� �� ����:

* �� ������ **BUSES_FOR_STOP stop** �������� ����� ������ ������ ���������, ����������� ����� ��� ���������, � ��� �������, � ������� ��� ����������� ��������� NEW_BUS. 
���� ��������� stop �� ����������, �������� No stop.
* �� ������ **STOPS_FOR_BUS bus** �������� �������� ��������� �������� bus � ��������� ������� � ��� �������, � ������� ��� ���� ������ � ��������������� ������� NEW_BUS. 
�������� ������ ��������� stop ������ ����� ��� Stop stop: bus1 bus2 ..., 
��� bus1 bus2 ... � ������ ���������, ����������� ����� ��������� stop, � �������, � ������� ��� ����������� ��������� NEW_BUS, �� ����������� ��������� �������� bus. 
���� ����� ��������� stop �� ��������� �� ���� �������, ����� bus, ������ ������ ��������� ��� �� �������� no interchange. ���� ������� bus �� ����������, �������� No bus.
* �� ������ **ALL_BUSES** �������� �������� ���� ��������� � ���������� �������. 
�������� ������� �������� bus ������ ����� ��� Bus bus: stop1 stop2 ...,
��� stop1 stop2 ... � ������ ��������� �������� bus � �������, � ������� ��� ���� ������ � ��������������� ������� NEW_BUS. 
���� �������� �����������, �������� No buses.

### ��������������

������� ������ ���� �������� ����� ������ �������. ���� �� �� ������� � ���, ��� �� �������� �� �����, ����������� ������� ��� ���.

## ������

### ����

```
10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES
```

### �����

```
No buses
No stop
No bus
32 32K
Stop Vnukovo: 32 32K 950
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950
Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
Bus 32: Tolstopaltsevo Marushkino Vnukovo
Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
```


*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

void NEW_BUS(map<string, vector<string>>& bus) {
	int count = 0;
	string name, stop_name;
	cin >> name>>count;
	vector<string> stop_name_vec;
	while (count > 0) {
		cin >> stop_name;
		stop_name_vec.push_back(stop_name);
		--count;
	}
	bus[name] = stop_name_vec;
}

string ALL_BUSES(const map<string, vector<string>>& bus) {
	string output;
	for (const auto& i : bus) {
		string name = i.first;
		vector<string> stop_name = i.second;
		output += name;
		output += ": ";
		for (const auto& j : stop_name) {
			output += j;
			output += " ";
		}
	}
	return output;
}



int main(int argc, char* argv[]) {
	
	int Q = 0;
	vector<string> output;
	map<string, vector<string>> bus;
	cin >> Q;

	while (Q > 0) {
		string cmd;
		cin >> cmd;
		if (cmd == "NEW_BUS") {
			NEW_BUS(bus);
		}
		else if (cmd == "ALL_BUSES") {
			output.push_back(ALL_BUSES(bus));
		}
		--Q;
	}

	for (const auto& i : output) {
		cout << i<<endl;
	}

	return 0;
}