#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, int> pii;

vector<pii> grade;
vector<int> question;
int res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  grade = vector<pii>(8, {0, 0});
  res = 0;

  for (int i = 0; i < 8; i++) {
    cin >> grade[i].first;
    grade[i].second = i + 1;
  }

  sort(grade.begin(), grade.end(), greater<>());

  for (int i = 0; i < 5; i++) {
    res += grade[i].first;
  }

  cout << res << endl;

  for (int i = 0; i < 5; i++) {
    question.push_back(grade[i].second);
  }

  sort(question.begin(), question.end());

  for (int i = 0; i < 5; i++) {
    cout << question[i] << " ";
  }
  cout << endl;

  return 0;
}