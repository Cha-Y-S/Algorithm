#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Job {
  int location;
  int priority;
  Job(int loc, int prior) : location(loc), priority(prior) {}
};

int findMaxPriority(queue<Job> j);

int solution(vector<int> priorities, int location) {
  int answer = 0;
  int finish = -1;
  queue<Job> j;

  for (int i = 0; i < priorities.size(); i++) {
    Job temp(i, priorities[i]);
    j.push(temp);
  }

  while (finish != location) {
    if (j.front().priority >= findMaxPriority(j)) {
      answer++;
      finish = j.front().location;
      j.pop();
    } else {
      j.push(j.front());
      j.pop();
    }
  }

  return answer;
}

int findMaxPriority(queue<Job> j) {
  queue<Job> temp = j;
  int max = 0;
  int size = temp.size();

  for (int i = 0; i < size; i++) {
    if (temp.front().priority > max) max = temp.front().priority;
    temp.pop();
  }
  cout << endl;

  return max;
}