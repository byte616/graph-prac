#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[100005], ans;
int n, m, a, b, deg[100005];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        deg[b] += 1;
        v[a].push_back(b);
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!deg[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        ans.push_back(u);
        q.pop();
        for(auto i : v[u]){
            deg[i] -= 1;
            if(!deg[i]) q.push(i);
        }
    }
    if(ans.size() == n){
        for(auto i : ans) cout << i << " ";
    }
    else cout << "IMPOSSIBLE" << '\n';
}
