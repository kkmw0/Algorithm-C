#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v1;
vector<int> v2;

bool binary_search(vector<int>& v1, int target, int start, int end){
    while(start <= end){
        int mid = (start + end) / 2;

        if(v1[mid] == target) return true;
        else if(v1[mid] > target) end = mid - 1;
        else start = mid + 1;
    }
    return false;
}

int main(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v1.push_back(x);
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        v2.push_back(x);
    }

    sort(v1.begin(), v1.end());
    for(int i = 0; i < m; i++){
        if(binary_search(v1, v2[i], 0, n - 1)){
            cout << "yes\n";
        }
        else cout << "no\n";
    }
}