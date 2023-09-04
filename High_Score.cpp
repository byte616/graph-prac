#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
vector<int> v1[2505], v2[2505];
struct dege{
    int a, b;
    ll w;
} p[5005];
int n, m;
ll dis[2505];
bool vis1[2505], vis2[2505];
void dfs(int x, vector<int> v[], bool vis[]){
    vis[x] = 1;
    for(auto i : v[x]){
        if(!vis[i]){
            dfs(i, v, vis);
        }
    }
}
ll bellman_ford(int s, int t){
    for(int i = 1; i <= n; i++){
        dis[i] = -1e18;
    }
    dis[s] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(dis[p[j].a] + p[j].w > dis[p[j].b] && vis1[p[j].a] && vis2[p[j].b]){
                if(i == n) return -1;
                dis[p[j].b] = dis[p[j].a] + p[j].w;
            }
        }
    }
    return dis[n];
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> p[i].a >> p[i].b >> p[i].w;
        v1[p[i].a].push_back(p[i].b);
        v2[p[i].b].push_back(p[i].a);
    }
    dfs(1, v1, vis1);
    dfs(n, v2, vis2);
    cout << bellman_ford(1, n) << '\n';
}
