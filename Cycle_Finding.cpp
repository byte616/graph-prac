#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct edge{
    int a, b;
    ll w;
};
int n, m, a, b, pre[2505];
ll w, dis[2505];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    vector<edge> p(m);
    for(auto &ele : p){
        cin >> ele.a >> ele.b >> ele.w;
    }
    bool flag = 0;
    int start = -1;
    for(int i = 1; i <= n; i++){
        for(auto e : p){
            if(dis[e.a] + e.w < dis[e.b]){
                dis[e.b] = dis[e.a] + e.w;
                pre[e.b] = e.a;
                if(i == n){
                    flag = 1;
                    start = e.b;
                    break;
                }
            }
        }
    }
    if(flag){
        cout << "YES" << '\n';
        set<int> s;
        vector<int> ans;
        int node = start;
        while(true){
            if(s.find(node) != s.end()){
                ans.push_back(node);
                break;
            }
            ans.push_back(node);
            s.insert(node);
            node = pre[node];
        }
        // we get ans in backstrack -> reverse ans before print
        reverse(ans.begin(), ans.end());
        for(auto i : ans){
            cout << i << " ";
        }
    }
    else cout << "NO" << '\n';
}
