#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
vector<pii> v[100005];
vector<int> order;
int n, m, a, b, c, dis[100005];
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
    dis[0] = 0;
    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();
        if(dis[u.s] < u.f) continue;
        order.push_back(u.s);
        for(auto i : v[x]){
            if(dis[i.f] > dis[u.s] + i.s){
                dis[i.f] = dis[u.s] + i.s;
                pq.push({dis[i.f], i.f});
            }
        }
    }

    cout << dis[n] << " ";
}
