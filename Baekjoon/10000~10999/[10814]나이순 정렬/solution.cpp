#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compare(pair<int, string> a, pair<int, string> b) {
  return a.first < b.first;
}

int main() {
  int n;

  cin >> n;

  vector<pair<int, string>> member;

  for (int i = 0; i < n; i++) {
    int age;
    string name;
    cin >> age >> name;
    member.push_back(make_pair(age, name));
  }

  stable_sort(member.begin(), member.end(), compare);

  for (int i = 0; i < n; i++) {
    printf("%d %s\n", member[i].first, member[i].second.c_str());
  }

  return 0;
}