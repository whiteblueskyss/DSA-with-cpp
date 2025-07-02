//Author: whiteblueskyss
//Created Date:   2025-07-02 23:01:21
//Last Modified: 2025-07-02 23:16:00

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

void solve(){

    ll n;
    cin>>n;
    ll gate[5], man[5];
    for(int i=0; i<3; i++)cin>>gate[i];
    for(int i=0; i<3; i++) cin>>man[i];

    ll ans = INT_MAX;

    for(int i=1; i<=n-(man[0]+man[1]+man[2])+1; i++){
        for(int j=i+man[0]; j<=n-(man[1]+man[2])+1; j++){
            for(int k=j+man[1]; k<=n-man[2]+1; k++){
                ll temp = 0;

                for(int p = i; p<i+man[0]; p++){
                    temp += abs(gate[0]-p)+1;
                }
                for(int p = j; p<j+man[1]; p++){
                    temp += abs(gate[1]-p)+1;
                }
                for(int p=k; p<k+man[2]; p++){
                    temp += abs(gate[2]-p)+1;
                }
                // cout<<"temp "<<temp<<endl;
                ans = min(ans, temp);
            }
        }
    }

    cout<<ans<<endl;
    
}

int main(){
    FAST
    int t=1;
    // cin >> t;
    for(int i=1; i<=t; i++){
        // cout<<"Test: "<<i<<endl;
        solve();
    }
    return 0;
}