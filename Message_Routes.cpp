#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m, a, b, pre[100005];
bool vis[100005];
vector<int> v[100005];
int main(){
    ios::sync_with_stdio(0) ,cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto i : v[u]){
            if(!vis[i]){
                vis[i] = 1;
                q.push(i);
                pre[i] = u;
            }
        }
    }
    if(vis[n]){
        vector<int> ans = {n};
        while(n != 1){
            int x = pre[n];
            ans.push_back(x);
            n = x;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(auto i : ans){
            cout << i << " ";
        }
    }
    else cout << "IMPOSSIBLE" << '\n';
}

