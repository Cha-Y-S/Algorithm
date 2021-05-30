#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
  string answer = "";
  string lower = "";
  string upper = "";
  
  for(int i = 0; i < s.size(); i++){
    if(s[i] >= 'a' && s[i] <= 'z') { lower.push_back(s[i]); }
    else { upper.push_back(s[i]); }
  }

  sort(lower.begin(), lower.end(), greater<>());
  sort(upper.begin(), upper.end(), greater<>());

  answer = lower + upper;

  return answer;
}