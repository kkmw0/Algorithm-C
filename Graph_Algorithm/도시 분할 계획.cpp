#include <bits/stdc++.h>

using namespace std;

int n, m;
int parent[100001];
vector<pair<int, pair<int, int>>> edges;

int findParent(int x){
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void UnionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < m; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.push_back({cost, {a, b}});
    }

    sort(edges.begin(), edges.end());

    int result = 0;
    int tmp;
    for(int i = 0; i < edges.size(); i++){
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if(findParent(a) != findParent(b)){
            tmp = cost;
            result += cost;
            UnionParent(a, b);
        }
    }
    cout << (result - tmp) << '\n';
}