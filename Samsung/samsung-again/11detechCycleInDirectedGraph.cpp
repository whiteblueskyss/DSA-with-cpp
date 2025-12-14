#include<iostream>
#include<algorithm>
#include<vector>
// #include<utility>
// #include<cstring>
// #include<cmath>
#include<numeric>
#include<climits>
// #include<bits/stdc++.h>

using namespace std;

vector<vector<int>>g;
vector<bool>vis;
vector<int>path, best;

int mn = INT_MAX;

void dfs(int u){
    vis[u] = true;
    path.push_back(u);
    for(auto x: g[u]){
        if(!vis[x]){
            dfs(x);
        }
        else{
            auto it = find(path.begin(), path.end(), x);
            if(it != path.end()){
                vector<int>cycle(it, path.end());

                // int temp = accumulate(cycle.begin(), cycle.end(), 0);
                int temp = accumulate(cycle.begin(), cycle.end(), 0);
                if(temp<mn){
                    mn = temp;
                    best = cycle;
                }
            }
            
        }
    }
    vis[u] = false;
    path.pop_back();
}

int main(){
    int n,m;
    cin>>n>>m;

    mn = INT_MAX;
    g.assign(n+1, {});
    vis.assign(n+1,0);

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }


    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    sort(best.begin(), best.end());

    for(auto x: best){
        cout<<x<< " ";
    }cout<<endl;


}