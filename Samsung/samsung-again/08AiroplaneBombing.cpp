//Author: whiteblueskyss
//Created Date:   2025-05-21 13:07:48
//Last Modified: 2025-05-21 14:29:53

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
int ans = 0;


void dfs (vector<vector<int>> v, int i, int j, int isSafe, int coins, bool isBombUsed){
    // cout<<coins<<" "<<i <<" "<<j<< endl;
    ans = max(ans, coins);
    if(i<0 || j>4 || j<0){
        return;
    }

    if(v[i][j]==1 || v[i][j]==0){
        if(v[i][j]==1)
            coins++;
        isSafe--;
        dfs(v, i-1, j-1, isSafe, coins, isBombUsed);
        dfs(v, i-1, j, isSafe, coins, isBombUsed);
        dfs(v, i-1, j+1, isSafe, coins, isBombUsed);
    }
    else{
        if(isBombUsed==false){
            isBombUsed = true;
            isSafe = 5;
        }
        if(isSafe>0){
            isSafe--;
            dfs(v, i-1, j-1, isSafe, coins, isBombUsed);
            dfs(v, i-1, j, isSafe, coins, isBombUsed);
            dfs(v, i-1, j+1, isSafe, coins, isBombUsed);
        }
    }


}


void solve(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(5, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            cin>>v[i][j];
        }
    }

    dfs(v, n-1, 1, 0, 0, 0);
    dfs(v, n-1, 2, 0, 0, 0);
    dfs(v, n-1, 3, 0, 0, 0);

    cout<<ans<<endl;
}

int main(){
    FAST
    int t=1;
    cin >> t;
    for(int i=1; i<=t; i++){
        cout<<"#"<<i <<" ";
        ans = 0;
        solve();
    }
    return 0;
}