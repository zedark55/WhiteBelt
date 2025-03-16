/*

Очередь
Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда. 
Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.

Будем считать, что люди в очереди нумеруются целыми числами, начиная с 0.

Реализуйте обработку следующих операций над очередью:

WORRY i: пометить i-го человека с начала очереди как беспокоящегося;
QUIET i: пометить i-го человека как успокоившегося;
COME k: добавить k спокойных человек в конец очереди;
COME -k: убрать k человек из конца очереди;
WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
Изначально очередь пуста.

Формат ввода
Количество операций Q, затем описания операций.

Для каждой операции WORRY i и QUIET i гарантируется, что человек с номером i существует в очереди на момент операции.

Для каждой операции COME -k гарантируется, что k не больше текущего размера очереди.

Формат вывода
Для каждой операции WORRY_COUNT выведите одно целое число — количество беспокоящихся людей в очереди.

Пример
Ввод	Вывод
8	    1
COME 5	2
WORRY 1
WORRY 4
COME -2
WORRY_COUNT
COME 3
WORRY 3
WORRY_COUNT

Указание
Для дописывания всех элементов вектора v2 в конец вектора v1 удобно использовать метод insert:

v1.insert(end(v1), begin(v2), end(v2));
Кроме того, элементом вектора может быть любой тип, в том числе и другой вектор. 
Например, ```vector<vector> — это вектор, элементами которого являются вектора целых чисел (то есть двумерный массив). 
Пример использования:

vector<vector<int>> m(10); // Создаём вектор из десяти векторов целых чисел
m[0].push_back(5);  // Добавляем элементы в первый вектор
m[0].push_back(15);
cout << m[0][1]; // Выведет 15 — второй элемент первого вектора

m[1].push_back(3);
for (int x : m[1]) {
    // Перебираем все элементы второго
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