#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
  int answer = 0;
  vector<bool> eratos(n+1, true);
  eratos[0] = false;
  eratos[1] = false;

  for(int i = 2; i < n + 1; i++){
    if(eratos[i]){ answer++; }

    for(int j = i; j < n + 1; j += i){
      eratos[j] = false;
    }
    // print eratos
    // cout << "=====" << i <<"=====" << endl;

    // for(int k = 0; k < eratos.size(); k++){
    //   if(k == 0) continue;
    //   cout << eratos[k] << " ";
    //   if(k % 10 == 0) { cout << endl; }
    // }

    // cout << endl;
  }

  
  
  return answer;
}