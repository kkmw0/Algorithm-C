//문자열 hash함수 djb2를 이용하여 hash구현
//djb2는 간략하면서도 무작위 분포를 만드는데 뛰어남
//magic number 5381과 33을 활용하여 hash key를 생성

//테이블의 크기로 소수를 사용 할 경우, 충돌이 적지만 느린 % 연산자를 사용해야 됨
//해시 함수가 무작위에 가까운 값들을 출력해준다면 테이블의 크기가 소수인지는 별로 중요하지 않지만,
//출력 값이 고르지 않다면, 테이블의 크기가 s이고 해시 함수가 x의 배수만 출력한다면, 실질적인 테이블의 크기는 s / gcd(s, x)와 같아짐

//테이블의 크기로 2의 거듭제곱을 활용 할 경우, bit masking을 통해 나머지를 빠르게 계산을 할 수 있지만,
//m개의 하위 bit를 그대로 사용하기 때문에 hash function이 하위 bit을 고르게 분포 시키지 못한다면 많은 충돌이 발생함
//흔히 사용하는 소수 10007, 20011, 30011, 40009, 100003, 200003

#include <iostream>
#include <cstring>

using namespace std;

size_t djb2(const char* str){
    size_t hash = 5381;
    for(; *str; ++str){
        hash = ((hash << 5) + hash) + *str;
    }
    return hash;
}

constexpr size_t MAX_N = 10000;
constexpr size_t MAX_LEN = 10;

struct Node{
    char str[MAX_LEN + 1];
    int data;
    Node* next;
};

int node_cnt = 0;
Node nodes[MAX_N];

Node* new_node(const char str[MAX_LEN + 1], int data){
    strcpy(nodes[node_cnt].str, str);
    nodes[node_cnt].data = data;
    nodes[node_cnt].next = nullptr;
    return &nodes[node_cnt++];
}

static constexpr size_t TABLE_SIZE = 1 << 12;
static constexpr size_t DIV = TABLE_SIZE - 1;
Node hash_table[TABLE_SIZE];

void init(){
    node_cnt = 0;
    memset(hash_table, 0, sizeof(hash_table));
}

Node* get_prev_node(const char str[MAX_LEN + 1]){
    Node* prev_ptr = &hash_table[djb2(str) & DIV];
    while(prev_ptr->next != nullptr && strcmp(prev_ptr->next->str, str) != 0){
        prev_ptr = prev_ptr->next;
    }
    return prev_ptr;
}

void insert(const char str[MAX_LEN + 1], int data){
    Node* const prev_node = get_prev_node(str);
    if(prev_node->next == nullptr){
        prev_node->next = new_node(str, data);
    }
    else{
        prev_node->next->data = data;
    }
}

void _remove(const char str[MAX_LEN + 1]){
    Node* const prev_node = get_prev_node(str);
    if(prev_node->next != nullptr){
        prev_node->next = prev_node->next->next;
    }
}

Node* get(const char str[MAX_LEN + 1]){
    return get_prev_node(str)->next;
}

int main() {
	//0 : 초기화
	//1 : (str, x) 삽입 (이미 str이 있는 경우 data를 x로 교체)
	//2 : str 삭제 (str이 없는 경우 무시)
	//3 : str 검색
    //99 : 종료
    init();

	int cmd, x;
	char str[MAX_LEN + 1];
	Node* ptr;
	for (;;) {
		cin >> cmd;
		switch (cmd) {
		case 0:
			init();
			break;

		case 1:
			cin >> str >> x;
			if(strlen(str) > MAX_LEN) return cout << "invalid key length", 0;
			insert(str, x);
			break;

		case 2:
			cin >> str;
			if(strlen(str) > MAX_LEN) return cout << "invalid key length", 0;
			_remove(str);
			break;

		case 3:
			cin >> str;
			if (strlen(str) > MAX_LEN) return cout << "invalid key length", 0;
			ptr = get(str);
			if (ptr == nullptr) cout << "not found\n";
			else cout << str << ": " << ptr->data << '\n';
			break;

        case 99:
            return 0;
		}
	}
} 