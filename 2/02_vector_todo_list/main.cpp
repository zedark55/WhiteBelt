/*

Ежемесячные дела
У каждого из нас есть повторяющиеся ежемесячные дела, каждое из которых нужно выполнять в конкретный день каждого месяца: 
оплата счетов за электричество, абонентская плата за связь и пр. 
Вам нужно реализовать работу со списком таких дел на месяц, а именно, реализовать набор следующих операций:

ADD i s
Назначить дело с названием s на день i текущего месяца.

DUMP i
Вывести все дела, запланированные на день i текущего месяца.

NEXT
Перейти к списку дел на новый месяц. 
При выполнении данной команды вместо текущего (старого) списка дел на текущий месяц создаётся и становится активным (новый) список дел на следующий месяц: 
все дела со старого списка дел копируются в новый список. 
После выполнения данной команды новый список дел и следующий месяц становятся текущими, а работа со старым списком дел прекращается. 
При переходе к новому месяцу необходимо обратить внимание на разное количество дней в месяцах:

если следующий месяц имеет больше дней, чем текущий, «дополнительные» дни необходимо оставить пустыми (не содержащими дел);
если следующий месяц имеет меньше дней, чем текущий, дела со всех «лишних» дней необходимо переместить на последний день следующего месяца.

Замечания

Историю списков дел хранить не требуется, работа ведется только с текущим списком дел текущего месяца. 
Более того, при создании списка дел на следующий месяц, он «перетирает» предыдущий список.
Обратите внимание, что количество команд NEXT в общей последовательности команд при работе со списком дел может превышать 11.
Начальным текущим месяцем считается январь.
Количества дней в месяцах соответствуют Григорианскому календарю с той лишь разницей, что в феврале всегда 28 дней.
Формат ввода
Сначала число операций Q, затем описания операций.

Названия дел s уникальны и состоят только из латинских букв, цифр и символов подчёркивания. 
Номера дней i являются целыми числами и нумеруются от 1 до размера текущего месяца. 

Формат вывода

Для каждой операции типа DUMP в отдельной строке выведите количество дел в соответствующий день, а затем их названия, разделяя их пробелом. 
Порядок вывода дел в рамках каждой операции значения не имеет.

Пример
Ввод							
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

Вывод
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