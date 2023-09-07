#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a, b, pre[100005], vis[100005];
vector<int> v[100005];
void dfs(int x){
    vis[x] = 1;
    for(auto i : v[x]){
        if(!vis[i]){
            pre[i] = x;
            dfs(i);
        }
        else if(vis[i] == 1){
            vector<int> ans = {i};
            while(x != i){
                ans.push_back(x);
                x = pre[x];
            }
            ans.push_back(i);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            for(auto i : ans){
                cout << i << " ";
            }
            exit(0);
        }
    }
    vis[x] = 2;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
