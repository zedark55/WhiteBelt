/*

# Анаграммы

Слова называются анаграммами друг друга, если одно из них можно получить перестановкой букв в другом. 
Например, слово «eat» можно получить перестановкой букв слова «tea», поэтому эти слова являются анаграммами друг друга. 
Даны пары слов, проверьте для каждой из них, являются ли слова этой пары анаграммами друг друга.

Указание

Один из способов проверки того, являются ли слова анаграммами друг друга, заключается в следующем. 
Для каждого слова с помощью словаря подсчитаем, сколько раз в нём встречается каждая буква. 
Если для обоих слов эти словари равны (а это проверяется с помощью обычного оператора ==), то слова являются анаграммами друг друга, в противном случае не являются.

При этом построение такого словаря по слову удобно вынести в отдельную функцию BuildCharCounters.

## Формат ввода

Сначала дано число пар слов N, затем в N строках содержатся пары слов, которые необходимо проверить. 
Гарантируется, что все слова состоят лишь из строчных латинских букв.

## Формат вывода

Выведите N строк: для каждой введённой пары слов YES, если эти слова являются анаграммами, и NO в противном случае.

## Пример

Ввод
3
eat tea
find search
master stream

Вывод
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