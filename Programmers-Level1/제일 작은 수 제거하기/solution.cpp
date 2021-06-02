#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
  vector<int> answer;
  vector<int> temp;

  temp = arr;

  sort(arr.begin(), arr.end(), greater<>());

  int removed = arr.back();

  for(int i = 0; i < arr.size(); i++){
    if(temp[i] != removed) { answer.push_back(temp[i]); }
  }

  if(!answer.size()) answer.push_back(-1);

  return answer;
}