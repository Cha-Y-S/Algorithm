#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> skill;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  skill = vector<int>(4);

  for (int i = 0; i < 4; i++) {
    cin >> skill[i];
  }

  sort(skill.begin(), skill.end());

  cout << abs((skill[3] + skill[0]) - (skill[1] + skill[2])) << endl;

  return 0;
}