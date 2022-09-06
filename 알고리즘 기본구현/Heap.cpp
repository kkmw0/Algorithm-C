//배열을 이용한 최대 힙 구현
//힙은 완전이진트리이므로 배열로 구현하면, 간단한 수식을로 부모, 자식 노드에 접근할 수 있음

//루트 노드의 인덱스가 1로 시작하는 경우 (0번 노드는 버림)
//부모의 인덱스 = (자식의 인덱스) / 2
//왼쪽 자식 인덱스 = (부모의 인덱스) * 2
//오른쪽 자식 인덱스 = (부모의 인덱스) * 2 + 1
//노드 하나의 메모리만 버리면 부모, 자식의 인덱스를 구하는 방법이 더 짧아지므로 편리

#include <iostream>
#include <algorithm>
#include <cassert>
#define MAX_NODE 100000
#define parent (i >> 1)
#define left (i << 1)
#define right (i << 1 | 1)

using namespace std;

int maxHeap[MAX_NODE + 1];
int minHeap[MAX_NODE + 1];
int maxHeap_size;
int minHeap_size;

//초기화
void init(){
    maxHeap_size = 0;
    minHeap_size = 0;
}

//최대 힙에 삽입
void push_max(int x){
    maxHeap[++maxHeap_size] = x;
    for(int i = maxHeap_size; parent != 0 && maxHeap[parent] < maxHeap[i]; i >>= 1){
        swap(maxHeap[parent], maxHeap[i]);
    }

}

//최소 힙에 삽입
void push_min(int x){
    minHeap[++minHeap_size] = x;
    for(int i = minHeap_size; parent != 0 && minHeap[parent] > minHeap[i]; i >>= 1){
        swap(minHeap[parent], minHeap[i]);
    }

}

//최대 힙에서 최대값 리턴
int top_max(){
    assert(maxHeap_size != 0);
    return maxHeap[1];
}

//최소 힙에서 최소값 리턴
int top_min(){
    assert(minHeap_size != 0);
    return minHeap[1];
}

//최대 힙에서 최대값 삭제
int pop_max(){
    assert(maxHeap_size != 0);
    int result = maxHeap[1];
    maxHeap[1] = maxHeap[maxHeap_size--];
    for(int i = 1; left <= maxHeap_size;){
        const int max_child = left == maxHeap_size || maxHeap[left] > maxHeap[right] ? left : right;
        if(maxHeap[max_child] > maxHeap[i]){
            swap(maxHeap[max_child], maxHeap[i]);
            i = max_child;
        }
        else{
            break;
        }
    }
    return result;
}

//최소 힙에서 최대값 삭제
int pop_min(){
    assert(minHeap_size != 0);
    int result = minHeap[1];
    minHeap[1] = minHeap[minHeap_size--];
    for(int i = 1; left <= minHeap_size;){
        const int min_child = left == minHeap_size || minHeap[left] < minHeap[right] ? left : right;
        if(minHeap[min_child] < minHeap[i]){
            swap(minHeap[min_child], minHeap[i]);
            i = min_child;
        }
        else{
            break;
        }
    }
    return result;
}

int main() {
	//0 : 힙 초기화
	//1 : 최대 힙에 노드 삽입
	//2 : 최소 힙에 노드 삽입
    //3 : 최대 힙에서 최대값 출력
	//4 : 최소 힙에서 최소값 출력
	//5 : 최대 힙에서 최대값 삭제 후 출력
    //6 : 최소 힙에서 최소값 삭제 후 출력
    //99 : 종료
    init();

	int cmd, x;
	for (;;) {
		cin >> cmd;
		switch (cmd) {
		case 0:
			init();
			break;

		case 1:
			cin >> x;
			push_max(x);
			break;

		case 2:
			cin >> x;
			push_min(x);
			break;

		case 3: {
			int topMax = top_max();
			cout << "maxValue = " << topMax << '\n';
			break;
        }

		case 4: {
			int topMin = top_min();
			cout << "minValue = " << topMin << '\n';
			break;
        }

		case 5: {
			int delete_maxValue = pop_max();
			cout << delete_maxValue << " is deleted" << '\n';
			break;
        }

        case 6: {
			int delete_minValue = pop_min();
			cout << delete_minValue << " is deleted" << '\n';
			break;
        }

        case 99:
            return 0;
		}
	}
}