#include <iostream>
#include <vector>
using namespace std;
int n, m, a, b;
bool vis[100005];
vector<int> v[100005], ans;
void dfs(int x){
    vis[x] = 1;
    for(auto i : v[x]){
        if(!vis[i]){
            dfs(i);
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    for(int i = 2; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for(auto i : ans){
        cout << 1 << " " << i << '\n';
    }
}
