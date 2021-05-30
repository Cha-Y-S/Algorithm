#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int len = numbers.size();
    vector<bool>v(len-2, false);

    v.insert(v.end(), 2, true);

    do {
        vector<int>partial;
        for(int i = 0 ; i < numbers.size(); i++){
            if(v[i]) { partial.push_back(numbers[i]); }
        }
        int sum = 0;

        for(int i = 0; i < partial.size(); i++){
            sum += partial[i];
        }

        answer.push_back(sum);
    } while(next_permutation(v.begin(), v.end()));

    sort(answer.begin(), answer.end());

    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}