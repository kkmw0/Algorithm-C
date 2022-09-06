//Binary Search Tree 구현(재귀)
//정적 할당(메모리 풀) 방식으로 구현

//정적 할당의 장점
//1. 동적 할당을 하는 오버헤드가 없어짐
//2. 사용이 끝날 때마다(특히 여러 개의 테스트 케이스가 있는 경우) 메모리를 해제할 필요가 없음
//3. 모든 노드가 메모리 상에서 뭉쳐 있기 때문에 캐시 효율이 높아짐

#include <iostream>
#include <string>
#include <array>
#define MAX_NODE 10000

using namespace std;

//Binary Search Tree Node
struct Node{
    int key;
    Node *left, *right;
};

//정적 할당(메모리 풀) 방식
Node node_pool[MAX_NODE];
Node* root;
int node_cnt;

Node* new_node(int x){
    node_pool[node_cnt].key = x;
    node_pool[node_cnt].left = nullptr;
    node_pool[node_cnt].right = nullptr;
    return &node_pool[node_cnt++];
}

//초기화
void init(){
    node_cnt = 0;
    root = nullptr;
}

//노드 추가
Node* insert_rec(Node* node, int x){
    if(node == nullptr){
        return new_node(x);
    }

    if(x < node->key){
        node->left = insert_rec(node->left, x);
    }
    else if(x > node->key){
        node->right = insert_rec(node->right, x);
    }    
    return node;
}
void insert(int x){
    root = insert_rec(root, x);
}

//최솟값 찾기
int find_min_key(Node* node){
    while(node->left != nullptr){
        node = node->left;
    }
    return node->key;
}

//노드 삭제
Node* remove_rec(Node* node, int x){
    if(node == nullptr){
        return node;
    }

    if(x < node->key){
        node->left = remove_rec(node->left, x);
    }
    else if(x > node->key){
        node->right = remove_rec(node->right, x);
    }
    else{
        if(node->left == nullptr){
            return node->right;
        }
        else if(node->right == nullptr){
            return node->left;
        }
        const int tmp = find_min_key(node->right);
        node->key = tmp;
        node->right = remove_rec(node->right, tmp);
    }
    return node;
}
void remove(int x){
    root = remove_rec(root, x);
}

//데이터 찾기
bool find(int x){
    Node* node = root;
    while(node != nullptr){
        if(node->key == x) return true;
        node = x < node->key ? node->left : node->right;
    }
    return false;
}

//트리 순회(0 : 전위, 1 : 중위, 2 : 후위)
void traversal_rec(Node* node, int type){
    if(node == nullptr) return;
    if(type == 0) cout << node->key << ' ';
    traversal_rec(node->left, type);
    if(type == 1) cout << node->key << ' ';
    traversal_rec(node->right, type);
    if(type == 2) cout << node->key << ' ';
}
void traversal(int type){
    static constexpr array<const char*, 3> traversal_types = {"pre", "in", "post"};
    cout << traversal_types[type] << "-order  ";
    traversal_rec(root, type);
    cout << '\n';
}

int main() {
	//0 : 트리 초기화
	//1 : 트리에 노드 삽입
	//2 : 트리에 노드 삭제
	//3 : 트리 탐색
	//4 : 트리 순회(0 : 전위, 1 : 중위, 2 : 후위)
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
			if (x < 0 || x > 2) return cout << "invalid traversal type\n", 0;
			traversal(x);
			break;

        case 99:
            return 0;
		}
	}
}