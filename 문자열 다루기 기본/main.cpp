#include "solution.h"

void printSolution(bool result);

int main(){
  
  printSolution(solution("a234"));

  printSolution(solution("1234"));

  return 0;
}

void printSolution(bool result){
  if(result){
    cout << "true" << endl;
  } else{
    cout << "false" << endl;
  };
}