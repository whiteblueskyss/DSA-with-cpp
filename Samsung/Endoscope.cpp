
#include <iostream>
#include <vector>
#include <queue>
#include<tuple>

using namespace std;

#define ll long long

ll n,m;

bool left(ll x){
    return x==1 || x==3 || x==6 || x==7;
}
bool right(ll x){
    return x==1 || x==3 || x==4 || x==5;
}
bool up(ll x){
    return x==1 || x==2 || x==4 || x==7;
}
bool down(ll x){
    return x==1 || x==2 || x==5 || x==6;
}

void bfs(ll x, ll y, ll len, vector<vector<bool>>&vis, vector<vector<ll>>&v){
    
    queue<tuple<ll,ll,ll>>q;
    q.push({x,y,len});
    vis[x][y] = true;
    // ll ans = 1;

    while(!q.empty()){
        auto [x,y, len] = q.front();
        q.pop();

        if(len==1){
            continue;
        }
        if(y+1<m && !vis[x][y+1] && right(v[x][y]) && left(v[x][y+1])){
            q.push({x, y+1, len-1});
            vis[x][y+1]=true;
        }

        if(y-1>=0 && !vis[x][y-1] && left(v[x][y]) && right(v[x][y-1])){
            q.push({x, y-1, len-1});
            vis[x][y-1]=true;
        }

        if(x+1<n && !vis[x+1][y] && down(v[x][y]) && up(v[x+1][y])){
            q.push({x+1, y, len-1});
            vis[x+1][y]=true;
        }

        if(x-1>=0 && !vis[x-1][y] && up(v[x][y]) && down(v[x-1][y])){
            q.push({x-1, y, len-1});
            vis[x-1][y]=true;
        }   
    }
    
}



void solve(){
    ll x,y,len;
    cin>>n>>m>>x>>y>>len;

    vector<vector<ll>>v(n, vector<ll>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    vector<vector<bool>>vis(n, vector<bool>(m,false));

    bfs(x,y,len,vis,v);

    ll ans = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]){
                ans++;
            }
        }
    }

    cout<<ans<<endl;
}


int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}



// // whats wrong in this code ? 
// // endoscope ? 

// #include <iostream>
// #include <vector>

// using namespace std;

// #define ll long long

// ll n,m;

// bool left(ll x){
//     return x==1 || x==3 || x==6 || x==7;
// }
// bool right(ll x){
//     return x==1 || x==3 || x==4 || x==5;
// }
// bool up(ll x){
//     return x==1 || x==2 || x==4 || x==7;
// }
// bool down(ll x){
//     return x==1 || x==2 || x==5 || x==6;
// }

// void bfs(ll x, ll y, ll len, vector<vector<bool>>&vis, vector<vector<ll>>&v){
//     if(vis[x][y] || v[x][y]==0 || len==0){
//         return;
//     }

//     vis[x][y] = true;

//     cout<<x<< " "<<y<<endl;

//     if(y+1<m && right(v[x][y]) && left(v[x][y+1])) bfs(x,y+1, len-1, vis, v);
//     if(y-1>=0 && left(v[x][y]) && right(v[x][y-1])) bfs(x,y-1, len-1, vis, v);
//     if(x+1<n && up(v[x][y]) && down(v[x+1][y])) bfs(x+1,y, len-1, vis, v);
//     if(x-1>=0 && down(v[x][y]) && up(v[x-1][y])) bfs(x-1,y, len-1, vis, v);
// }



// void solve(){
//     ll x,y,len;
//     cin>>n>>m>>x>>y>>len;

//     vector<vector<ll>>v(n, vector<ll>(m));

//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cin>>v[i][j];
//         }
//     }

//     vector<vector<bool>>vis(n, vector<bool>(m,false));

//     bfs(x,y,len,vis,v);

//     ll ans = 0;

//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(vis[i][j]){
//                 ans++;
//             }
//         }
//     }

//     cout<<ans<<endl;
// }


// int main(){
//     int t;
//     cin>>t;

//     while(t--){
//         solve();
//     }
// }










// //Author: whiteblueskyss
// //Created Date:   2025-07-02 12:52:21
// //Last Modified: 2025-07-02 13:23:48

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
// int r, c; 


// bool right(int x){
//     return x==1 || x==3 || x==4 || x==5;
// }
// bool left(int x){
//     return x==1 || x==3 || x==6 || x==7;
// }
// bool up(int x){
//     return x==1 || x==2 || x==4 || x==7;
// }
// bool down(int x){
//     return x==1 || x==2 || x==5 || x==6;
// }

// bool valid(int i, int j){
//     return i>=0 && i<r && j>=0 && j<c;
// }

// void solve(){
//     ll x,y,l;
//     cin>>r>>c>>x>>y>>l;

//     int a[r+20][c+20];

//     for(int i=0; i<r; i++){
//         for(int j=0; j<c;j++){
//             cin>>a[i][j];
//         }
//     }

//     queue<pair<int,int>>q;

//     int vis[r+20][c+20] = {false};
//     int ans=0, cnt=0;
    
//     vis[x][y] = true;

//     if(a[x][y]){        
//         q.push({x,y});
//         ans++;
//         cnt++;
//     }

//     vector<pair<int,int>>vp = {{0,1},{0,-1},{1,0},{-1,0}};

//     while(!q.empty() && cnt<l){
//         cnt++;
//         vector<pair<int,int>>v;

//         while(!q.empty()){
//             v.push_back(q.front());
//             q.pop();
//         }

//         for(auto x : v){
//             int i=x.first;
//             int j=x.second;
//             int xi,xj;

//             for(int d=0; d<4; d++){
//                 xi = i+vp[d].F;
//                 xj = j+vp[d].S;

//                 if(valid(xi,xj) && !vis[xi][xj] && a[xi][xj]!=0){

//                     if(d==0 && right(a[i][j]) && left(a[xi][xj])){
//                         ans++;
//                         q.push({xi, xj});
//                         vis[xi][xj] = true;

//                     }

//                     if(d==1 && left(a[i][j]) && right(a[xi][xj])){
//                         ans++;
//                         q.push({xi, xj});
//                         vis[xi][xj] = true;
//                     }

//                     if(d==2 && down(a[i][j]) && up(a[xi][xj])){
//                         ans++;
//                         q.push({xi, xj});
//                         vis[xi][xj] = true;
//                     }

//                     if(d==3 && up(a[i][j]) && down(a[xi][xj])){
//                         ans++;
//                         q.push({xi, xj});
//                         vis[xi][xj] = true;
//                     }
//                 }

//             }

//         }
//     }

//     cout<<ans<<endl;
    
// }

// int main(){
//     FAST
//     int t=1;
//     cin >> t;
//     for(int i=1; i<=t; i++){
//         // cout<<"Test: "<<i<<endl;
//         solve();
//     }
//     return 0;
// }