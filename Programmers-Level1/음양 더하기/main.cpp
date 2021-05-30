#include "plus_negnpos.h"
#include <iostream>


int main(){
  vector<int>a;
  vector<bool>s;

  a.push_back(4);
  a.push_back(7);
  a.push_back(12);

  s.push_back(true);
  s.push_back(false);
  s.push_back(true);

  cout << solution(a, s) << endl;

  return 0;
}