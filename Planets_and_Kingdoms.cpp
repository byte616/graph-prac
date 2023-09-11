#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, m, a, b, color, vis[100005];
vector<int> v[100005], rv[100005], topo;
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
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
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
    cout << color << '\n';
    for(int i = 1; i <= n; i++){
        cout << vis[i] << " ";
    }
}
