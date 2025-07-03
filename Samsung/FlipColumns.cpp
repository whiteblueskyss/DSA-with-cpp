//Author: whiteblueskyss
//Created Date:   2025-07-03 09:31:35
//Last Modified: 2025-07-03 09:34:33

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
const int N = 2e5+10;
const ll MOD = 1e9+7;

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;

    unordered_map<string,int>mp;

    for(int i=0; i<n; i++){
        ll zero = 0;
        string s = "";
        for(int j=0; j<m; j++){
            ll x; cin>>x;
            if(x==0) zero++;
            s += '0' + x;
        }

        if(zero<=k && (k-zero)%2==0){
            mp[s]++;
        }
    }
    ll ans = 0;
    for(auto x : mp){
        if(ans<x.second) ans = x.second;
    }

    cout<<ans<<endl;
    
}

int main(){
    FAST
    int t=1;
    // cin >> t;
    for(int i=1; i<=t; i++){
        // cout<<"Test: "<<i<<endl;
        solve();
    }
    return 0;
}

/*
3 3 2
1 0 0
1 0 1
1 0 0
*/