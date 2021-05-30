#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int p1[5] = {1, 2, 3, 4, 5};
    int p2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int p3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int cnt[3] = {0, 0, 0};

    for(int i = 0; i < answers.size(); i++){
      if(p1[i % 5] == answers[i]){ cnt[0]++; }
      if(p2[i % 8] == answers[i]){ cnt[1]++; }
      if(p3[i % 10] == answers[i]) { cnt[2]++; }
    }

    int mAns = max({cnt[0], cnt[1], cnt[2]});
    if(cnt[0] == mAns){ answer.push_back(1); }
    if(cnt[1] == mAns){ answer.push_back(2); }
    if(cnt[2] == mAns){ answer.push_back(3); }

    return answer;
}