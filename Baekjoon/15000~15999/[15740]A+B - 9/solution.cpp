#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

#define endl "\n"

void add(bool sign, string a, string b);
void sub(string a, string b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string n1, n2;

  cin >> n1 >> n2;

  if (n1[0] == '-' && n2[0] == '-')
    add(1, n1, n2);
  else if (n1[0] == '-')
    sub(n2, n1);
  else if (n2[0] == '-')
    sub(n1, n2);
  else
    add(0, n1, n2);

  return 0;
}

void add(bool sign, string a, string b) {
  string answer = "";
  int up = 0;

  if (sign) {
    a.erase(a.begin());
    b.erase(b.begin());
  }

  if (a.size() > b.size()) swap(a, b);

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  for (int i = 0; i < a.size(); i++) {
    int sum = a[i] - '0' + b[i] - '0' + up;

    up = sum < 10 ? 0 : 1;
    sum = sum < 10 ? sum : sum % 10;

    answer = to_string(sum) + answer;
  }

  for (int i = a.size(); i < b.size(); i++) {
    int sum = b[i] - '0' + up;

    up = sum < 10 ? 0 : 1;
    sum = sum < 10 ? sum : sum % 10;

    answer = to_string(sum) + answer;
  }

  answer = up == 1 ? to_string(up) + answer : answer;

  answer = sign ? '-' + answer : answer;

  cout << answer;
}

void sub(string a, string b) {
  string answer = "";
  bool sign = false;

  b.erase(b.begin());

  if (a.size() < b.size()) {
    swap(b, a);
    sign = true;
  } else if (a.size() == b.size()) {
    for (int i = 0; i < a.size(); i++) {
      if (a[i] < b[i]) {
        swap(b, a);
        sign = true;
        break;
      } else if (a[i] > b[i]) {
        break;
      }
    }
  }

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  for (int i = 0; i < b.size(); i++) {
    int temp = a[i] - b[i];
    if (temp < 0) {
      a[i + 1] -= 1;
      temp += 10;
    }
    answer = to_string(temp) + answer;
  }

  for (int i = b.size(); i < a.size(); i++) {
    int temp = a[i] - '0';
    if (temp < 0) {
      a[i + 1] -= 1;
      temp += 10;
    }
    answer = to_string(temp) + answer;
  }

  for (int i = 0; i < answer.size(); i++) {
    if (answer[i] == '0') {
      answer.erase(answer.begin());
      i--;
    } else
      break;
  }

  if (answer == "")
    answer = "0";
  else
    answer = sign ? '-' + answer : answer;

  cout << answer << endl;
}