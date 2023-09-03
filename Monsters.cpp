#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
int n, m, dis[1005][1005], pre[1005][1005];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char maps[1005][1005];
vector<pii> monster;
queue<pii> q;
pii st;
bool is_valid(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m && maps[x][y] != '#';
}
bool is_border(int x, int y){
    return x == 1 || x == n || y == 1 || y == m;
}
void bfs(int mode){
    // 0 -> monster ; 1 -> people
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        if(mode == 1 && is_border(u.f, u.s)){
            cout << "YES" << '\n';
            string step = "RLDU", ans = "";
            pii start = u;
            while(start != st){
                int idx = pre[start.f][start.s];
                ans += step[idx];
                start = {start.f - dx[idx], start.s - dy[idx]};
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            cout << ans << '\n';
            exit(0);
        }
        for(int i = 0; i < 4; i++){
            int xx = u.f + dx[i], yy = u.s + dy[i];
            if(is_valid(xx, yy) && dis[xx][yy] > dis[u.f][u.s] + 1){
                dis[xx][yy] = dis[u.f][u.s] + 1;
                q.push({xx, yy});
                pre[xx][yy] = i;
            }
        }
    }
}
void init(){
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    for(auto i : monster){
        q.push(i);
        dis[i.f][i.s] = 0;
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> maps[i][j];
            if(maps[i][j] == 'A') st = {i, j};
            if(maps[i][j] == 'M') monster.push_back({i, j});
        }
    }
    init();
    bfs(0);
    q.push(st);
    dis[st.f][st.s] = 0;
    bfs(1);
    cout << "NO" << '\n';
}
