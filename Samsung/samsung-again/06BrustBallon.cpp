#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;

int get(int i, int j, vector<vector<int>>&dp, vector<int>&v){
    if(i>j){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = INT_MIN;

    for(int idx=i; idx<=j; idx++){
        int score = v[i-1]*v[j+1];
        if(i==1 && j==n){
            score = v[idx];
        }

        score += get(i, idx-1, dp, v) + get(idx+1, j, dp, v);

        ans = max(ans, score);
    }

    return dp[i][j] = ans;
}


int main(){

    cin>>n;

    vector<int>v(n+2);
    v[0] = 1;
    v[n+1] = 1;

    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    vector<vector<int>>dp(n+2, vector<int>(n+2, -1));

    cout<<get(1, n, dp, v)<<endl;

    return 0;

}