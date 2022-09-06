#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    int cnt = 0;
    cin >> n >> k;

    while(true){
        int tmp = n % k;
        cnt += tmp;
        n -= tmp;

        if(n < k){
            break;
        }

        n /= k;
        cnt++;
    }
    cnt += (n - 1);
    cout << cnt << "\n";
}