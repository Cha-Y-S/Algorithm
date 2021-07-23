#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> time);

int main() {
  int size;

  cin >> size;

  vector<int> time(size, 0);

  for (int i = 0; i < time.size(); i++) {
    cin >> time[i];
  }

  cout << solution(time) << endl;

  return 0;
}

int solution(vector<int> time) {
  int answer = 0;

  sort(time.begin(), time.end());

  answer += time[0];

  for (int i = 1; i < time.size(); i++) {
    time[i] += time[i - 1];
    answer += time[i];
  }

  return answer;
}