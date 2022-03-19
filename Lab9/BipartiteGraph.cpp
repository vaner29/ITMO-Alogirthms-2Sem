#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> graph[200000];
int used[200000];
 
void dfs(int v) {
    for (int u: graph[v]) {
            if (used[u] == used [v]){
                cout << "NO";
                exit(0);
            }
            else if (used[u] == 0){
                if (used[v] == 1)
                    used[u] = 2;
                else
                    used[u] = 1;
                dfs(u);
            }
    }
}
 
 
int main() {
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out","w", stdout);
    int n,m;
    cin >> n >> m;
    int x,y;
    for (int i = 0; i<m; i++){
        cin >> x >> y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
 
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            used[i] = 1;
            dfs(i);
        }
    }
   cout << "YES";
return 0;
}
