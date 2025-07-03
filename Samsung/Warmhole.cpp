//Author: whiteblueskyss
//Created Date:   2025-07-03 15:37:19
//Last Modified: 2025-07-03 16:51:12

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

ll sx,sy,ex,ey,n, ans=INT_MAX;
vector<bool>vis(15, false); 
vector<vector<ll>>v(15, vector<ll>(5));

ll dis(int sx, int sy, int ex, int ey){
    return abs(sx-ex) + abs(sy-ey);
}

void backtrack(ll sx, ll sy, ll ex, ll ey, ll val){
    
    ans = min(ans, dis(sx, sy, ex, ey)+val);

    for(int i=0; i<n; i++){
        if(!vis[i]){
            vis[i] = true;
            ll temp = dis(sx,sy,v[i][0],v[i][1]) + v[i][4] + val;
            backtrack(v[i][2], v[i][3], ex, ey, temp);

            temp = dis(sx, sy, v[i][2], v[i][3]) + v[i][4] + val;
            backtrack(v[i][0], v[i][1], ex, ey, temp);

            vis[i] = false;
        }
    }
}

void solve(){
    cin>>n;
    cin>>sx>>sy>>ex>>ey;

    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            cin>>v[i][j];
        }
    }
    
    backtrack(sx, sy, ex, ey, 0); 

    cout<<ans<<endl;
}

int main(){
    FAST
    int t=1;
    cin >> t;
    for(int i=1; i<=t; i++){
        // cout<<"Test: "<<i<<endl;
        solve();
    }
    return 0;
}