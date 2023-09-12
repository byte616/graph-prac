#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a, b, in[100005], out[100005];
vector<int> v[100005], ans;
void dfs(int x){
    while(!v[x].empty()){
        int node = v[x].back();
        v[x].pop_back();
        dfs(node);
    }
    ans.push_back(x);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        out[a] += 1, in[b] += 1;
    }
    if(out[1] - in[1] != 1 || in[n] - out[n] != 1){
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    for(int i = 2; i < n; i++){
        if(out[i] != in[i]){
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }
    dfs(1);
    if(ans.size() == m + 1){
        reverse(ans.begin(), ans.end());
        for(auto i : ans) cout << i << " ";
    }
    else cout << "IMPOSSIBLE" << '\n';
}
