#include <bits/stdc++.h>

using namespace std;

//����� ����(V)�� ����(Union ����)�� ����(E)
//����� ������ �ִ� 100,000����� ����
int v, e;
int parent[100001];

//��� ������ ���� ����Ʈ��, ���� ����� ���� ����
vector<pair<int, pair<int ,int>>> edges;
int result = 0;

//Ư�� ���Ұ� ���� ������ ã��
int findParent(int x){
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

//�� ���Ұ� ���� ������ ��ġ��
void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main(){
    cin >> v >> e;

    //�θ� ���̺�󿡼�, �θ� �ڱ� �ڽ����� �ʱ�ȭ
    for(int i = 1; i <= v; i++){
        parent[i] = i;
    }

    //��� ������ ���� ������ �Է� �ޱ�
    for(int i = 0; i < e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;

        //�������� �����ϱ� ���� Ʃ���� ù ��° ���Ҹ� ������� ����
        edges.push_back({cost, {a, b}});
    }

    //������ �������� ����
    sort(edges.begin(), edges.end());

    //������ �ϳ��� Ȯ��
    for(int i = 0; i < edges.size(); i++){
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        //����Ŭ�� �߻����� �ʴ� ��쿡�� ���տ� ����
        if(findParent(a) != findParent(b)){
            unionParent(a, b);
            result += cost;
        }
    }
    cout << result << '\n';
}