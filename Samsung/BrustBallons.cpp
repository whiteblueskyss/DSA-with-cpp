#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int f (vector<ll>&v, int i, int j, vector<vector<ll>>&dp){
    if(i>j) return 0;
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    ll mx = INT_MIN;

    for(ll idx = i; idx<=j; idx++){
        ll temp = v[i-1]*v[j+1];
        ll n = v.size()-2;
        if(i==1 && j==n){
            temp = v[idx];
        }

        ll score = temp + f(v, i, idx-1, dp) + f(v, idx+1, j, dp);

        mx = max(score, mx);
        // cout<<i<< " "<<j << " "<<mx<<score<<endl; 
    }

    return dp[i][j] = mx;
}


int main(){
    ll n;
    cin>>n;

    vector<ll>v(n); 

    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    v.push_back(1);
    v.insert(v.begin(), 1);

    vector<vector<ll>>dp (n+2, vector<ll>(n+2, -1));

    cout<<f(v,1,n, dp)<<endl;


}