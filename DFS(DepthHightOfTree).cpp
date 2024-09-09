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

vector<int>g[50];

int depth[50],hight[50];

void dfs(int vertex, int par){
    //take action on vertex after entering the vertex.
    for(auto x : g[vertex]){
        // take action on child before entering the child node.
        // cout<<x<<endl;
        if(x==par){
            continue;
        }
        // cout<<"OKay"<<endl;
        depth[x] = depth[vertex]+1;
        dfs(x,vertex);
        hight[vertex]=max(hight[vertex], hight[x]+1);
        // take action on vertex before exiting the vertex.
    }
    // take action vertex before exiting the vertex.
}

int main(){
    int n;
    cin>>n;
    int x,y;

    for(int i=0; i<n; i++){
        cin>>x>>y;

        g[x].PB(y);
        g[y].PB(x);
    }

    dfs(1,0);

    // for(auto x : g){
    //     for(auto y : x){
    //         cout<<y<<" ";
    //     }cout<<endl;
    // }

    for(int i=1; i<=n; i++){
        cout<<i<<" dept "<<depth[i]<< " hight "<<hight[i]<<endl;
    }

    return 0;
}