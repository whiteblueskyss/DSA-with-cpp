#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 1e9;

int dp[12][1<<12];
int n;

int tsp(int pos, int mask, vector<vector<int>>& v) {
    if(mask == (1 << n) - 1)
        return v[pos][0];

    if(dp[pos][mask] != -1)
        return dp[pos][mask];

    int ans = INF;

    for(int i=0; i<n; i++){
        if((mask & (1 << i)) == 0) {
            int newAns = v[pos][i] + tsp(i, mask | (1 << i), v);
            ans = min(ans, newAns);
        }
    }

    return dp[pos][mask] = ans;
}


void solve(){

    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> v[i][j];

    memset(dp, -1, sizeof(dp)); 

    cout << tsp(0, 1, v) << endl;
}


int main() {
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
