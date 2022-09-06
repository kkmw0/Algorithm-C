#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m;
int graph[101][101];;

int main(){
    cin >> n >> m;

    //최단 거리 테이블을 모두 무한으로 초기화
    for(int i = 0; i < 101; i++){
        fill(graph[i], graph[i] + 101, INF);
    }

    //자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
    for(int a = 1; a <= n; a++){
        for(int b = 1; b <= n; b++){
            if(a == b) graph[a][b] = 0;
        }
    }

    //각 간선에 대한 정보를 입력 받아, 그 값으로 초기화
    for(int i = 0; i < m; i++){
        //A에서 B로 가는 비용은 1이라고 설정
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    int k, x;
    cin >> x >> k;

    for(int i = 1; i <= n; i++){
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){
                graph[a][b] = min(graph[a][b], graph[a][i] + graph[i][b]);
            }
        }
    }

    int result = graph[1][k] + graph[k][x];
    if(result >= INF) cout << -1 << '\n';
    else cout << result << '\n';
}