#include <bits/stdc++.h>
using namespace std;

int toInt(string s){
    int n= s.size();
    int num = 0;
    for(int i=0; i<n; i++){
        num = num*10 + s[i]-'0';
    }

    return num;
}

int main(){

    int k;
    cin>>k;

    string s;
    cin>>s;
    
    int n = s.size();

    int level = -1;
    int sum = 0;

    for(int i=0; i<n; i++){
        if(s[i]=='(') level++;
        else if(s[i]==')') level--;

        else if(level==k){
            string temp = "";
            while(i<n && s[i] != '(' && s[i] != ')'){
                temp.push_back(s[i]);
                i++;
            }
            i--;
            // cout<<temp<<endl;
            int num = toInt(temp);
            sum += num;
        }
    }

    cout<<sum<<endl;
}