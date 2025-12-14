#include <iostream>
#include <cstring>

using namespace std;

int n,m;
int grid[50][50];
bool vis[50][50];

bool is_possible;


void dfs(int x, int y, int l){
   if(x>=n || x<0 || y>=m || y<0 || vis[x][y]){
      return;
   }
   
   vis[x][y] = true;

   if(grid[x][y]==3){
      is_possible = true;
      return;
   }

   if(y+1<m && grid[x][y+1] && vis[x][y+1]==false){
      dfs(x, y+1, l);
   }

   if(y-1>=0 && grid[x][y-1] && vis[x][y-1]==false){
      dfs(x,y-1, l);
   }

   for(int i=1; i<=l; i++){
      if(x+i<n && grid[x+i][y] && vis[x+i][y]==false){
         dfs(x+i, y, l);
      }
      if(x-i>=0 && grid[x-i][y] && vis[x-i][y]==false){
         dfs(x-i, y, l);
      }
   }
}

int main(){

   cin>>n>>m;

   for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
         cin>>grid[i][j];
      }
   }

   for(int i=0; i<=n; i++){
      is_possible = false;
      memset(vis, 0, sizeof(vis));
      dfs(n-1, 0, i);

      if(is_possible){
         cout<<i<<endl;
         break;
      }
   }

   return 0;
}