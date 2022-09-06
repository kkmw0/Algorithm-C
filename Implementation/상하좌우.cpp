#include <bits/stdc++.h>

using namespace std;

char direction[4] = {'L', 'R', 'U', 'D'};
int dx[4] = {0, 0, -1 ,1};
int dy[4] = {-1, 1, 0, 0};

int main(){
    int n;
    int x = 1, y = 1;
    string mov;

    cin >> n;
    cin.ignore();
    getline(cin, mov);

    for(int i = 0; i < mov.size(); i++){
        int nx, ny;
        char ch = mov[i];
        for(int j = 0; j < 4; j++){
            if(ch == direction[j]){
                nx = x + dx[j];
                ny = y+ dy[j];
                break;
            }
        }

        if(nx < 1 || nx > n || ny < 1 || ny > n) continue;

        x = nx;
        y = ny;
    }
    cout << x << ' ' << y << "\n";
}