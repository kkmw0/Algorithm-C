#include <bits/stdc++.h>

using namespace std;

//���� Ž�� �ҽ��ڵ� ����(��� �Լ�)
int binarySearch(vector<int>& arr, int target, int start, int end) {
    if (start > end) return -1;
    int mid = (start + end) / 2;
    //ã�� ��� �߰��� �ε��� ��ȯ
    if (arr[mid] == target) return mid;
    //�߰����� ������ ã���� �ϴ� ���� ���� ��� ���� Ȯ��
    else if (arr[mid] > target) return binarySearch(arr, target, start, mid - 1);
    //�߰����� ������ ã���� �ϴ� ���� ū ��� ������ Ȯ��
    else return binarySearch(arr, target, mid + 1, end);
}

int n, target;
vector<int> arr;

int main(void) {
    //n(������ ����)�� target(ã���� �ϴ� ��)�� �Է¹ޱ� 
    cin >> n >> target;
    //��ü ���� �Է¹ޱ� 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    //���� Ž�� ���� ��� ��� 
    int result = binarySearch(arr, target, 0, n - 1);
    if (result == -1) {
        cout << "���Ұ� �������� �ʽ��ϴ�." << '\n';
    }
    else {
        cout << result + 1 << '\n';
    }
}