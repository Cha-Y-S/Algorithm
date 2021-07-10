#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
  int answer = 0;

  sort(citations.begin(), citations.end(), greater<>());

  for (int i = 0; i < citations.size(); i++) {
    int cnt = 0;

    for (int j = 0; j < i + 1; j++) {
      if (citations[j] >= citations[i]) cnt++;
    }

    if (citations[i] >= cnt && cnt > answer) answer = cnt;
  }

  return answer;
}