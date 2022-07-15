#include <iostream>
#include <set>
#include <string>

using namespace std;

#define endl "\n"

set<string, greater<string>> company;
string name, info;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> name >> info;

    if (info == "enter") {
      company.insert(name);
    } else {
      company.erase(name);
    }
  }

  for (string person : company) {
    cout << person << endl;
  }

  return 0;
}