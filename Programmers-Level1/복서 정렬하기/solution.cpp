#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Boxer {
  int number;
  int weight;
  int h_cnt;
  double rate;
};

bool comp(Boxer a, Boxer b);

vector<int> solution(vector<int> weights, vector<string> head2head) {
  vector<int> answer;
  vector<Boxer> boxers(weights.size());

  for (int i = 0; i < boxers.size(); i++) {
    int standard = weights[i];
    int h_cnt = 0;
    int w_cnt = 0;
    int game = 0;

    for (int j = 0; j < head2head[i].size(); j++) {
      if (i != j && head2head[i][j] == 'W') {
        game++;
        w_cnt++;
        if (standard < weights[j]) h_cnt++;
      } else if (i != j && head2head[i][j] == 'L')
        game++;
    }

    boxers[i].number = i + 1;
    boxers[i].weight = standard;
    boxers[i].h_cnt = h_cnt;
    boxers[i].rate = game != 0 ? (double)w_cnt / game * 100 : 0;
  }

  sort(boxers.begin(), boxers.end(), comp);

  for (int i = 0; i < boxers.size(); i++) answer.push_back(boxers[i].number);

  return answer;
}

bool comp(Boxer a, Boxer b) {
  if (a.rate != b.rate)
    return a.rate > b.rate;
  else {
    if (a.h_cnt != b.h_cnt)
      return a.h_cnt > b.h_cnt;
    else {
      if (a.weight != b.weight)
        return a.weight > b.weight;
      else
        return a.number < b.number;
    }
  }
}