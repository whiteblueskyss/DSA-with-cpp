#include <bits/stdc++.h>
using namespace std;

int pre(char c){

    if(c=='^')
        return 3;

    if(c=='*' || c=='/')
        return 2;
    if(c=='+' || c=='-')
        return 1;
    return -1;
}



void solve(){
    string s;
    cin>>s;

    stack<char>st;

    for(int i=0; i<s.size(); i++){

        char ch=s[i];

        if(ch>='a' && ch<='z' || ch >= 'A' && ch<='Z'
             || ch>='0'&&ch<='9'){
            cout<<ch;
        }
       
        else if(ch=='('){
            st.push(ch);
        }
        // if(!st.empty())
        //     cout<<st.top()<<endl;

        else if(ch == ')'){
            while(st.top()!='('){
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }
       
        else{
            while(!st.empty() && pre(ch)<=pre(st.top())){
                cout<<st.top();
                st.pop();
                
            }
            
            st.push(ch);
        
        }
    }

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
}

int main(){
    int test=1;
    cin >> test;
    while(test--){
      solve();
    }
    return 0;
}
