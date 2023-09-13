#include <iostream>
#include <vector>
using namespace std;
const int  p = 1e9 + 7;
int n, m, a, b, dp[(1 << 21)][21];
vector<int> v[100005];
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
    }
    dp[1][0] = 1; // visit set (2 ^ 0): cur_node (0)
    for(int i = 1; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(!dp[i][j]) continue;
            for(auto k : v[j]){
                if((1 << k) & i) continue; // already in set
                dp[i | (1 << k)][k] += dp[i][j];
                dp[i | (1 << k)][k] %= p;
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << '\n';
}

