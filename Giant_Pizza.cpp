#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a, b, vis[200005], color;
char c1, c2;
vector<int> v[200005], rv[200005], topo;
int rev(int x){
    if(x > m){
        return x - m;
    }
    return x + m;
}
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
    while(n--){
        cin >> c1 >> a >> c2 >> b;
        if(c1 == '-') a = m + a;
        if(c2 == '-') b = m + b;
        v[a].push_back(rev(b));
        v[b].push_back(rev(a));
        rv[rev(a)].push_back(b);
        rv[rev(b)].push_back(a);
    }
    for(int i = 1; i <= 2 * m; i++){
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
    vector<string> ans;
    for(int i = 1; i <= m; i++){
        int pos = i, neg = m + i;
        if(vis[pos] == vis[neg]){
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
        if(vis[pos] > vis[neg]){
            ans.push_back("-");
        }
        else{
            ans.push_back("+");
        }
    }
    for(auto i : ans) cout << i << " ";
}
