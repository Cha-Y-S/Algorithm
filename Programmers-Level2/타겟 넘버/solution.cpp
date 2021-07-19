#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
  int answer = 0;
  queue<pair<int, int>> q;

  q.push(make_pair(0, numbers[0]));
  q.push(make_pair(0, -numbers[0]));

  while (!q.empty()) {
    int index = q.front().first;
    int sum = q.front().second;

    q.pop();

    if (index == numbers.size() - 1) {
      if (sum == target)
        answer++;
      continue;
    }

    int cs1 = sum + numbers[index + 1];
    int cs2 = sum - numbers[index + 1];

    q.push(make_pair(index + 1, cs1));
    q.push(make_pair(index + 1, cs2));
  }

  return answer;
}