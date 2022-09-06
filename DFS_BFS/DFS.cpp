#include <bits/stdc++.h>
#define INF 999999999 //무한의 비용

using namespace std;

//2차원 배열을 이용해 인접 행렬 표현
int graph1[3][3] = {
        {0, 7 ,5},
        {7, 0 , INF},
        {5, INF, 0}
    };

//행이 3개인 인접 리스트 표현
vector<pair<int, int>> graph2[3];

//인접 행렬 표현 출력
void print_Adjacency_Matrix(){
     for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << graph1[i][j] << ' ';
        }
        cout << '\n';
    }
}

//인접 리스트 표현 출력 및 노드 정보 저장
void print_Adjacency_List(){
    //노드 0에 연결된 노드 정보 저장 {노드, 거리}
    graph2[0].push_back({1, 7});
    graph2[0].push_back({2, 5});

    //노드 1에 연결된 노드 정보 저장 {노드, 거리}
    graph2[1].push_back({0, 7});

    //노드 2에 연결된 노드 정보 저장 {노드, 거리}
    graph2[2].push_back({0, 5});

    // 그래프 출력
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < graph2[i].size(); j++) {
            cout << '(' << graph2[i][j].first << ',' << graph2[i][j].second << ')' << ' ';
        }
        cout << '\n';
    } 
}

int main(){
    print_Adjacency_Matrix();
    cout << "-----------------------" << '\n';
    print_Adjacency_List();
}