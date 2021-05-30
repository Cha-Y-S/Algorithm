#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs){
  int size = absolutes.size();
  int answer = 0;
  for(int i = 0; i < size; i++){
    if(signs[i]){
      answer += absolutes[i];
    } else{
      answer -= absolutes[i];
    }
  }
  return answer;
}