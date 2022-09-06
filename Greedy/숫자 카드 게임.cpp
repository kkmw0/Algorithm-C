#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, result = 0;
    int arr[100];
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int min_value = 10001;
        for(int j = 0; j < m; j++){
            cin >> arr[j];
        }
        min_value = *min_element(arr, arr + m);
        result = max(result, min_value);
    }
    cout << result << "\n";
}