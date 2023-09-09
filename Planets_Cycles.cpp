#include <iostream>
#include <vector>
using namespace std;
int n, arr[20][200005], ans[200005];
void build(){
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = arr[i - 1][arr[i - 1][j]];
        }
    }
}
int find(int x){
    if(ans[x]) return ans[x];
    return ans[x] = find(arr[0][x]) + 1;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[0][i];
    }
    build();
    for(int i = 1;i <= n; i++){
        // start from tail, make sure start in cycle
        int cur = arr[19][i];
        int next = arr[0][cur];
        if(ans[cur]) continue;
        ans[cur] = 1;
        // count how many node in cycle
        while(next != cur){
            ans[cur] += 1;
            next = arr[0][next];
        }
        // update node in cycle
        next = arr[0][cur];
        while(next != cur){
            ans[next] = ans[cur];
            next = arr[0][next];
        }
    }
    for(int i = 1; i <= n; i++){
        if(!ans[i]) ans[i] = find(i);
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
}
