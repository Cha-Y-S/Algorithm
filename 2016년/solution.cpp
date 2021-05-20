#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
  string answer = "";
  int mon[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  string day[] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
  int dSum = 0;

  for(int i = 0; i < a - 1; i++){
    dSum += mon[i];
  }
  dSum += b;

  answer = day[dSum%7];

  return answer;
}