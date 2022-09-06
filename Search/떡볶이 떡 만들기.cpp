#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int start = 0;
    int end = 1e9;
    int res = 0;

    while(start <= end){
        int mid = (start + end) / 2;
        long long int total = 0;

        for(int i = 0; i < n; i++){
            if(v[i] > mid)
                total += v[i] - mid;
        }

        if(total < m) end = mid - 1;
        else{
            //�ִ��� �� �߶��� ���� �����̹Ƿ�, ���⿡�� res�� ��� 
            res = mid;
            start = mid + 1;
        }
    }
    cout << res << '\n';
}