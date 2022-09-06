#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(){
    int n, m, k;

    cin >> n >> m >> k;
    vector<int> vec(n);

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    //입력받은 수 정렬
    sort(vec.begin(), vec.end());

    //가장 큰 수 & 두 번째로 큰 수
    int first = vec[n - 1];
    int second = vec[n - 2];

    // 가장 큰 수가 더해지는 횟수 계산
    int cnt = k * m / (k + 1) + m % (k + 1);
    int result = cnt * first + (m - cnt) * second;

    cout << result << endl;
}