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
const int N = 1e5;

vector<int>g[N];
bool vis[N];

int level[N];

void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source] = true;

    while(!q.empty()){
        int curv = q.front();
        q.pop();
        cout<<curv<<" ";
        for(int child : g[curv] ){
            if(vis[child]){
                continue;
            }
            q.push(child);
            vis[child] = true;
            level[child] = level[curv]+1;
        }
    }
}

void solve(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;

        g[x].PB(y);
        g[y].PB(x);

    }

    bfs(1);
    cout<<endl;
    for(int i=1; i<=n; i++){
        cout<<i<< " : "<<level[i]<<endl;
    }
}

int main(){
    FAST
    int t=1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
