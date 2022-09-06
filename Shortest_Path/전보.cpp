#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m, start;
vector<pair<int, int>> graph[30001];
int d[30001];

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    d[start] = 0;

    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist) continue;

        for(int i = 0; i < graph[now].size(); i++){
            int cost = d[now] + graph[now][i].second;
            if(cost < d[graph[now][i].first]){
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main(){
    cin >> n >> m >> start;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    fill_n(d, 30001, INF);
    dijkstra(start);

    int result = 0;
    int time = -1;
    for(int i = 1; i <= n; i++){
        if(d[i] < INF && i != start){
            result += 1;
            time = d[i] > time ? d[i] : time;
        }
    }
    cout << result  << ' ' << time << '\n';
}