#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
  int answer = 0;

  sort(d.begin(), d.end());

  int i = 0;
  while (budget > 0 && i < d.size()) {
    budget -= d[i];
    if (budget >= 0) answer++;
    i++;
  }

  return answer;
}