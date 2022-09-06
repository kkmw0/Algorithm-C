#include <bits/stdc++.h>

using namespace std;

class Fruit {
public:
    string name;
    int score;
    Fruit(string name, int score) {
        this->name = name;
        this->score = score;
    }
    //���� ������ '������ ���� ����'
    bool operator <(Fruit &other) {
        return this->score < other.score; 
    }
};

int main(void) {
    int n = 3;
    Fruit fruits[] = {
        Fruit("�ٳ���", 2),
        Fruit("���", 5),
        Fruit("���", 3)
    };
    sort(fruits, fruits + n);
    for(int i = 0; i < n; i++) {
        cout << '(' << fruits[i].name << ',' << fruits[i].score << ')' << ' ';
    }
}