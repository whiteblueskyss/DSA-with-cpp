#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, sx, sy, dx, dy;
vector<vector<int>> v; 
int ans;
bool vis[100];

void calc(int x, int y, int c) {
    ans = min(ans, c + abs(x - dx) + abs(y - dy));

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = true;

            // enter at (x1,y1), exit at (x2,y2)
            int temp1 = c + abs(x - v[i][0]) + abs(y - v[i][1]) + v[i][4];
            calc(v[i][2], v[i][3], temp1);

            // enter at (x2,y2), exit at (x1,y1)
            int temp2 = c + abs(x - v[i][2]) + abs(y - v[i][3]) + v[i][4];
            calc(v[i][0], v[i][1], temp2);

            vis[i] = false;
        }
    }
}

void solve() {
    cin >> n;
    cin >> sx >> sy >> dx >> dy;

    v.assign(n, vector<int>(5));
    ans = INT_MAX;
    fill(begin(vis), end(vis), false);

    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3] >> v[i][4];
    }

    
    calc(sx, sy, 0);

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
