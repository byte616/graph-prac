#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
struct edge{
    int to, rev;
    ll cap;
    bool flag;
    edge(){}
    edge(int t, ll c, int r, bool f): to(t), cap(c), rev(r), flag(f){}
};
const ll INF = 1e18;
vector<edge> v[100005]; 
vector<vector<int>> ans;
int n, m, a, b, level[100005], iter[100005], s, t;
ll c;
void add_edge(int a, int b, ll c){
    v[a].push_back(edge(b, c, v[b].size(), 1));
    v[b].push_back(edge(a, 0, v[a].size() - 1, 0));
}
void BFS(){
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto e : v[u]){
            if(e.cap > 0 && level[e.to] == -1){
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
}
ll dfs(int now, ll flow){
    if(now == t) return flow;
    for(int &i = iter[now]; i < v[now].size(); i++){
        edge &e = v[now][i];
        if(e.cap > 0 && level[e.to] == level[now] + 1){
            ll ret = dfs(e.to, min(flow, e.cap));
            if(ret > 0){
                e.cap -= ret;
                v[e.to][e.rev].cap += ret;
                return ret;
            }
        }
    }
    return 0;
}
ll max_flow(){
    ll ret = 0;
    while(1){
        BFS();
        if(level[t] == -1) break;
        memset(iter, 0, sizeof(iter));
        ll tmp;
        while((tmp = dfs(s, INF)) > 0) ret += tmp; 
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        add_edge(a, b, 1);
    }
    s = 1, t = n;
    cout << max_flow() << '\n';
    for(auto &e : v[t]){
        vector<int> tmp = {t};
        if(e.flag == 0 && e.cap == 1){
            e.cap = 0;
            int st = e.to;
            tmp.push_back(st);
            while(st != 1){
                for(auto &ee : v[st]){
                    if(ee.cap == 1 && ee.flag == 0){
                        st = ee.to;
                        ee.cap = 0;
                        break;
                    }
                }
                tmp.push_back(st);
            }
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
        }
    }
    for(auto i : ans){
        cout << i.size() << '\n';
        for(auto j : i) cout << j << ' ' ;
        cout << '\n';
    }
}

