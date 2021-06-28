#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
  int answer = 0;
  priority_queue<int, vector<int>, greater<int>> food;

  for (int i = 0; i < scoville.size(); i++) {
    food.push(scoville[i]);
  }

  while (food.top() < K) {
    if (food.size() < 2) {
      answer = -1;
      break;
    }

    int temp1 = food.top();
    food.pop();
    int temp2 = food.top();
    food.pop();

    food.push(temp1 + (temp2 * 2));

    answer++;
  }

  return answer;
}