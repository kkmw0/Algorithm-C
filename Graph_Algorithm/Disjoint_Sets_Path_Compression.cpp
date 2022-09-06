#include <bits/stdc++.h>

using namespace std;

//��� ����(V)�� ����(Union ����)�� ����(E)
int v, e;
int parent[100001]; //�θ� ���̺� �ʱ�ȭ

//Ư�� ���Ұ� ���� ������ ã��(��� ����)
//find�Լ��� ��������� ȣ���� �ڿ� �θ� ���̺��� ����
int findParent(int x){
    //��Ʈ ��尡 �ƴ϶��, ��Ʈ ��带 ã�� ������ ��������� ȣ��
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

    //Union ������ ���� ����
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }

    //�� ���Ұ� ���� ���� ���
    cout << "�� ���Ұ� ���� ����: ";
    for(int i = 1; i <= v; i++){
        cout << findParent(i) << ' ';
    }
    cout << '\n';

    //�θ� ���̺� ���� ���
    cout << "�θ� ���̺�: ";
    for(int i = 1; i <= v; i++){
        cout << parent[i] << ' ';
    }
    cout << '\n';
}

