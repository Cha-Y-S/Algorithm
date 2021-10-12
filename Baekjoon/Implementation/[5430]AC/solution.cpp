#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> arr;
string method, input;
int T, N, head, tail;
bool flag;

void print_arr();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  for (; T > 0; T--) {
    cin >> method >> N >> input;

    string temp = input.substr(1, input.size() - 2);
    stringstream st(temp);
    string number;
    head = 0;
    tail = N;
    flag = true;

    while (getline(st, number, ','))
      arr.push_back(stoi(number));

    for (int i = 0; i < method.size(); i++) {
      if (method[i] == 'R') {
        if (flag) {
          int temp = head - 1;
          head = tail - 1;
          tail = temp;
        } else {
          int temp = head + 1;
          head = tail + 1;
          tail = temp;
        }
        flag = !flag;
      } else {
        if (flag) {
          if (head > tail) break;
          head++;
        } else {
          if (head < tail) break;
          head--;
        }
      }
    }

    print_arr();

    arr.clear();
  }

  return 0;
}

void print_arr() {
  if (flag) {
    if (head > tail) {
      cout << "error" << endl;
      return;
    }
    cout << "[";
    for (int i = head; i < tail; i++) {
      cout << arr[i];
      if (i + 1 != tail) cout << ",";
    }
    cout << "]" << endl;
  } else {
    if (head < tail) {
      cout << "error" << endl;
      return;
    }
    cout << "[";
    for (int i = head; i > tail; i--) {
      cout << arr[i];
      if (i - 1 != tail) cout << ",";
    }
    cout << "]" << endl;
  }
}