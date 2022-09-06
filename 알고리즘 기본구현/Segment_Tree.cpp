//기초적인 형태의 세그먼트 트리 구현
//기초적인 형태란, 교환법칙이 성립하는 연산에 대한 range query를 처리하는 세그먼트 트리

//세그먼트 트리는 point update와 range query를 모두 O(logN)의 시간에 처리할 수 있는 자료구조
//세그먼트 트리는 이진 트리로. 구간의 길이가 1인(원소의 개수가 하나인) 구간은 리프 노드가 되고, 나머지 노드는 자식 노드를 합친 구간 합이 됨
//세그먼트 트리의 노드 개수는 2N - 1개
//0번 노드는 버리고, 1번 노드가 루트가 되는 방식으로 구현하면 완전 이진 트리의 모습을 하며,
//필요한 배열의 길이는 2N이 되고, 리프 노드의 인덱스는 [ N , 2N )가 된다.

#include <iostream>
#define MAX_NODE 10000
using namespace std;

int arr[MAX_NODE];
int segtree[2 * MAX_NODE];
int n;

//원소의 개수가 하나인 구간은 리프 노드가 되고,
//나머지 노드는 자식 노드를 합친 구간 합이 되도록 초기화
void init(){
    for(int i = 0; i < n; i++){
        segtree[i + n] = arr[i];
    }

    for(int i = n - 1; i != 0; i--){
        segtree[i] = segtree[i << 1] + segtree[i << 1 | 1];
    }
}

//i번째 리프 노드의 값을 x로 변경
//해당 리프 노드부터 루트 노드까지 부모 노드를 타고 올라가면서 조상 노드의 값을 갱신
void update(int idx, int x){
    segtree[idx += n] = x;
    while(idx >>= 1){
        segtree[idx] = segtree[idx << 1] + segtree[idx << 1 | 1];
    }
}

//[ l , r ) 구간 합
int query(int l, int r){
    int result = 0;
    for(l += 5, r += 5; l != r; l >>= 1, r >>= 1){
        if(l & 1) result += segtree[l++];
        if(r & 1) result += segtree[--r];
    }
    return result;
}

int main(void){
    cout << "Input N(MAX 10000) : ";
    cin >> n;

    cout << "Input nodes Value(1 ~ N)" << '\n';
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

	//0 : Segment_Tree 초기화
	//1 : Point Update(a번째 값을 b로 변경)
	//2 : Range Query([l, r) 구간 합)
    //3 : 리프노드 값 출력
    //99 : 종료
    init();

	int cmd, a, b;
	for (;;) {
		cin >> cmd;
		switch (cmd) {
		case 0:
			init();
			break;

		case 1:
            //a번째 값을 b로 변경
			cin >> a >> b;
            update(a, b);
            cout << a << " index value changed to " << b << '\n';
			break;

		case 2: {
            //a이상 b미만의 구간 합
			cin >> a >> b;
			int result = query(a, b);
            cout << "Sum of intervals between " << a << " and " << b << " indexes is = " << result << '\n';
			break;
        }

        case 3:
            cout << "Segment Tree = ";
            for(int i = n; i < 2 * n; i++){
                cout << segtree[i] << ' ';
            }
            cout << '\n';
            break;

        case 99:
            return 0;
		}
	}
    return 0;
}