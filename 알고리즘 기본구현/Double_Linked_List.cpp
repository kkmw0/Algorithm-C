//Double Linked List 구현
//정적 할당(메모리 풀) 방식으로 구현

//정적 할당의 장점
//1. 동적 할당을 하는 오버헤드가 없어짐
//2. 사용이 끝날 때마다(특히 여러 개의 테스트 케이스가 있는 경우) 메모리를 해제할 필요가 없음
//3. 모든 노드가 메모리 상에서 뭉쳐 있기 때문에 캐시 효율이 높아짐

#include <iostream>
#define MAX_NODE 10000

using namespace std;
enum { INIT = 0, ADD_HEAD, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99 };

//Double Linked List Node
struct Node{
    int data;
    Node *next, *prev;
};

//정적 할당(메모리 풀) 방식
Node node_pool[MAX_NODE];
Node* head;
int node_cnt;

Node* new_node(int data){
    node_pool[node_cnt].data = data;
    node_pool[node_cnt].next = nullptr;
    node_pool[node_cnt].prev = nullptr;
    return &node_pool[node_cnt++];
}

//초기화
void init(){
    node_cnt = 0;
    head = new_node(0);
}

//맨 앞에 노드 추가
void addNode2Head(int data){
    Node* node = new_node(data);
    if(head->next != nullptr){
        node->next = head->next;
        node->next->prev = node;
    }
    node->prev = head;
    head->next = node;
}

//맨 뒤에 노드 추가
void addNode2Tail(int data){
    Node* ptr = head;
    Node* node = new_node(data);

    while(ptr->next != nullptr) ptr = ptr->next;
    node->prev = ptr;
    ptr->next = node;
}

//지정된 순서(num)에 노드 추가(1 - 2 - 3 - 4 - ...)
void addNode2Num(int data, int num){
    Node* ptr = head;
    Node* node = new_node(data);

    int cnt = 1;
    while(ptr->next != nullptr && cnt != num){
        ptr = ptr->next;
        cnt++;
    }

    if(ptr->next != nullptr){
        node->next = ptr->next;
        node->next->prev = node;
    }
    node->prev = ptr;
    ptr->next = node;
}

//data를 가진 node의 순서를 리턴
int findNode(int data){
    Node* ptr = head;

    int idx = 1;
    while(ptr->next != nullptr && ptr->next->data != data){
        idx++;
        ptr = ptr->next;
    }
    return idx;
}

//data를 가진 노드를 삭제
void removeNode(int data){
    Node* ptr = head->next;

    while(ptr != nullptr){
        if(ptr->data == data){
            if(ptr->prev == head){
                head->next = ptr->next;
                head->next->prev = head;
            }
            else{
                if(ptr->next != nullptr){
                    ptr->next->prev = ptr->prev;
                    ptr->prev->next = ptr->next;
                }
                else{
                    ptr->prev->next = nullptr;
                }
            }
        }
        ptr = ptr->next;
    }
}

//노드의 data 정보를 차례대로 output[]에 저장하고 노드 갯수를 리턴
int getList(int output[MAX_NODE]){
    Node* ptr = head->next;

    int idx = 0;
    while(ptr != nullptr){
        output[idx++] = ptr->data;
        ptr = ptr->next;
    }
    return idx;
}

//노드의 data 정보를 역순으로 output[]에 저장하고 노드 갯수를 리턴
int getReversedList(int output[MAX_NODE]){
    Node *ptr = head;

    while(ptr->next != nullptr) ptr = ptr->next;

    int idx = 0;
    while(ptr->prev != nullptr){
        output[idx++] = ptr->data;
        ptr = ptr->prev;
    }
    return idx;
}

int main(void){
    //0 : 초기화
    //1 : 맨 앞에 노드 추가
    //2 : 맨 뒤에 노드 추가
    //3 : 지정된 순서(num)에 노드 추가(1 - 2 - 3 - 4 - ...)
    //4 : data를 가진 node의 순서를 리턴
    //5 : 주어진 data값을 가진 노드 삭제
    //5 : 정방향 출력
    //6 : 역방향 출력
    //99 : 종료
    init();

    while (1) {
	    int cmd, data, num, cnt, i = 0;
	    int output[MAX_NODE] = { 0 };

		cin >> cmd;
		switch (cmd) {
        case INIT:
            init();
            break;

		case ADD_HEAD:
			cin >> data;
			addNode2Head(data);
			break;

		case ADD_TAIL:
			cin >> data;
			addNode2Tail(data);
			break;

		case ADD_NUM:
			cin >> data >> num;
			addNode2Num(data, num);
			break;

		case FIND:
			cin >> data;
			num = findNode(data);
			printf("%d\n", num);
			break;

		case REMOVE:
			cin >> data;
			removeNode(data);
			break;

		case PRINT:
			cnt = getList(output);
            cout << "Node = ";
			while (cnt--)
				cout << output[i++] << ' ';
			cout << '\n';
			break;

		case PRINT_REVERSE:
			cnt = getReversedList(output);
            cout << "Node = ";
			while (cnt--)
				cout << output[i++] << ' ';
			cout << '\n';
			break;

		case END:
			return 0;
		}
	}
}