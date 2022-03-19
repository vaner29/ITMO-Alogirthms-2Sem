#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> graph[100000];
vector <int> order;
bool used[100000];
bool win[100000];
 
 
void topSort (int v) {
    used[v] = true;
    for (int u: graph[v]){
        if (!used[u])
            topSort(u);
    }
    order.push_back(v);
}
 
 
 
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out","w", stdout);
    int n,m,s;
    cin >> n >> m >> s;
    int x,y;
    for (int i = 0; i<m; i++){
        cin >> x >> y;
        graph[x-1].push_back(y-1);
    }
 
    topSort(s-1);
 
    for (int i = 0; i < n; i++)
        win[i] = true;
    bool flag = false;
    for (int u: order){
        if (graph[u].size() == 0)
            win[u] = false;
        else {
            for (int q: graph[u]){
                if (win[q] == false){
                    flag = true;
                    break;
                }
            }
            if (!flag)
                win[u] = false;
 
        }
        flag = false;
 
    }
    if (win[s-1]) cout <<"First player wins";
    else cout << "Second player wins";
 
 
    return 0;
}
