#include "solution.h"

void printAnswer(bool result);
int main(){

  printAnswer(solution("pPoooyY"));

  printAnswer(solution("Pyy"));

}

void printAnswer(bool result){
  if(result) cout << "true" << endl;
  else cout << "false" <<endl;
}