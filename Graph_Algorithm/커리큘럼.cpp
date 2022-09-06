#include <bits/stdc++.h>

using namespace std;

int n;
int indegree[501];
int times[501];
vector<int> graph[501];

void TopologySort(){
    queue<int> q;
    vector<int> result(501);

    for(int i = 1; i <= n; i++){
        result[i] = times[i];
    }

    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i = 0; i < graph[now].size(); i++){
            result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);
            indegree[graph[now][i]] -= 1;

            if(indegree[graph[now][i]] == 0){
                q.push(graph[now][i]);
            }
        }
    }
    //위상 정렬을 수행한 결과를 출력
    for(int i = 1; i <= n; i++){
        cout << result[i] << '\n';
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        //첫 번째 수는 시간 정보를 담고 있음
        int x;
        cin >> x;
        times[i] = x;

        //해당 강의를 듣기 위해 먼저 들어야 하는 강의들의 번호 입력
        while(true){
            cin >> x;
            if(x == -1) break;
            indegree[i] += 1;
            graph[x].push_back(i);
        }
    }
    TopologySort();
}