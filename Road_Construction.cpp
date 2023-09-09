#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a, b, par[100005], sz[100005];
int find(int x){
    return x == par[x] ? x : par[x] = find(par[x]);
}
bool uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return 0;
    if(sz[a] > sz[b]){
        sz[a] += sz[b];
        par[b] = a;
    }
    else{
        sz[b] += sz[a];
        par[a] = b;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int  i = 1; i <= n; i++){
        par[i] = i;
        sz[i] = 1;
    }
    int component = n, ma = 0;
    while(m--){
        cin >> a >> b;
        if(uni(a, b)){
            component -= 1;
            ma = max({ma, sz[find(a)], sz[find(b)]});
        }
        cout << component << " " << ma << '\n';
    }
}
