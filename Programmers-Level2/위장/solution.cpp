#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
  int answer = 0;
  unordered_map<string, string> h;

  for (int i = 0; i < clothes.size(); i++) {
    h.insert(make_pair(clothes[i][1], clothes[i][0]));
  }

  // for (pair<string, string> e : h) {
  //   cout << "key: " << e.first << "\t";
  //   cout << "value: " << h.at(e.first) << endl;
  // }

  return answer;
}