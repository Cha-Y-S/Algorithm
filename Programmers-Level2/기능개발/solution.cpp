#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;

  while (!progresses.empty()) {
    for (int i = 0; i < progresses.size(); i++) {
      progresses[i] = progresses[i] >= 100 ? 100 : progresses[i] + speeds[i];
    }

    int done = 0;
    bool isDone = false;
    while (*progresses.begin() == 100 && progresses.size() > 0) {
      progresses.erase(progresses.begin(), progresses.begin() + 1);
      speeds.erase(speeds.begin(), speeds.begin() + 1);
      done++;
      isDone = true;
    }

    if (isDone)
      answer.push_back(done);
  }

  return answer;
}