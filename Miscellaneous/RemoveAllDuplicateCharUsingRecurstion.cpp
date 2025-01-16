#include <bits/stdc++.h>
using namespace std;

string rev(string s){
  if(s.size()==0){
    return "";
  }
  
  char ch = s[0];
  string ans = rev(s.substr(1));
  if(s[0]==ans[0]){
    return ans;
  }
  return(ch+ans);
}

int main(){
  string s;
  cin>>s;
  string ss = rev(s);
  cout<<ss<<endl;
}