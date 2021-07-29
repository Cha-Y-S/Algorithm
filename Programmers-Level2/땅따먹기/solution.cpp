#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land) {
  int answer = 0;
  vector<vector<int>> conquer;

  conquer.push_back(land[0]);

  for (int i = 1; i < land.size(); i++) {
    vector<int> temp = land[i];

    temp[0] = max(max(conquer[i - 1][1], conquer[i - 1][2]), conquer[i - 1][3]) + temp[0];
    temp[1] = max(max(conquer[i - 1][0], conquer[i - 1][2]), conquer[i - 1][3]) + temp[1];
    temp[2] = max(max(conquer[i - 1][0], conquer[i - 1][1]), conquer[i - 1][3]) + temp[2];
    temp[3] = max(max(conquer[i - 1][0], conquer[i - 1][1]), conquer[i - 1][2]) + temp[3];

    conquer.push_back(temp);
  }

  answer = max(max(max(conquer[conquer.size() - 1][0], conquer[conquer.size() - 1][1]), conquer[conquer.size() - 1][2]), conquer[conquer.size() - 1][3]);

  return answer;
}