#include <bits/stdc++.h>

using namespace std;

vector<int> v1, v2;

int compare(int a, int b){
    return a > b;
}

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v2.push_back(x);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), compare);

    for(int i = 0; i < k; i++){
        if(v1[i] < v2[i]) swap(v1[i], v2[i]);
        else break;
    }

    long long result = 0;
    for(int i = 0; i < n; i++){
        result += v1[i];
    }
    cout << result << '\n';
}