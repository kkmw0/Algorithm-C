#include <bits/stdc++.h>

using namespace std;

//����� ����(V)�� ������ ����(E)
//����� ������ �ִ� 100,00����� ����
int v, e;

//��� ��忡 ���� ���������� 0���� �ʱ�ȭ
int indegree[100001];

//�� ��忡 ����� ���� ������ ��� ���� ���� ����Ʈ �ʱ�ȭ
vector<int> graph[100001];

void topologySort(){
    vector<int> result; //�˰��� ���� ����� ���� ����Ʈ
    queue<int> q;       //ť ���̺귯�� ���

    //ó�� ������ ���� ���������� 0�� ��带 ť�� ����
    for(int i = 1; i <= v; i++){
        if(indegree[i] == 0) q.push(i);
    }

    //ť�� �� ������ �ݺ�
    while(!q.empty()){
        //ť���� ���� ������
        int now = q.front();

        q.pop();
        result.push_back(now);

        //�ش� ���ҿ� ����� ������ ������������ 1 ����
        for(int i = 0; i < graph[now].size(); i++){
            indegree[graph[now][i]] -= 1;

            //���Ӱ� ���������� 0�� �Ǵ� ��带 ť�� ����
            if(indegree[graph[now][i]] == 0){
                q.push(graph[now][i]);
            }
        }
    }

    //���� ������ ������ ����� ���
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << ' ';
    }
    cout << '\n';
}

int main(){
    cin >> v >> e;

    //���� �׷����� ��� ���� ������ �Է� �ޱ�
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);  //���� A���� B�� �̵� ����
        //���� ������ 1 ����
        indegree[b] += 1;
    }

    topologySort();
}