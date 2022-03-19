#include <bits/stdc++.h>
 
using namespace std;
 
vector <int> graph[200000], graphT[200000];
vector <int> order;
bool used[20000];
int comp[20000];
int currComp = 0;
 
void topSort (int v) {
    used[v] = true;
    for (int u: graph[v]){
        if (!used[u])
            topSort(u);
    }
    order.push_back(v);
}
 
void dfsComps(int v){
    comp[v] = currComp;
    for (int u: graphT[v])
        if (comp[u] == 0)
            dfsComps(u);
}
 
int main() {
    freopen("cond.in", "r", stdin);
    freopen("cond.out","w", stdout);
    int n,m;
    cin >> n >> m;
    int x,y;
    for (int i = 0; i<m; i++){
        cin >> x >> y;
        graph[x-1].push_back(y-1);
        graphT[y-1].push_back(x-1);
    }
 
 
    for (int i = 0; i < n; i++)
        if (!used[i])
            topSort(i);
 
    reverse(order.begin(), order.end());
    for (int v : order)
        if (comp[v] == 0){
            currComp++;
            dfsComps(v);
        }
    cout << currComp <<endl;
    for (int i = 0; i<n; i++)
        cout << comp[i] << " ";
 
    return 0;
}
