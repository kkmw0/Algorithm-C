#include <bits/stdc++.h>

using namespace std;

//노드 개수(V)와 간선(Union 연산)의 개수(E)
int v, e;
int parent[100001]; //부모 테이블 초기화

//특정 원소가 속한 집합을 찾기
//모든 노드를 거슬러 올라가는 경우 최대 O(V)의 시간이 소요
//노드의 개수가 V이고, find 또는 union 연산의 개수가 M개 일때, O(VM)의 시간복잡도(비효율)
int findParent(int x){
    //루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if(x == parent[x]) return x;
    return findParent(parent[x]);
}

//두 원소가 속한 집합을 합치기
void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main(){
    cin >> v >> e;

    //부모 테이블상에서, 부모를 자기 자신으로 초기화
    for(int i = 1; i <= v; i++){
        parent[i] = i;
    }

    //Union 연산을 각각 수행
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    //각 원소가 속한 집합 출력
    cout << "각 원소가 속한 집합: ";
    for(int i = 1; i <= v; i++){
        cout << findParent(i) << ' ';
    }
    cout << '\n';

    //부모 테이블 내용 출력
    cout << "부모 테이블: ";
    for(int i = 1; i <= v; i++){
        cout << parent[i] << ' ';
    }
    cout << '\n';
}

