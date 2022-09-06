#include <bits/stdc++.h>

using namespace std;

int n, m;
int parent[100001];
vector<string> ans;

int findParent(int x){
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void UnionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < m; i++){
        int oper, a, b;
        cin >> oper >> a >> b;

        if(oper == 0){
            UnionParent(a, b);
        }
        else{
            if(findParent(a) != findParent(b)){
                ans.push_back("NO");
            }
            else{
                ans.push_back("YES");
            }
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << '\n';
    }
}