#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n, m, k, a, b, match[505];
bool vis[505];
vector<int> v[505];
bool dfs(int x){
    for(auto i : v[x]){
        if(vis[i]) continue;
        vis[i] = 1;
        if(match[i] == 0 || dfs(match[i])){
            match[i] = x;
            return 1;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    while(k--){
        cin >> a >> b;
        v[a].push_back(b);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) ans += 1;
    }
    cout << ans << '\n';
    for(int i = 1;i <= n; i++){
        if(match[i]) cout << match[i] << " " << i << '\n';
    }
}
