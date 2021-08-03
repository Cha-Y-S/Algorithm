#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
  int answer = 0;
  vector<string> str1_set;
  vector<string> str2_set;
  int nUnion = 0;
  int nIntersection = 0;
  double similarity;

  // Get Multiset of string
  for (int i = 0; i < str1.size() - 1; i++) {
    if (isalpha(tolower(str1[i])) && isalpha(tolower(str1[i + 1]))) {
      string temp = "";
      temp += tolower(str1[i]);
      temp += tolower(str1[i + 1]);

      str1_set.push_back(temp);
    }
  }

  for (int i = 0; i < str2.size() - 1; i++) {
    if (isalpha(tolower(str2[i])) && isalpha(tolower(str2[i + 1]))) {
      string temp = "";
      temp += tolower(str2[i]);
      temp += tolower(str2[i + 1]);

      str2_set.push_back(temp);
    }
  }

  if (!str1_set.size() && !str2_set.size()) return answer = 65536;

  nUnion = str1_set.size() + str2_set.size();

  sort(str1_set.begin(), str1_set.end());
  sort(str2_set.begin(), str2_set.end());

  // Get intersection set of str1's multiset and str2's multiset
  vector<string> inter(nUnion);
  auto it = set_intersection(str1_set.begin(), str1_set.end(), str2_set.begin(), str2_set.end(), inter.begin());
  inter.erase(it, inter.end());

  nIntersection = inter.size();

  nUnion -= nIntersection;

  answer = (double)nIntersection / nUnion * 65536;

  return answer;
}