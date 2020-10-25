#include<bits/stdc++.h>

using namespace std;

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph
vector<bool> isArticulationPoint;
vector<bool> vis;
vector<int> in, lo;
int t = 0;

void dfs(int v, int p = -1) {
    vis[v] = true;
    in[v] = lo[v] = t++;
    int children = 0;
    for (int nbr : adj[v]) {
        if (nbr == p) continue;
        if (vis[nbr]) {
            lo[v] = min(lo[v], in[nbr]);
        } else {
            ++children;
            dfs(nbr, v);
            lo[v] = min(lo[v], lo[nbr]);
            if (lo[nbr] >= in[v] && p!=-1)
                isArticulationPoint[v] = true;
        }
    }
    
    if(p == -1 && children > 1)
        isArticulationPoint[v] = true;;
}


int main(){

    t = 0;
    adj = vector<vector<int>> (n);
    vis = vector<bool> (n, false);
    in = vector<int> (n, -1); 
    lo = vector<int> (n, -1);
    isArticulationPoint = vector<bool> (n, false);
    for (int i = 0; i < n; ++i) {
        if (vis[i] == false)
            dfs(i);
    }

  return 0;
}
