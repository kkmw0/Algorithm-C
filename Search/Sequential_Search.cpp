#include <bits/stdc++.h>

using namespace std;

//���� Ž�� �ҽ��ڵ� ����
int sequantialSearch(int n, string target, vector<string> arr) {
    //�� ���Ҹ� �ϳ��� Ȯ���ϸ�
    for (int i = 0; i < n; i++) {
        //������ ���Ұ� ã���� �ϴ� ���ҿ� ������ ���
        if (arr[i] == target) {
            return i + 1; //������ ��ġ ��ȯ (�ε����� 0���� �����ϹǷ� 1 ���ϱ�)
        }
    }
    return -1; //���Ҹ� ã�� ���� ��� -1 ��ȯ
}

int n; //������ ����
string target; //ã���� �ϴ� ���ڿ�
vector<string> arr;

int main(void) {
    cout << "������ ���� ������ �Է��� ���� �� ĭ ��� ã�� ���ڿ��� �Է��ϼ���." << '\n';
    cin >> n >> target;
    
    cout << "�ռ� ���� ���� ������ŭ ���ڿ��� �Է��ϼ���. ������ ���� �� ĭ���� �մϴ�." << '\n';
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        arr.push_back(x);
    }

    //���� Ž�� ���� ��� ���
    cout << sequantialSearch(n, target, arr) << '\n';
}