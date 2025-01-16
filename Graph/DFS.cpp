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

const int N = 100099;
vector<ll>g[N];
vector<bool>vis(N);
ll cnt=0;

void dfs(ll x){
    vis[x] = true;
    for(auto child : g[x]){
        if(vis[child]){
            continue;
        }
        cnt++;
        dfs(child);
        
    }
}

void solve(){
    for(int i=0; i<N; i++){
        g[i].clear();
    }
    vis.clear();
    cnt = 0;

    ll n, e;
    cin>>n;
    e = n-1;
    // cout<<"n "<<n<<"  e "<<e<<endl;
    
    for(ll i=0; i<e; i++){
        ll u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    

    for(int i=1; i<=n; i++){
        if(g[i].size()==1){
            cnt++;
        }
    }

    // cout<<cnt<<endl;

    if(cnt%2==0){
        cout<<cnt/2<<endl;
    }
    else{
        cout<<cnt/2+1<<endl;
    }
}

int main(){
    FAST
    int t=1;
    cin >> t;
    while(t--)solve();
    return 0;
}

/*
8 5
1 2
2 3
2 4
3 5
6 7
*/