#include <iostream>
#include <map>
#include <string>

using namespace std;

#define endl "\n"

string name;
int N, number, scenario;
char tmp;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  scenario = 0;

  while (true) {
    cin >> N;

    if (N == 0) break;

    map<int, pair<string, bool>> student;

    cin.ignore();
    for (int i = 0; i < N; i++) {
      getline(cin, name);

      student[i + 1] = {name, false};
    }

    for (int i = 0; i < 2 * N - 1; i++) {
      cin >> number >> tmp;

      student[number].second = !student[number].second;
    }

    for (pair<int, pair<string, bool>> p : student) {
      if (p.second.second) cout << ++scenario << " " << p.second.first << endl;
    }
  }

  return 0;
}