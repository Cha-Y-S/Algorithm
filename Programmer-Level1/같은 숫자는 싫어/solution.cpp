#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
  vector<int> answer;
  int prevNum = arr[0];

  answer.push_back(prevNum);
  for(int i = 1; i < arr.size(); i++){
    if(arr[i] == prevNum) continue;
    else{
      prevNum = arr[i];
      answer.push_back(prevNum);
    }
  }

  return answer;
}