#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>
#define f first
#define s second
const ll p = 1e9 + 7;
vector<pii> v[100005];
vector<int> order;
int n, m, a, b, mi[100005], ma[100005];
ll c, dis[100005], dp[100005];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dis[1] = 0;
    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();
        if(dis[u.s] < u.f) continue;
        order.push_back(u.s);
        for(auto i : v[u.s]){
            if(dis[i.f] > dis[u.s] + i.s){
                dis[i.f] = dis[u.s] + i.s;
                pq.push({dis[i.f], i.f});
            }
        }
    }
    memset(mi, 0x3f3f3f3f, sizeof(mi));
    dp[1] = 1;
    mi[1] = 0;
    for(auto i : order){
        for(auto j : v[i]){
            if(dis[j.f] == dis[i] + j.s){
                dp[j.f] += dp[i];
                dp[j.f] %= p;
                mi[j.f] = min(mi[j.f], mi[i] + 1);
                ma[j.f] = max(ma[j.f], ma[i] + 1);
            }
        }
    }
    cout << dis[n] << " " << dp[n] << " " << mi[n] << " " << ma[n] << '\n';
}
