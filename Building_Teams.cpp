#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100005];
int n, m, a, b, color[100005];
void dfs(int x, int pre){
    for(auto  i : v[x]){
        if(i == pre) continue;
        if(!color[i]){
            color[i] = 3 - color[x];
            dfs(i, x);
        }
        else if(color[x] == color[i]){
            cout << "IMPOSSIBLE" << '\n';
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
        if(!color[i]){
            color[i] = 1;
            dfs(i, 0);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << color[i] << " ";
    }
}
