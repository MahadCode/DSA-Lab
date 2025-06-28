#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

bool isEqual(string s, string t){
    stack<char> stk1;
    int l1=s.length();

    for(int i=0; i<l1; i++){
        char ch=s[i];
        if(ch!='#'){
          stk1.push(ch);
        }
        else{
          if(!stk1.empty()){
            stk1.pop();
          }
        }
    }

    stack<char> stk2;
    int l2=t.length();

    for(int i=0; i<l2; i++){
        char ch=t[i];
        if(ch!='#'){
          stk2.push(ch);
        }
        else{
            if(!stk1.empty()){
                stk1.pop();
            }
        }
    }

    while(!stk1.empty() && !stk2.empty()){
        if(stk1.top()!=stk2.top()){
            return false;
        }
        stk1.pop();
        stk2.pop();
    }

    if(stk1.empty() && stk2.empty()){
      return true;
    }
    
    return false;
}

int main(){
    cout << isEqual("c###", "#");
}