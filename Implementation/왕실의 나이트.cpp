#include <bits/stdc++.h>

using namespace std;

//상, 하, 좌, 우 이동방향(x, y)
int steps[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};

int main(){
    int res = 0;
    string pos;
    cin >> pos;

    int x = pos[1] - '0';
    int y = pos[0] - 'a' + 1;

    for(int i = 0; i < 8; i++){
        int nx = x + steps[i][0];
        int ny = y + steps[i][1];

        if(nx < 1 || nx > 8 || ny < 1 || ny > 8) continue;
        res += 1;
    }
    cout << res << "\n";
}