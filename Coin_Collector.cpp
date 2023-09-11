#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
int n, m, a, b, vis[100005], color;
ll arr[100005], val[100005], dp[100005];
vector<int> v[100005], rv[100005], nv[100005], topo;
void dfs(int x){
    vis[x] = 1;
    for(auto i : v[x]){
        if(!vis[i]) dfs(i);
    }
    topo.push_back(x);
}
void dfs2(int x){
    vis[x] = color;
    for(auto i : rv[x]){
        if(!vis[i]) dfs2(i);
    }
}
ll func(int x){
    if(dp[x]) return dp[x];
    dp[x] = val[x];
    for(int i : nv[x]){
        dp[x] = max(dp[x], val[x] + func(i));
    }
    return dp[x];
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
        rv[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }
    reverse(topo.begin(), topo.end());
    memset(vis, 0, sizeof(vis));
    for(auto i : topo){
        if(!vis[i]){
            color += 1;
            dfs2(i);
        }
    }
    for(int i = 1; i <= n; i++){
        val[vis[i]] += arr[i];
    }
    for(int i = 1; i <= n; i++){
        int tmp = 0;
        for(auto e : v[i]){
            if(vis[i] == vis[e]) continue;
            nv[vis[i]].push_back(vis[e]);
        }
    }
    ll ans = 0;
    for(int i = 1; i <= color; i++){
        ans = max(ans, func(i));
    }
    cout << ans << '\n';
}
