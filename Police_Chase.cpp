#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
struct edge{
    int to, rev;
    ll cap;
    bool flag;
    edge(){}
    edge(int a, ll b, int c, bool d): to(a), cap(b), rev(c), flag(d){}
};
vector<edge> v[100005];
vector<pair<int,int>> u;
int n, m, a, b, s, t, level[100005], iter[100005];
ll c;
void add_edge(int a, int b, ll c){
    v[a].push_back(edge(b, c, v[b].size(), 1));
    v[b].push_back(edge(a, 0, v[a].size() - 1, 0));
}
void BFS(){
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto e : v[cur]){
            if(e.cap > 0 && level[e.to] == -1){
                level[e.to] = level[cur] + 1;
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
        ll tmp = 0;
        while((tmp = dfs(s, INF)) > 0) ret += tmp;
    }
    return ret;
}
int main(){
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        add_edge(a, b, 1);
        add_edge(b, a, 1);
        u.push_back({a, b});
    }
    s = 1, t = n;
    cout << max_flow() << '\n';
    for(auto i : u){
        if(level[i.first] != -1 && level[i.second] == -1){
            cout << i.first << " " << i.second << '\n';
        }
    }
}
