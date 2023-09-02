#include <iostream>
using namespace std;
int n, m, cnt;
char maps[1005][1005];
bool vis[1005][1005];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool is_valid(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y] && maps[x][y] != '#';
}
void dfs(int x, int y){
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(is_valid(xx, yy)){
            dfs(xx, yy);
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> maps[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vis[i][j] && maps[i][j] == '.'){
                cnt += 1;
                dfs(i, j);
            }
        }
    }
    cout << cnt << '\n';
}
