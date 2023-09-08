#include<iostream>
using namespace std;
int n, m, x, k, arr[30][1000005];
void build(){
    for(int i = 1; i <= 29; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = arr[i - 1][arr[i - 1][j]];
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[0][i];
    }
    build();
    while(m--){
        cin >> x >> k;
        for(int i = 0; i <= 29; i++){
            if(k & (1 << i)){
                x = arr[i][x];
            }
        }
        cout << x << '\n';
    }
}
