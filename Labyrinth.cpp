#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
int n, m, pre[1005][1005];
string step = "RLDU";
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char maps[1005][1005];
bool vis[1005][1005];
pii st, en;
bool is_valid(int x, int y){
    return x >= 1&& x <= n && y >= 1 && y <= m && !vis[x][y] && maps[x][y] != '#';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> maps[i][j];
            if(maps[i][j] == 'A') st = {i, j};
            if(maps[i][j] == 'B') en = {i, j};
        }
    }
    queue<pii> q;
    q.push(st);
    vis[st.f][st.s] = 1;
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int xx = u.f + dx[i], yy = u.s + dy[i];
            if(is_valid(xx, yy)){
                vis[xx][yy] = 1;
                pre[xx][yy] = i;
                q.push({xx, yy});
            }
        }
    }
    if(vis[en.f][en.s]){
        cout << "YES" << '\n';
        string ans = "";
        while(en != st){
            int idx = pre[en.f][en.s];
            ans += step[idx];
            en = {en.f - dx[idx], en.s - dy[idx]};
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        cout << ans << '\n';
    }
    else cout << "NO" << '\n';
}
