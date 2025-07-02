#include <bits/stdc++.h>
using namespace std;

vector<int>ans;
int s = INT_MAX;

int sum(vector<int>v){
    int x=0;
    for(auto y : v){
        x+=y;
    }

    return x;
}
void dfs(vector<int>g[], int node, vector<bool>&vis, vector<int>temp){
    vis[node] = true;
    temp.push_back(node);

    for(auto x: g[node]){
        if(!vis[x]) dfs(g, x, vis, temp);

        else{
            if(x==temp[0] && sum(temp)<s) {
                // cout<<"s"<<endl;
                s = sum(temp);
                ans = temp;
            }
        }
    }

    vis[node] = false;
    temp.pop_back();
}


int main(){
    int n,e;
    cin>>n>>e;

    vector<int>g[n+2];

    for(int i=1; i<=e; i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }

    for(int i=1; i<=n; i++){
        vector<bool>vis(n+2, 0);

        dfs(g, i,vis, {});
    }

    sort(ans.begin(), ans.end());

    for(auto x : ans){
        cout<<x<<" ";
    }cout<<endl;

    // for(int i=1; i<=n; i++){
    //     cout<<i<< " : ";
    //     for(auto x : g[i]){
    //         cout<<x<<" ";
    //     }cout<<endl;
    // }
}


// 3 4
// 1 2 2 3 1 3 3 1
// output: 1 3
// 5 5
// 2 4 2 3 4 3 1 5 5 1
// output: 1 5 