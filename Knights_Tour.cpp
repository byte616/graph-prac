#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ans[10][10], n, m;
bool vis[10][10];
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
bool is_valid(int x, int y){
    return x >= 1 && x <= 8 && y >= 1 && y <= 8 && !vis[x][y];
}
int degree(int x, int y){
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(is_valid(xx, yy)) cnt += 1;
    }
    return cnt;
}
void dfs(int x, int y, int step){
    if(step == 64){
        for(int i = 1; i <= 8; i++){
            for(int j = 1; j <= 8; j++){
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
        exit(0);
    }
    vector<pair<int,pair<int,int>>> v;    
    for(int i = 0; i < 8; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(!is_valid(xx, yy)) continue;
        v.push_back({degree(xx, yy), {xx, yy}});
    }
    sort(v.begin(), v.end());
    for(auto i : v){
        int xx = i.second.first, yy = i.second.second;
        vis[xx][yy] = 1;
        ans[xx][yy] = step + 1;
        dfs(xx, yy, step + 1);
        vis[xx][yy] = 0;
        ans[xx][yy] = 0;
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;
    ans[n][m] = 1;
    vis[n][m] = 1;
    dfs(n, m, 1);
}
