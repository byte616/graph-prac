#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>
#define f first
#define s second
vector<pii>  v1[100005], v2[100005];
vector<pair<ll,pii>> path;
ll n, m, a, b, c;
vector<ll> dijkstra(int st, vector<pii> *v){
    vector<ll> dis(100005, 1e18);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});
    dis[st] = 0;
    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();
        if(dis[u.s] < u.f) continue;
        for(auto i : v[u.s]){
            if(dis[i.f] > dis[u.s] + i.s){
                dis[i.f] = dis[u.s] + i.s;
                pq.push({dis[i.f], i.f});
            }
        }
    }
    return dis;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> c;
        v1[a].push_back({b, c});
        v2[b].push_back({a, c});
        path.push_back({c, {a, b}});
    }
    vector<ll> dis1 = dijkstra(1, v1);
    vector<ll> dis2 = dijkstra(n, v2);
    ll ans = 1e18;
    for(auto i : path){
        ans = min(ans, dis1[i.s.f] + dis2[i.s.s] + (i.f / 2));
    }
    cout << ans << '\n';
}
