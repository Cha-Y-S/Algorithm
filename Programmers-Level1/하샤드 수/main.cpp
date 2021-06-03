#include "solution.h"

void printAnswer(bool result);

int main(){
  
  printAnswer(solution(10));

  printAnswer(solution(12));

  printAnswer(solution(11));

  printAnswer(solution(13));

  return 0;
}

void printAnswer(bool result){
  if(result) cout << "true" << endl;
  else cout << "false" << endl;
}