//Author: whiteblueskyss
//Created Date:   2025-06-30 14:00:41
//Last Modified: 2025-06-30 14:20:44

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

ll ans = 0;

void dfs (vector<vector<ll>>&v, int i, int j, ll coins, int safe, bool isBombed){
    ans = max(ans, coins);

    if(i<0 || j<0 || j>4){
        return;
    }

    if(v[i][j]==1){
        if(isBombed){
            if(safe==0){
                return;
            }
            safe--;
        }
        coins++;

        dfs(v, i-1, j-1, coins, safe, isBombed);
        dfs(v, i-1, j, coins, safe, isBombed);
        dfs(v, i-1, j+1, coins, safe, isBombed);
    }

    else if(v[i][j]==0){
        if(isBombed){
            if(safe==0){
                return;
            }
            safe--;
        }

        dfs(v, i-1, j-1, coins, safe, isBombed);
        dfs(v, i-1, j, coins, safe, isBombed);
        dfs(v, i-1, j+1, coins, safe, isBombed);

    }

    else if(v[i][j]==2){
        if(isBombed){
            if(safe==0){
                return;
            }
            safe--;
        }
        else{
            isBombed=true;
            safe=4;
        }

        dfs(v, i-1, j-1, coins, safe, isBombed);
        dfs(v, i-1, j, coins, safe, isBombed);
        dfs(v, i-1, j+1, coins, safe, isBombed);
    }
}


void solve(){
    ll n;
    cin>>n;
    vector<vector<ll>> v(n, vector<ll>(5,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            cin>>v[i][j];
        }
    }    

    dfs(v, n-1, 1, 0, 0, 0);
    dfs(v, n-1, 2, 0, 0, 0);
    dfs(v, n-1, 3, 0, 0, 0);

    cout<<ans<<endl;
    ans=0;
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