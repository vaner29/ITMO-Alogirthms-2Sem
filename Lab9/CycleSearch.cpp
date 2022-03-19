#include <bits/stdc++.h>
 
using namespace std;
 
vector <int> graph[100000];
vector <int> used;
vector <int> stac;
int cycleStart, cycleEnd;
 
bool dfs(int v) {
    used[v] = 1;
 
    for (int u: graph[v]) {
        if (used[u] == 0){
            stac[u] = v;
            if (dfs (u)) return true;
        }
        else if (used[u] == 1){
            cycleEnd = v;
            cycleStart = u;
            return true;
        }
    }
    used[v] = 2;
    return false;
}
 
int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out","w", stdout);
    int n,m;
    cin >> n >> m;
    int x,y;
    for (int i = 0; i<m; i++){
        cin >> x >> y;
        graph[x-1].push_back(y-1);
    }
 
    stac.assign(n, -1);
    used.assign(n, 0);
    cycleStart = -1;
 
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            if (dfs(i))
                break;
        }
    }
 
    if (cycleStart == -1)
        cout <<"NO";
 
    else {
        cout <<"YES" << endl;
        vector <int> cycle;
        for (int v = cycleEnd; v!= cycleStart; v = stac[v])
            cycle.push_back (v);
        cycle.push_back (cycleStart);
        //reverse (cycle.begin(), cycle.end());
        for (int i = cycle.size() - 1; i >= 0; i-- )
            cout << cycle[i] + 1 <<" ";
    }
    return 0;
}
