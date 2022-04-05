#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<string> words;
int N;

int cmp(string a, string b) {
  if (a.length() != b.length()) {
    return a.length() < b.length();
  } else {
    int a_sum = 0;
    int b_sum = 0;
    for (int i = 0; i < a.length(); i++) {
      if (isdigit(a[i])) {
        a_sum += a[i] - '0';
      }
      if (isdigit(b[i])) {
        b_sum += b[i] - '0';
      }
    }
    if (a_sum == b_sum) {
      return a < b;
    } else {
      return a_sum < b_sum;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  words = vector<string>(N);

  for (int i = 0; i < N; i++) {
    cin >> words[i];
  }

  sort(words.begin(), words.end(), cmp);

  for (int i = 0; i < N; i++) {
    cout << words[i] << endl;
  }

  return 0;
}