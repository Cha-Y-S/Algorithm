#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
  int answer = 0;
  vector<int> temp = nums;

  sort(temp.begin(), temp.end());

  temp.erase(unique(temp.begin(), temp.end()), temp.end());

  answer = (temp.size() <= (nums.size() / 2)) ? temp.size() : nums.size() / 2;

  return answer;
};