#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int n, m, q, a, b;
ll c, dis[1005][1005];
void init(){
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= n; j++){
            dis[i][j] = 1e18;
        }
        dis[i][i] = 0;
    }
}
int main(){
    ios::sync_with_stdio(0) ,cin.tie(0);
    cin >> n >> m >> q;
    init();
    while(m--){
        cin >> a >> b >> c;
        dis[a][b] = min(c, dis[a][b]);
        dis[b][a] = dis[a][b];
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            if(i == k) continue;
            for(int j = 1; j <= n; j++){
                if(j == k) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--){
        cin >> a >> b;
        if(dis[a][b] == 1e18){
            cout << -1 << '\n';
        }
        else cout << dis[a][b] << '\n';
    }
}
