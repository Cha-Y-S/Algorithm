#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int n);

int solution(vector<int> nums) {
  int answer = 0;
  int len = nums.size();
  vector<bool>v(len-3, false);;


  v.insert(v.end(), 3, true);

  do {
    vector<int>partial;
    for(int i = 0; i < nums.size(); i++){
      if(v[i]) { partial.push_back(nums[i]); }
    }
    int sum = 0;

    for(int i = 0; i < partial.size(); i++){
      sum += partial[i];
    }

    if(isPrime(sum)) answer++;

  } while(next_permutation(v.begin(), v.end()));

  return answer;
}

bool isPrime(int n){
  if (n <= 1) return false;
  if (n % 2 == 0) return false;
  for(int i = 3; i <= sqrt(n); i += 2){
    if(n % i == 0) return false;
  }
  return true;
}
