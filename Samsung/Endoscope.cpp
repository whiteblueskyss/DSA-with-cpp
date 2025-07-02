//Author: whiteblueskyss
//Created Date:   2025-07-02 12:52:21
//Last Modified: 2025-07-02 13:23:48

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
int r, c; 


bool right(int x){
    return x==1 || x==3 || x==4 || x==5;
}
bool left(int x){
    return x==1 || x==3 || x==6 || x==7;
}
bool up(int x){
    return x==1 || x==2 || x==4 || x==7;
}
bool down(int x){
    return x==1 || x==2 || x==5 || x==6;
}

bool valid(int i, int j){
    return i>=0 && i<r && j>=0 && j<c;
}

void solve(){
    ll x,y,l;
    cin>>r>>c>>x>>y>>l;

    int a[r+20][c+20];

    for(int i=0; i<r; i++){
        for(int j=0; j<c;j++){
            cin>>a[i][j];
        }
    }

    queue<pair<int,int>>q;

    int vis[r+20][c+20] = {false};
    int ans=0, cnt=0;
    
    vis[x][y] = true;

    if(a[x][y]){        
        q.push({x,y});
        ans++;
        cnt++;
    }

    vector<pair<int,int>>vp = {{0,1},{0,-1},{1,0},{-1,0}};

    while(!q.empty() && cnt<l){
        cnt++;
        vector<pair<int,int>>v;

        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }

        for(auto x : v){
            int i=x.first;
            int j=x.second;
            int xi,xj;

            for(int d=0; d<4; d++){
                xi = i+vp[d].F;
                xj = j+vp[d].S;

                if(valid(xi,xj) && !vis[xi][xj] && a[xi][xj]!=0){

                    if(d==0 && right(a[i][j]) && left(a[xi][xj])){
                        ans++;
                        q.push({xi, xj});
                        vis[xi][xj] = true;

                    }

                    if(d==1 && left(a[i][j]) && right(a[xi][xj])){
                        ans++;
                        q.push({xi, xj});
                        vis[xi][xj] = true;
                    }

                    if(d==2 && down(a[i][j]) && up(a[xi][xj])){
                        ans++;
                        q.push({xi, xj});
                        vis[xi][xj] = true;
                    }

                    if(d==3 && up(a[i][j]) && down(a[xi][xj])){
                        ans++;
                        q.push({xi, xj});
                        vis[xi][xj] = true;
                    }
                }

            }

        }
    }

    cout<<ans<<endl;
    
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