//Binary Search Tree 구현(비재귀)
//정적 할당(메모리 풀) 방식으로 구현

//정적 할당의 장점
//1. 동적 할당을 하는 오버헤드가 없어짐
//2. 사용이 끝날 때마다(특히 여러 개의 테스트 케이스가 있는 경우) 메모리를 해제할 필요가 없음
//3. 모든 노드가 메모리 상에서 뭉쳐 있기 때문에 캐시 효율이 높아짐

#include <iostream>
#define MAX_NODE 10000

using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

//정적 할당(메모리 풀) 방식
Node *root;
Node node_pool[MAX_NODE];
int node_cnt;

Node* new_node(int x){
    node_pool[node_cnt].data = x;
    node_pool[node_cnt].left = nullptr;
    node_pool[node_cnt].right = nullptr;
    return &node_pool[node_cnt++];
}

//스택
struct Node_stk{
    int stack_cnt = 0;
    Node* stack_pool[MAX_NODE + 1];

    void clear(){ stack_cnt = 0; }
    bool empty(){ return stack_cnt == 0; }
    void push(Node* node){
        stack_pool[stack_cnt++] = node;
    }
    Node* top(){ return stack_pool[stack_cnt - 1]; }
    void pop(){ stack_cnt--; }
};

//초기화
void init(){
    node_cnt = 0;
    root = nullptr;
}

//노드 추가
void insert(int x){
    if(root == nullptr){
        root = new_node(x);
        return;
    }

    for(Node* node = root; node->data != x; ){
        Node** child = x < node->data ? &node->left : &node->right;
        if(*child == nullptr){
            *child = new_node(x);
            return;
        }
        node = *child;
    }
}

//노드 삭제
void remove(int x){
    Node* parent = nullptr;
    Node* node = root;

    while(node != nullptr && node->data != x){
        parent = node;
        node = x < node->data ? node->left : node->right;
    }

    if(node == nullptr){
        return;
    }

    if(node->left == nullptr && node->right == nullptr){
        if(parent == nullptr){
            root = nullptr;
        }
        else{
            (node == parent->left ? parent->left : parent->right) == nullptr;
        }
    }
    else if(node->left == nullptr){
        *node = *node->right;
    }
    else if(node->right == nullptr){
        *node = *node->left;
    }
    else{
        parent = node;
        Node* successor = node->right;

        while(successor->left != nullptr){
            parent = successor;
            successor = successor->left;
        }

        node->data = successor->data;
        (successor == parent->left ? parent->left : parent->right) = successor->right;
    }
}

//데이터 찾기
bool find(int x){
    Node* node = root;
    while(node != nullptr){
        if(node->data == x) return true;
        node = x < node->data ? node->left : node->right;
    }
    return false;
}

//전위 순회
void pre_order(){
    Node_stk stk;
    stk.push(root);

    while(!stk.empty()){
        Node* node = stk.top();
        stk.pop();

        cout << node->data << ' ';
        if(node->right != nullptr) stk.push(node->right);
        if(node->left != nullptr) stk.push(node->left);
    }
    cout << '\n';
}

//중위 순회
void in_order(){
    Node_stk stk;
    Node* node = root;

    while(!stk.empty() || node != nullptr){
        if(node != nullptr){
            stk.push(node);
            node = node->left;
        }
        else{
            node = stk.top();
            stk.pop();

            cout << node->data << ' ';
            node = node->right;
        }
    }
    cout << '\n';
}

//후위 순회
void post_order(){
    Node_stk stk1, stk2;
    stk1.push(root);

    while(!stk1.empty()){
        Node* node = stk1.top();
        stk1.pop();
        stk2.push(node);

        if(node->left != nullptr) stk1.push(node->left);
        if(node->right != nullptr) stk1.push(node->right);
    }

    while(!stk2.empty()){
        cout << stk2.top()->data << ' ';
        stk2.pop();
    }
    cout << '\n';
}

void traversal(int type){
    if(type == 1) pre_order();
    else if(type == 2) in_order();
    else post_order();
}

int main() {
	//0 : 트리 초기화
	//1 : 트리에 노드 삽입
	//2 : 트리에 노드 삭제
	//3 : 트리 탐색
	//4 : 트리 순회(1 : 전위, 2 : 중위, 3 : 후위)
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
			insert(x);
			break;

		case 2:
			cin >> x;
			remove(x);
			break;

		case 3:
			cin >> x;
			cout << (find(x) ? "found" : "not found") << '\n';
			break;

		case 4:
			cin >> x;
			if (x < 1 || x > 4) return cout << "invalid traversal type\n", 0;
			traversal(x);
			break;

        case 99:
            return 0;
		}
	}
}