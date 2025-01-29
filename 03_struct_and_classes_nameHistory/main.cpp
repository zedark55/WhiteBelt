/*
История имени

Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
  }
private:
  // приватные поля
};

Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени. 
При этом с течением времени могут открываться всё новые факты из прошлого человека, 
поэтому года́ в последовательных вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.

Гарантируется, что все имена и фамилии непусты.

Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и фамилию человека по состоянию на конец данного года.

Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".
Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните "last_name with unknown first name".
Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните "first_name with unknown last name".

Пример

Код
int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}

Вывод
Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria Sergeeva
Polina Volkova
Appolinaria Volkova

*/


#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        year_to_firstname[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        year_to_lastname[year] = last_name;
    }
    string GetFullName(int year) {
        if (isIncognito(year)) {
            return "Incognito";
        }
        else if (isNoChangeFirstName(year)) {
            return GetLastName(year) + " with unknown first name";
        }
        else if (isNoChangeLastName(year)) {
            return GetFirstName(year) + " with unknown last name";
        }
        else {
            return GetFirstName(year) + " " + GetLastName(year);
        }
    }
    string GetFullNameWithHistory(int year) {
        // получить все имена и фамилии по состоянию на конец года year
        if (isIncognito(year)) {
            return "Incognito";
        }
        else if (isNoChangeFirstName(year)) {
            return GetLastName(year) + " with unknown first name";
        }
        else if (isNoChangeLastName(year)) {
            return GetFirstName(year) + " with unknown last name";
        }
        else {
            return GetFirstNameWithHistory(year) + " " + GetLastNameWithHistory(year);
        }
    }

private:
    string GetFirstName(int year) {
        int lastChangeYear = year;
        for (const auto& i : year_to_firstname) {
            if (i.first <= year) {
                lastChangeYear = i.first;
            }
            else {
                break;
            }
        }
        return year_to_firstname[lastChangeYear];
    }
    string GetLastName(int year) {
        int lastChangeYear = year;
        for (const auto& i : year_to_lastname) {
            if (i.first <= year) {
                lastChangeYear = i.first;
            }
            else {
                break;
            }
        }
        return year_to_lastname[lastChangeYear];
    }
    string GetFirstNameWithHistory(int year) {
        int lastChangeYear = year;
        string historyChange = "";
        vector<string> vec_firstname;
        for (const auto& i : year_to_firstname) {
            if (i.first <= year) {
                lastChangeYear = i.first;
                vec_firstname.push_back(year_to_firstname[lastChangeYear]);
            }
            else {
                break;
            }
        }
        for (auto i = 0; i<vec_firstname.size() - 1;++i) {
            if (vec_firstname[i] != vec_firstname[i + 1]) {
                historyChange.append(vec_firstname[i]);
            }
        }
        return historyChange.empty()
            ? year_to_firstname[lastChangeYear]
            : year_to_firstname[lastChangeYear] + "(" + historyChange + ")";
    }
    string GetLastNameWithHistory(int year) {
        int lastChangeYear = year;
        string historyChange = "";
        vector<string> vec_lastname;
        for (const auto& i : year_to_lastname) {
            if (i.first <= year) {
                lastChangeYear = i.first;
                vec_lastname.push_back(year_to_lastname[lastChangeYear]);
            }
            else {
                break;
            }
        }
        for (auto i = 0; i < vec_lastname.size() - 1; ++i) {

            if (vec_lastname[i] != vec_lastname[i + 1]) {
                historyChange.append(vec_lastname[i]);
            }
        }
        return historyChange.empty()
            ? year_to_lastname[lastChangeYear]
            : year_to_lastname[lastChangeYear] + "(" + historyChange + ")";
    }

    bool isIncognito(int year) {
        return isNoChangeFirstName(year) && isNoChangeLastName(year);
    }

    bool isNoChangeFirstName(int year) {
        int count = 0;
        for (const auto& i : year_to_firstname) {
            if (i.first <= year) {
                count++;
            }
        }
        return count == 0;
    }

    bool isNoChangeLastName(int year) {
        int count = 0;
        for (const auto& i : year_to_lastname) {
            if (i.first <= year) {
                count++;
            }
        }
        return count == 0;
    }

    map<int, string> year_to_firstname;
    map<int, string> year_to_lastname;
};


int main() {
    
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;
    
    return 0;
}