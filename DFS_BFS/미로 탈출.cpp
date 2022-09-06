#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[200][200];
int visited[200][200];

//상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //현재 위치에서 4가지 방향으로 위치 확인
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            //미로 찾기 공간을 벗어난 경우 무시
            if(nx <= -1 || nx >= n || ny <= -1 || ny >= m) continue;

            //벽이 아니거나, 처음 방문하는 경우에만 최단 거리 기록
            if(arr[nx][ny] == 1 && !visited[nx][ny]){
                visited[nx][ny] = visited[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return visited[n - 1][m - 1];
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    cout << bfs(0, 0) << "\n";
}