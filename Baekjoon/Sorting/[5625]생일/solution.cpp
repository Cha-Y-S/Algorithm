#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Person {
  string name;
  int year;
  int month;
  int day;
};

vector<Person>
    people;
string name;
int N, year, month, day;

bool cmp(Person a, Person b) {
  if (a.year != b.year) {
    return a.year < b.year;
  } else {
    if (a.month != b.month) {
      return a.month < b.month;
    } else {
      return a.day < b.day;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  people = vector<Person>(N);

  for (int i = 0; i < N; i++) {
    cin >> name >> day >> month >> year;

    people[i].name = name;
    people[i].year = year;
    people[i].month = month;
    people[i].day = day;
  }

  sort(people.begin(), people.end(), cmp);

  cout << people[N - 1].name << endl;
  cout << people[0].name << endl;

  return 0;
}