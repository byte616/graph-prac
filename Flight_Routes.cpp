#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>
#define f first
#define s second
vector<pii> v[100005];
vector<ll> dis[100005];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int n, m, k, a, b;
ll c;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    while(m--){
        cin >> a >> b >> c;  
        v[a].push_back({b, c});
    }
    pq.push({0, 1});
    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();
        if(dis[u.s].size() >= k) continue;
        dis[u.s].push_back(u.f);
        for(auto i : v[u.s]){
            pq.push({u.f + i.s, i.f});
        }
    }
    for(auto i : dis[n]) cout << i << " ";
}

