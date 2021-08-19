#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int compare(pair<string, int> a, pair<string, int> b);
int getAmountOfCandidate(string candidate, vector<string> orders);

vector<string> solution(vector<string> orders, vector<int> course) {
  vector<string> answer;
  set<char> menu_set;
  vector<char> menu;

  for (int i = 0; i < orders.size(); i++) {
    for (int j = 0; j < orders[i].size(); j++) {
      if (menu_set.find(orders[i][j]) == menu_set.end()) {
        menu_set.insert(orders[i][j]);
        menu.push_back(orders[i][j]);
      }
    }
  }

  sort(menu.begin(), menu.end());

  for (int i = 0; i < course.size(); i++) {
    vector<bool> v(course[i], true);
    v.insert(v.end(), menu.size() - course[i], false);
    vector<pair<string, int>> candidates;

    do {
      string candidate = "";
      for (int j = 0; j < v.size(); j++) {
        if (v[j]) candidate += menu[j];
      }

      int cnt = getAmountOfCandidate(candidate, orders);

      if (cnt > 1) candidates.push_back({candidate, cnt});
    } while (prev_permutation(v.begin(), v.end()));

    sort(candidates.begin(), candidates.end(), compare);

    int standard;
    if (candidates.empty())
      continue;
    else
      standard = candidates[0].second;
    for (int j = 0; j < candidates.size(); j++) {
      if (candidates[j].second == standard)
        answer.push_back(candidates[j].first);
      else
        break;
    }
  }

  sort(answer.begin(), answer.end());

  return answer;
}

int compare(pair<string, int> a, pair<string, int> b) {
  return a.second == b.second ? a.first < b.first : a.second > b.second;
}

int getAmountOfCandidate(string candidate, vector<string> orders) {
  int result = orders.size();

  for (char c : candidate) {
    for (int i = 0; i < orders.size(); i++) {
      bool isIn = false;
      for (int j = 0; j < orders[i].size(); j++) {
        if (c == orders[i][j]) {
          isIn = true;
          break;
        }
      }
      if (!isIn) {
        orders.erase(orders.begin() + i);
        i--;
        result--;
      }
    }
  }

  return result;
}