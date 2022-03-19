#include <bits/stdc++.h>
 
using namespace std;
 
vector <int> graph[100000];
vector <bool> used;
vector <int> order;
 
void topSort (int v) {
    used[v] = true;
    for (int u: graph[v]){
        if (!used[u])
            topSort(u);
    }
    order.push_back(v);
}
 
 
int main() {
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out","w", stdout);
    int n,m;
    cin >> n >> m;
    int x,y;
    for (int i = 0; i<m; i++){
        cin >> x >> y;
        graph[x-1].push_back(y-1);
    }
    used.assign(n, false);
 
 
    for (int i = 0; i < n; i++)
        if (!used[i])
             topSort(i);
 
    bool flag = false;
    for (int i = n - 1; i > 0; i--){
        for (int j = 0; j < graph[order[i]].size(); j++){
            if (graph[order[i]][j] == order[i-1]){
                flag = true;
                break;
            }
        }
        if (flag == false){
            cout << "NO";
            exit(0);
        }
        flag = false;
 
    }
    cout << "YES";
 
 
    return 0;
}
