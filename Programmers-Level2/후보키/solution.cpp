#include <bitset>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool checkMinimality(vector<int> comb, int cur);

int solution(vector<vector<string>> relation) {
  int answer = 0;
  int cardinality = relation.size();
  int degree = relation[0].size();
  vector<int> comb;

  // Extract every possible combination of attribute for getting candidate key
  for (int i = 1; i < (1 << degree); i++) {
    set<string> s;

    for (int j = 0; j < cardinality; j++) {
      // Get element made by current key
      string current = "";

      for (int k = 0; k < degree; k++) {
        if (i & (1 << k))
          current += relation[j][k] + ' ';
      }
      s.insert(current);
    }

    // Check uniqueness and minimality
    if (s.size() == cardinality && checkMinimality(comb, i))
      comb.push_back(i);
  }

  answer = comb.size();

  return answer;
}

bool checkMinimality(vector<int> comb, int cur) {
  // Check wheter is has a attribute that is a already candidate key
  for (int i = 0; i < comb.size(); i++) {
    if ((comb[i] & cur) == comb[i])
      return false;
  }
  return true;
}