#include <iostream>
#include<vector>
#include <climits>

using namespace std;

int xh,yh;

int tsp(int mask, int pos, int n, vector<pair<int,int>>&v){
    if(mask == (1<<n)-1) {
        return abs(v[pos].first-xh)+abs(v[pos].second - yh);
    }

    int ans = INT_MAX;

    for(int i=0; i<n; i++){
        if((mask & (1<<i)) == 0){
            ans = min(ans, abs(v[pos].first-v[i].first)+abs(v[pos].second - v[i].second) + tsp(mask | (1<<i), i, n, v));
        }
    }

    return ans;
}


void solve(){
    int n;
    cin>>n;

    vector<pair<int,int>>v(n+1);
    
    int xo,yo;
    cin>>xo>>yo>>xh>>yh;
    v[0] = {xo,yo};

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v[i+1] = {x,y};
    }

    cout<<tsp(1, 0, n+1, v)<<endl;
}


int main(){
    int t=10;
    for(int i=0; i<t; i++){
        cout<<"# "<<i+1<< " ";
        solve();
    }
}










// //Author: whiteblueskyss
// //Created Date:   2025-07-03 14:29:46
// //Last Modified: 2025-07-03 14:46:59

// #include <bits/stdc++.h>
// using namespace std;
// #define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define ll long long int
// #define F first
// #define S second
// #define PB push_back
// #define PPB pop_back
// #define MP make_pair
// #define endl "\n"
// const int N = 2e5+10;
// const ll MOD = 1e9+7;

// ll ans = INT_MAX;
// ll n;
// ll hx,hy,ox,oy;

// void getDis(vector<pair<ll,ll>>&w){
//     ll x=ox,y=oy;
//     ll dis = 0;
//     for(auto a: w){
//         dis += abs(x-a.first);
//         dis += abs(y-a.second);
//         x = a.first;
//         y = a.second;
//     }

//     dis += abs(x-hx);
//     dis += abs(y-hy);

//     ans = min(dis, ans);
// }

// void backtrack(vector<pair<ll,ll>>&v, vector<bool>&vis, vector<pair<ll,ll>>&w){
//     if(w.size()==n){
//         getDis(w);
//         return;
//     }


//     for(int i=0; i<n; i++){
//         if(!vis[i]){
//             vis[i] = true;
//             w.push_back(v[i]);
//             backtrack(v, vis, w);
//             vis[i] = false;
//             w.pop_back();
//         }
//     }
// }


// void solve(){
//     ans = INT_MAX;
//     cin>>n;
//     vector<pair<ll,ll>>v(n);
//     cin>>hx>>hy>>ox>>oy;
//     for(int i=0; i<n; i++){
//         ll x,y;
//         cin>>x>>y;
//         v[i] = {x,y};
//     }

//     vector<bool>vis(n, false);
//     vector<pair<ll,ll>>w;
//     backtrack(v, vis, w);   

//     cout<<ans<<endl;
    
// }

// int main(){
//     FAST
//     int t=10;
//     // cin >> t;
//     for(int i=1; i<=t; i++){
//         cout<<"# "<<i<< " ";
//         solve();
//     }
//     return 0;
// }