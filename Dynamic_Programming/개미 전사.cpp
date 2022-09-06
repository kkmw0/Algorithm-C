#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100];
int d[100];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    d[0] = arr[0];
    d[1] = max(arr[0], arr[1]);
    for(int i = 2; i < n; i++){
        d[i] = max(d[i - 1], d[i - 2] + arr[i]);
    }
    cout << d[n - 1] << '\n';
}