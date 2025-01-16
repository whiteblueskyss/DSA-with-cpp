#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define F first
#define S second
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define endl "\n"
ll n;
vector<string>ans;

void genarate(string &s, int open, int close){
    if(open == n && close == n){
        ans.PB(s);
        return;
    }
    if(open<n){
        s.PB('(');
        genarate(s, open+1, close);
        s.PPB();
    }
    if(close<open){
        s.PB(')');
        genarate(s, open, close+1);
        s.PPB();

    }

}


void solve(){
    cin>>n;
    string s="";
    genarate(s, 0, 0);

    for(auto str  : ans){
        cout<<str<<endl;
    }
}

int main(){
    FAST
    int t=1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
