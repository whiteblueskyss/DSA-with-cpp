
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