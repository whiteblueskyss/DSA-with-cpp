#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>

using namespace std;

int dp[15][1<<15];
vector<pair<int,int>>v(20);
int n;

int absv(int x, int y){
    return abs(v[x].first - v[y].first) + abs(v[x].second-v[y].second);
}

int tsp(int pos, int mask){
    if(mask == (1<<n)-1){
        return absv(pos, n+1);
    }
    if(dp[pos][mask] != -1){
        return dp[pos][mask];
    }

    int ans = 1e9;

    for(int i=1; i<=n; i++){
        // if(mask & ((1<<(i-1))==0)){
        //     ans = min(ans, absv(pos, i) + tsp(i, mask | (1<<(i-1))));
        // }
        if ((mask & (1 << (i-1))) == 0) {
            ans = min(ans, absv(pos, i) + tsp(i, mask | (1 << (i-1))));
        }
    }

    return dp[pos][mask] = ans;
}

void solve(){
    cin>>n;
    cin>>v[0].first>>v[0].second;
    cin>>v[n+1].first>>v[n+1].second;

    for(int i=1; i<=n; i++){
        cin>>v[i].first>>v[i].second;
    } 

    memset(dp, -1, sizeof(dp));

    cout<<tsp(0,0)<<endl;
}

int main(){
    int t=10;

    for(int i=0; i<t; i++){
        cout<< "# " <<i+1<< " ";
        solve(); 
    }
}