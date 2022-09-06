#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[1000][1000];

//DFS 함수 정의
bool dfs(int x, int y) {
    //주어진 범위를 벗어나는 경우 
    if(x <= -1 || x >= n || y <= -1 || y >= m)
        return false;

    //현재 노드를 방문하지 않았다면
    if(arr[x][y] == 0){
        //방문 처리 후, 상하좌우로 탐색
        arr[x][y] = 1;
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y - 1);
        dfs(x, y + 1);
        return true;
    }
    return false;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dfs(i, j))
                cnt += 1;
        }
    }
    cout << cnt << "\n";
}