#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>
#define f first
#define s second
ll n, m, a, b, c, dis[100005];
vector<pii> v[100005];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[1] = 0;
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
    for(int i = 1; i <= n; i++){
        cout << dis[i] << " ";
    }
}
