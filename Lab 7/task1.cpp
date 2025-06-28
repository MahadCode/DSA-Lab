#include<iostream>
#include"s.cpp"
#include<vector>
using namespace std;

string removeKdigits(string num,int k){
    Stack<char> ansSt;
    int l=num.length();

    for(int i=0; i<l; i++){
        char ch=num[i];
        while(!ansSt.empty() && ansSt.top()>ch && k>0){
            ansSt.pop();
            k--;
        }
        ansSt.push(ch);
    }

    while(k>0 && !ansSt.empty()){
        ansSt.pop();
        k--;
    }
    

    string ans="";
    while(!ansSt.empty()){
       ans = ansSt.top() + ans;
       ansSt.pop();
    }
    
    return ans;
}


int main(){
   string a="10001";
   cout << removeKdigits(a,1);
}