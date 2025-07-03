//Author: whiteblueskyss
//Created Date:   2025-07-03 14:29:46
//Last Modified: 2025-07-03 14:46:59

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

ll ans = INT_MAX;
ll n;
ll hx,hy,ox,oy;

void getDis(vector<pair<ll,ll>>&w){
    ll x=ox,y=oy;
    ll dis = 0;
    for(auto a: w){
        dis += abs(x-a.first);
        dis += abs(y-a.second);
        x = a.first;
        y = a.second;
    }

    dis += abs(x-hx);
    dis += abs(y-hy);

    ans = min(dis, ans);
}

void backtrack(vector<pair<ll,ll>>&v, vector<bool>&vis, vector<pair<ll,ll>>&w){
    if(w.size()==n){
        getDis(w);
        return;
    }


    for(int i=0; i<n; i++){
        if(!vis[i]){
            vis[i] = true;
            w.push_back(v[i]);
            backtrack(v, vis, w);
            vis[i] = false;
            w.pop_back();
        }
    }
}


void solve(){
    ans = INT_MAX;
    cin>>n;
    vector<pair<ll,ll>>v(n);
    cin>>hx>>hy>>ox>>oy;
    for(int i=0; i<n; i++){
        ll x,y;
        cin>>x>>y;
        v[i] = {x,y};
    }

    vector<bool>vis(n, false);
    vector<pair<ll,ll>>w;
    backtrack(v, vis, w);   

    cout<<ans<<endl;
    
}

int main(){
    FAST
    int t=10;
    // cin >> t;
    for(int i=1; i<=t; i++){
        cout<<"# "<<i<< " ";
        solve();
    }
    return 0;
}