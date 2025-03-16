/*

¬ стандартном потоке даны три строки, разделЄнные пробелом. 
 ажда€ строка состоит из строчных латинских букв и имеет длину
	не более 30 символов. 
¬ыведите в стандартный вывод лексикографически минимальную из них.


stdin	                stdout
milk milkshake month	milk
c a b					a
fire fog wood			fire

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	string str1, str2, str3;
	cin >> str1 >> str2 >> str3;

	if (str1 <= str2 && str1 <= str3) {
		cout << str1<<endl;
	}
	else if (str2 <= str1 && str2 <= str3) {
		cout << str2<<endl;
	}
	else {
		cout << str3<<endl;
	}
	
	//======================================== другое решение

	vector<string> vec = { str1,str2,str3 };
	sort(begin(vec), end(vec));
	cout << vec[0];


	return 0;
}