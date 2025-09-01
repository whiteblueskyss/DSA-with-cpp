#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define ll long long

//replace all int by ll

int tsp(int mask, int pos, int n, vector<vector<int>>&v){

    if(mask == (1<<n)-1){
        return v[pos][0];
    }

    int ans = INT_MAX;

    for(int i=0; i<n; i++){

        if( (mask & (1<<i))== 0){
            // cout<<"okay"<<endl;
            ans = min(ans, v[pos][i]+tsp(mask | (1<<i), i, n, v));
        }
    }

    return ans;
}



void solve(){
    int n;
    cin>>n;

    vector<vector<int>>v(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>v[i][j];
        }
    }

    int ans = tsp(1,0,n,v);
    cout<<ans<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}








// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 1e9;
// int dp[12][1 << 12]; // dp[pos][mask]: min cost to complete tour starting from 'pos' with visited mask 'mask'

// int tsp(int pos, int mask, vector<vector<int>>& M, int N) {
//     if (mask == (1 << N) - 1) {
//         return M[pos][0]; // all cities visited, return to city 0
//     }
    
//     if (dp[pos][mask] != -1) return dp[pos][mask];
    
//     int ans = INF;
    
//     for (int city = 0; city < N; city++) {
//         if ((mask & (1 << city)) == 0) { // if city not visited
//             int newAns = M[pos][city] + tsp(city, mask | (1 << city), M, N);
//             ans = min(ans, newAns);
//         }
//     }
    
//     return dp[pos][mask] = ans;
// }

// int main() {
//     int T;
//     cin >> T;
    
//     while (T--) {
//         int N;
//         cin >> N;
        
//         vector<vector<int>> M(N, vector<int>(N));
        
//         for (int i = 0; i < N; i++) 
//             for (int j = 0; j < N; j++) 
//                 cin >> M[i][j];
        
//         memset(dp, -1, sizeof(dp));
        
//         int minCost = tsp(0, 1, M, N); // Start at city 0, only city 0 visited
        
//         cout << minCost << endl;
//     }
    
//     return 0;
// }
