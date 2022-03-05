#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
  vector<int> answer;
  map<string, set<string>> m;
  map<string, int> result;

  for (int i = 0; i < report.size(); i++) {
    stringstream st;
    string reporter, reported;

    st.str(report[i]);

    st >> reporter >> reported;

    m[reporter].insert(reported);
  }

  for (auto p : m) {
    for (string s : p.second) {
      result[s]++;
    }
  }

  for (int i = 0; i < id_list.size(); i++) {
    string reporter = id_list[i];
    int cnt = 0;

    for (string s : m[reporter]) {
      if (result[s] >= k) cnt++;
    }

    answer.push_back(cnt);
  }

  return answer;
}