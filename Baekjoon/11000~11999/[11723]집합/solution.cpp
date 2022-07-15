#include <iostream>
#include <map>
#include <string>

using namespace std;

#define endl "\n"

string query;
map<string, int> command;
int M, target, s;

void add_set(int n);
void remove_set(int n);
void check_set(int n);
void toggle_set(int n);
void all_set();
void empty_set();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> M;

  command = {{"add", 0}, {"remove", 1}, {"check", 2}, {"toggle", 3}, {"all", 4}, {"empty", 5}};

  for (int i = 0; i < M; i++) {
    cin >> query;

    switch (command[query]) {
      case 0:
        cin >> target;
        add_set(target - 1);
        break;
      case 1:
        cin >> target;
        remove_set(target - 1);
        break;
      case 2:
        cin >> target;
        check_set(target - 1);
        break;
      case 3:
        cin >> target;
        toggle_set(target - 1);
        break;
      case 4:
        all_set();
        break;
      case 5:
        empty_set();
        break;
      default:
        break;
    }
  }

  return 0;
}

void add_set(int n) {
  s |= (1 << n);
}

void remove_set(int n) {
  if ((s & (1 << n)) != 0)
    s ^= (1 << n);
}

void check_set(int n) {
  cout << ((s & (1 << n)) != 0 ? 1 : 0) << endl;
}

void toggle_set(int n) {
  if ((s & (1 << n)) != 0)
    remove_set(n);
  else
    add_set(n);
}

void all_set() {
  s = 0;
  for (int i = 0; i < 20; i++) {
    s += (1 << i);
  }
}

void empty_set() {
  s = 0;
}