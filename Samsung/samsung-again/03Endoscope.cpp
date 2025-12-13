#include <iostream>
#include<vector>
#include <cstring>
#include <queue>
using namespace std;

bool vis[60][60];
int n,m,l;


bool left(int x){
    return x==1 || x==3 || x==6 || x==7;
}
bool right(int x){
    return x==1 || x==3 || x==4 || x==5;
}
bool up(int x){
    return x==1 || x==2 || x==4 || x==7;
}
bool down(int x){
    return x==1 || x==2 || x==5 || x==6;
}


void bfs(int x,int y, int l, vector<vector<int>>&v){
    vis[x][y] = true;
    queue<vector<int>>q;
    q.push({x,y,l});

    while(!q.empty()){
        // cout<<"IN"<<endl;
        vector<int>temp = q.front();
        q.pop();
        x = temp[0];
        y = temp[1];
        l = temp[2];
        
        // cout<<x<<y<<l<<endl;

        if(l==1){
            continue;
        }

        if(x+1<n && !vis[x+1][y] && down(v[x][y]) && up(v[x+1][y])){
            q.push({x+1, y, l-1});
            vis[x+1][y] = true;
        }
        if(x-1>=0 && !vis[x-1][y] && up(v[x][y]) && down(v[x-1][y])){
            q.push({x-1, y, l-1});
            vis[x-1][y] = true;
        }
        if(y+1<m && !vis[x][y+1] && right(v[x][y]) && left(v[x][y+1])){
            q.push({x, y+1, l-1});
            vis[x][y+1] = true;
        }
        if(y-1>=0 && !vis[x][y-1] && left(v[x][y]) && right(v[x][y-1])){
            q.push({x, y-1, l-1});
            vis[x][y-1] = true;
        }
    }

}

int main(){
    int t;
    cin>>t;

    while(t--){

        int x,y;

        cin>>n>>m>>x>>y>>l;
        // cout<<n<<m<<x<<y<<l;
        
        vector<vector<int>>v(n, vector<int>(m));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>v[i][j];
            }
        }

        memset(vis, 0, sizeof(vis));
        
        bfs(x,y,l,v);

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]){
                    ans++;
                }
            }
        }

        cout<<ans<<endl;
    }
}

