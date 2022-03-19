#include <bits/stdc++.h>
 
using namespace std;
 
vector <int> graph[100000];
int used[100000];
vector <int> stac;
 
void dfs(int v) {
    used[v] = 1;
 
    for (int u: graph[v]) {
        if (used[u] == 1){
            cout << "-1";
            exit(0);
        }
        if (used[u] == 0) {
            dfs(u);
        }
    }
    used[v] = 2;
    stac.push_back(v+1);
}
 
int main() {
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out","w", stdout);
    int n,m;
    cin >> n >> m;
    int x,y;
    for (int i = 0; i<m; i++){
        cin >> x >> y;
        graph[x-1].push_back(y-1);
    }
 
    for (int i = 0; i < n; i++) {
        if (used[i] != 2) {
            dfs(i);
        }
    }
    for (int i = n-1; i >= 0; i--){
        cout << stac[i] << " ";
    }
    return 0;
}
