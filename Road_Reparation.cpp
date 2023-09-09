#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
struct edge{
    int a, b;
    ll w;
    edge(){};
    edge(int _a, int _b, ll _w): a(_a), b (_b), w(_w){}
} p[200005];
bool cmp(edge a, edge b){
    return a.w < b.w;
}
int n, m, a, b, par[200005];
ll w;
int find(int x){
    return par[x] == x ? x : par[x] = find(par[x]);
}
bool uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return 0;
    par[a] = b;
    return 1;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        p[i] = edge(a, b, w);
    }
    sort(p, p + m, cmp);
    for(int i = 1; i <= n; i++){
        par[i] = i;
    }
    ll ans = 0, cnt = 0;
    for(int i = 0; i < m; i++){
        if(uni(p[i].a, p[i].b)){
            ans += p[i].w;
            cnt += 1;
        }
    }
    if(cnt == n - 1) cout << ans << '\n';
    else cout << "IMPOSSIBLE" << '\n';
}

