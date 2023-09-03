#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
int n, m, a, b, par[100005];
bool vis[100005];
void dfs(int x, int pre){
    vis[x] = 1;
    par[x] = pre;
    for(auto i : v[x]){
        if(i == pre) continue;
        if(!vis[i]) dfs(i, x);
        else{
            vector<int> ans ={i};
            int start = x;
            while(start != *ans.begin()){
                ans.push_back(start);
                start = par[start];
            }
            ans.push_back(i);
            cout << ans.size() << '\n';
            for(auto i : ans){
                cout << i << " ";
            }
            exit(0);
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
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, 0);
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
