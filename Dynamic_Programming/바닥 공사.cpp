#include <bits/stdc++.h>

using namespace std;

int n;
int d[1001];

int dp(int x){
    d[1] = 1;
    d[2] = 3;

    for(int i = 3; i <= x; i++){
        d[i] = d[i - 1] + (2 * d[i - 2]);
    }
    return d[x];
}

int main(){
    cin >> n;
    int result = dp(n) % 796796;
    cout << result << '\n';
}