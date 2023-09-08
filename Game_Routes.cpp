#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a, b, dp[100005];
bool vis[100005];
vector<int> v[100005], topo;
const int p = 1e9 + 7;
void dfs(int x){
    vis[x] = 1;
    for(auto i : v[x]){
        if(!vis[i]){
            dfs(i);
        }
    }
    topo.push_back(x);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
    }
    dfs(1);
    reverse(topo.begin(), topo.end());
    dp[1] = 1;
    for(auto i : topo){
        for(auto j : v[i]){
            dp[j] += dp[i];
            dp[j] %= p;
        }
    }
    cout << dp[n] << '\n';
}
