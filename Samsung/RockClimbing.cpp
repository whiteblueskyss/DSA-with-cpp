#include<bits/stdc++.h>
using namespace std; 
int row, col;
int grid[100][100];
int sol[100][100];
int vis[100][100];


int find(int x, int y){
    vis[x][y] = 1;

    int dificulty = 9999;
    int i,j,flag=0, temp;

    if(y-1>=0 && grid[x][y-1]){
        if(sol[x][y-1] != 9999){
            dificulty = sol[x][y-1];
        }
        else if(vis[x][y-1]==0){
            dificulty = find(x, y-1);
        }
    }

    if(dificulty<sol[x][y]){
        sol[x][y] = dificulty;
    }

    if(y+1<col && grid[x][y+1]){
        if(sol[x][y+1] != 9999){
            dificulty = sol[x][y+1];
        }
        else if(vis[x][y+1]==0){
            dificulty = find(x,y+1);
        }
    }

    if(dificulty<sol[x][y]){
        sol[x][y] = dificulty;
    }



    for(i=x-1; i>=0; i--){
        if(grid[i][y] != 0){
            flag = 1;
            break;
        }
    }

    if(flag){
        temp = x-i;
        if(sol[i][y]!=9999){
            dificulty = sol[i][y];
        } 

        else if(vis[i][y]==0){
            dificulty = find(i,y);
        }

        dificulty = max(temp, dificulty);

        if(dificulty<sol[x][y]){
            sol[x][y] = dificulty;
        }
    }

    flag = 0;

    for(i = x+1; i<row; i++){
        if(grid[i][y]){
            flag = 1;
            break;
        }
    }

    if(flag){
        temp = i-x;

        if(sol[i][y] != 9999){
            dificulty = sol[i][y];
        }
        else if(vis[i][y]){
            dificulty = find(i,y);
        }

        dificulty = max(temp, dificulty);

        if(sol[x][y]>dificulty){
            sol[x][y] = dificulty;
        }
    }

    return sol[x][y];

}

int main(){
    cin>>row>>col;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>grid[i][j];
            vis[i][j] = 0;
            sol[i][j] = 9999;
            
            if(grid[i][j]==3){
                sol[i][j] = 0;
            }
        }
    }

    int ans = find(row-1, 0);

    cout<<ans<<endl;

    return 0;
}