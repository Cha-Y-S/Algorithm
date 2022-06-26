#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define endl "\n"

stack<char> stk;
string str;
int T, res;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  T = 1;

  while(true){
    cin >> str;

    if(str[0] == '-') break;

    res = 0;

    for(int i = 0; i < str.size(); i++){
      if(str[i] == '}' && !stk.empty() && stk.top() == '{')
        stk.pop();
      else
        stk.push(str[i]);
    }

    while(!stk.empty()){
      char c1= stk.top();
      stk.pop();

      char c2 = stk.top();
      stk.pop();

      if(c1 == c2) res++;
      else res += 2;
    }

    cout << T++ << ". " << res << endl;
  }

  return 0;
}