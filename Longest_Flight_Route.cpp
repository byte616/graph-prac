#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
int n, m, a, b, dis[100005], pre[100005];
vector<int> v[100005];
priority_queue<pii,vector<pii>,greater<pii>> pq;
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
    }
    pq.push({0, 1});
    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();
        if(dis[u.s] > u.f) continue;
        for(auto i : v[u.s]){
            if(dis[i] < dis[u.s] + 1){
                dis[i] = dis[u.s] + 1;
                pre[i] = u.s;
                pq.push({dis[i], i});
            }
        }
    }
    if(dis[n]){
        cout << dis[n] + 1 << '\n';
        vector<int> ans = {n};
        while(n != 1){
            n = pre[n];
            ans.push_back(n);
        }
        reverse(ans.begin(), ans.end());
        for(auto i : ans){
            cout << i << " ";
        }
    }
    else cout << "IMPOSSIBLE" << '\n';
}
