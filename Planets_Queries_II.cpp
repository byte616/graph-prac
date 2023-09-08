#include <iostream>
using namespace std;
int n, m, x, y, len[200005], arr[21][200005];
bool vis[200005];
void dfs(int x){
    vis[x] = 1;
    int next = arr[0][x];
    if(!vis[next]) dfs(next);
    len[x] = len[next] + 1;
}
void build(){
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = arr[i - 1][arr[i - 1][j]];
        }
    }
}
int jump(int x, int step){
    if(step < 0) return 0;
    for(int i = 0; i <= 20; i++){
        if(step & (1 << i)){
            x = arr[i][x];
        }
    }
    return x;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[0][i];
    }
    build();
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }
    while(m--){
        cin >> x >> y;
        int st = jump(x, len[x]);
        int dis = len[x] + len[st] - len[y];
        // case 1: no cycle
        if(jump(x, len[x] - len[y]) == y){
            cout << len[x] - len[y] << '\n';
        }
        // case 2: has cycle
        else if(jump(st, len[st] - len[y]) == y){
            cout << dis << '\n';
        }
        else cout << -1 << '\n';
    }
}
