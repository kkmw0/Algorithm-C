#include <bits/stdc++.h>

using namespace std;

long long d1[100];
long long d2[100];

//피보나치 함수를 재귀함수로 구현(탑다운 다이나믹 프로그래밍)
long long fibo1(int x){
    if(x == 1 || x == 2){
        return 1;
    }

    if(d1[x] != 0){
        return d1[x];
    }

    d1[x] = fibo1(x - 1) + fibo1(x - 2);
    return d1[x];
}

//피보나치 함수를 반복문으로 구현(보텀업 다이나믹 프로그래밍)
long long fibo2(int x){
    d2[1] = 1;
    d2[2] = 1;

    for(int i = 3; i <= x; i++){
        d2[i] = d2[i - 1] + d2[i - 2];
    }
    return d2[x];
}

int main(){
    cout << fibo1(50) << '\n';
    cout << fibo2(50) << '\n';
}