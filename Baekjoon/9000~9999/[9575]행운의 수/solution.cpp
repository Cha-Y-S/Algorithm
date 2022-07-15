#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

set<int> A, B, C;
set<int> lucky_number;
int T, N, M, K;

void input_data();
bool check_validity(string number);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> T;

  while (T--) {
    input_data();

    for (int a : A) {
      for (int b : B) {
        for (int c : C) {
          int tmp = a + b + c;
          if (check_validity(to_string(tmp))) lucky_number.insert(tmp);
        }
      }
    }

    cout << lucky_number.size() << endl;

    lucky_number.clear();
    A.clear();
    B.clear();
    C.clear();
  }

  return 0;
}

bool check_validity(string number) {
  bool result = true;

  for (int i = 0; i < number.size(); i++) {
    if (number[i] != '5' && number[i] != '8') {
      result = false;
      break;
    }
  }

  return result;
}

void input_data() {
  int data;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> data;

    A.insert(data);
  }

  cin >> M;

  for (int i = 0; i < M; i++) {
    cin >> data;

    B.insert(data);
  }

  cin >> K;

  for (int i = 0; i < K; i++) {
    cin >> data;

    C.insert(data);
  }
}