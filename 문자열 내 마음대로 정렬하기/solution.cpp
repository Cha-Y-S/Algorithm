#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, char> a, pair<string, char> b);

vector<string> solution(vector<string> strings, int n) {
  vector<string> answer;

  vector<pair<string, char>> sPair;

  for(int i = 0; i < strings.size(); i++){
    pair<string, char> temp;
    temp.first = strings[i];
    temp.second = temp.first[n];
    sPair.push_back(temp);
  }

  sort(sPair.begin(), sPair.end(), compare);

  for(int i = 0; i< sPair.size(); i++){
    answer.push_back(sPair[i].first);
  }

  return answer;
}

bool compare(pair<string, char> a, pair<string, char> b){
  if(a.second == b.second){
    return a.first < b.first;
  } else {
    return a.second < b.second;
  }
}