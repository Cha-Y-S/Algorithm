#include <cmath>
#include <queue>
#include <string>

using namespace std;

int solution(string dartResult) {
  int answer = 0;
  vector<int> trySum = {0, 0, 0};
  int cnt = 0;
  queue<char> q;

  for (int i = 0; i < dartResult.size(); i++) {
    if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
      if (q.size() == 2) {
        trySum[cnt] = (q.front() - '0') * 10;
        q.pop();

        trySum[cnt] += q.front() - '0';
        q.pop();
      } else {
        trySum[cnt] = q.front() - '0';
        q.pop();
      }
      switch (dartResult[i]) {
        case 'S':
          trySum[cnt] = pow(trySum[cnt], 1);
          break;
        case 'D':
          trySum[cnt] = pow(trySum[cnt], 2);
          break;
        case 'T':
          trySum[cnt] = pow(trySum[cnt], 3);
          break;
      }
      cnt++;
    } else if (dartResult[i] == '#' || dartResult[i] == '*') {
      switch (dartResult[i]) {
        case '#':
          trySum[cnt - 1] *= -1;
          break;
        case '*':
          if (cnt == 1) {
            trySum[cnt - 1] *= 2;
          } else {
            trySum[cnt - 2] *= 2;
            trySum[cnt - 1] *= 2;
          }
          break;
      }
    } else {
      q.push(dartResult[i]);
    }
  }

  for (int i = 0; i < trySum.size(); i++) {
    answer += trySum[i];
  }

  return answer;
}