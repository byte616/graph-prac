#include <iostream>
#include <vector>
using namespace std;
int n, m, a, b;
bool vis1[100005], vis2[100005];
vector<int> v[100005], u[100005];
void dfs(int x, bool vis[], vector<int> v[]){
    vis[x] = 1;
    for(auto i : v[x]){
        if(!vis[i]){
            dfs(i, vis, v);
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
        u[b].push_back(a);
    }
    dfs(1, vis1, v);
    dfs(1, vis2, u);
    for(int i = 2; i <= n; i++){
        if(!vis1[i]){
            cout << "NO" << '\n';
            cout << 1 << " " << i << '\n';
            return 0;
        }
        if(!vis2[i]){
            cout << "NO" << '\n';
            cout << i << " " << 1 << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
}
// check 1 can reach every node and every node can reach 1
// if yes, u to v can derive into u -> 1 -> v

