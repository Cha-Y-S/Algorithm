#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int compare(pair<int, double> a, pair<int, double> b);

vector<int> solution(int N, vector<int> stages) {
  vector<int> answer;
  vector<int> notClear;
  vector<int> tryUser;
  vector<pair<int, double>> failure;

  for (int i = 0; i < N; i++) {
    notClear.push_back(0);
    tryUser.push_back(0);
  }

  for (int i = 0; i < stages.size(); i++) {
    if (stages[i] <= N) {
      notClear[stages[i] - 1]++;
    }
    for (int j = 0; j < stages[i]; j++) {
      tryUser[j]++;
      if (j > N) {
        break;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    pair<int, double> temp;
    temp.first = i + 1;
    temp.second = notClear[i] == 0 ? 0 : (double)notClear[i] / tryUser[i];
    failure.push_back(temp);
  }

  sort(failure.begin(), failure.end(), compare);

  for (int i = 0; i < failure.size(); i++) {
    answer.push_back(failure[i].first);
  }

  return answer;
}

int compare(pair<int, double> a, pair<int, double> b) {
  if (a.second == b.second) {
    return a.first < b.first;
  } else {
    return a.second >= b.second;
  }
}