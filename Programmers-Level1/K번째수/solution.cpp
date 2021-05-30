#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int i = 0; i < commands.size(); i++){
      vector<int>partial;
      vector<int>command = commands[i];
      int lIndex = command[0] - 1;
      int rIndex = command[1] - 1;
      int marker = command[2];

      for(int j = lIndex; j < rIndex + 1; j++){
        partial.push_back(array[j]);
      }

      sort(partial.begin(), partial.end());

      answer.push_back(partial[marker - 1]);
    }

    return answer;
}