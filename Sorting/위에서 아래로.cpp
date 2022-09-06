#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int compare(int a, int b){
    return a > b;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), compare);
    for(int i = n - 1; i >= 0; i--){
        cout << v[i] << ' ';
    }
}