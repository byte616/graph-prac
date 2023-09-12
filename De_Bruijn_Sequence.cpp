#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n;
vector<string> ans;
map<string,vector<string>> mp;
map<string,bool> vis;
void dfs(string x){
    if(ans.size() == (1 << n)){
        string output = ans[0];
        for(int i = 1; i < ans.size(); i++){
            output += ans[i].back();
        }
        cout << output << '\n';
        exit(0);
    }
    for(auto i : mp[x]){
        if(!vis[i]){
            vis[i] = 1;
            ans.push_back(i);
            dfs(i);
            ans.pop_back();
            vis[i] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0; i < (1 << n); i++){
        string s = "";
        for(int k = n - 1; k >= 0; k--){
            if(i & (1 << k)) s += "1";
            else s += "0";
        }
        string ss = s.substr(1);
        if(ss + '0' != s) mp[s].push_back(ss + '0');
        if(ss + '1' != s) mp[s].push_back(ss + '1');
    }
    string st = "";
    for(int i = 0; i < n; i++){
        st += "0";
    }
    vis[st] = 1;
    ans.push_back(st);
    dfs(st);
}
