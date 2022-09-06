#include <bits/stdc++.h>

using namespace std;

int check[50][50];
int arr[50][50];

//북, 동, 남, 서 이동방향
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int direction;

void is_turn(){
    direction -= 1;
    if(direction == -1) direction = 3;
}

int main(){
    int n, m;
    int x, y;

    cin >> n >> m;
    cin >> x >> y >> direction;
    check[x][y] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int cnt = 1;
    int turn = 0;
    while(true){
        is_turn();

        int nx = x + dx[direction];
        int ny = y + dy[direction];

        //회전한 이후 정면에 아직 가보지 않은 칸이 존재 & 바다가 아닌 경우 이동
        if(check[nx][ny] == 0 && arr[nx][ny] == 0){
            check[nx][ny] = 1;
            x = nx;
            y = ny;
            cnt += 1;
            turn = 0;
            continue;
        }
        //회전한 이후 정면에 가보지 않은 칸이 없거나 바다인 경우
        else
            turn += 1;

        //네 방향 모두 갈 수 없는 경우
        if(turn == 4){
            nx = x - dx[direction];
            ny = y - dy[direction];

            //뒤로 갈 수 없는 경우
            if(arr[nx][ny] == 1) break;
            //뒤로 갈 수 있는 경우
            else{
                x = nx;
                y = ny;
                turn = 0;
                continue;
            }
        }
    }
    cout << cnt << "\n";
}