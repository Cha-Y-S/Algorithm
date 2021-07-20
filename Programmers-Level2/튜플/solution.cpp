#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int compare(vector<int> a, vector<int> b);

vector<int> solution(string s) {
  vector<int> answer;
  vector<vector<int>> tuples;

  // Remove '{', '}' on string s
  s.erase(s.begin(), s.begin() + 1);
  s.erase(s.end() - 1, s.end());

  int i = 0;

  // Process string and push into the vector(tuples)
  while (i < s.size()) {
    string element;
    if (s[i] == '{') {
      i++;
      while (s[i] != '}') {
        element.push_back(s[i]);
        i++;
      }
      i += 2;
    }

    stringstream st;
    st.str(element);

    vector<int> temp;
    while (getline(st, element, ',')) {
      temp.push_back(stoi(element));
    }
    tuples.push_back(temp);
  }

  // sort vector by vector's size in ascending order
  sort(tuples.begin(), tuples.end(), compare);

  // Insert tuple's element
  for (int i = 0; i < tuples.size(); i++) {
    for (int j = 0; j < tuples[i].size(); j++) {
      bool isInclude = false;
      for (int k = 0; k < answer.size(); k++) {
        if (tuples[i][j] == answer[k])
          isInclude = true;
      }
      if (!isInclude)
        answer.push_back(tuples[i][j]);
    }
  }

  return answer;
}

int compare(vector<int> a, vector<int> b) {
  return a.size() < b.size();
}