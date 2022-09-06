//알파벳 소문자로만 이루어진 문자열을 관리하는 트라이
//트라이의 공간 복잡도는 O(삽입된 문자열의 총 길이)
//문자열의 삽입/삭제/탐색은 언제나 O(문자열의 길이)

//간선을 저장하는 방법
//1. std::map에 사용하는 간선만큼의 데이터만 저장하는 방법
//2. 사용되는 문자 종류의 개수만큼 간선을 만들어서 배열에 저장하는 방법
//첫 번째 방법은 불필요한 간선을 만들지 않지만 std::map 자체가 많이 무거움
//사용되는 문자의 종류가 적다면 두 번째 방법이 더 효과적

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

static constexpr int M = 26;
static constexpr char OFFSET = 'a';

struct TrieNode{
    int child[M];
    bool is_Terminal; //문자열의 끝을 표시하는 Boolean 변수
                      //True / False 대신 개수를 표기하여 원소의 중복을 허용하는 트라이를 만들 수도 있음
    
    TrieNode(){
        is_Terminal = false;
        memset(child, -1, sizeof(int) * M);
    }
};

vector<TrieNode> nodes;

//초기화
void init(){
    nodes.resize(1);
    nodes[0] = TrieNode();
}

//문자열 삽입
void insert(const string& str){
    int node_id = 0;
    for(const auto& c : str){
        int word = c - OFFSET;
        if(nodes[node_id].child[word] == -1){
            nodes[node_id].child[word] = nodes.size();
            nodes.emplace_back();
        }
        node_id = nodes[node_id].child[word];
    }
    nodes[node_id].is_Terminal = true;
}

//문자열 삭제
void remove(const string& str){
    int node_id = 0;
    for(const auto& c : str){
        int word = c - OFFSET;
        if(nodes[node_id].child[word] == -1){
            return;
        }
        node_id = nodes[node_id].child[word];
    }
    nodes[node_id].is_Terminal = false;
}

//문자열 탐색
bool find(const string& str){
    int node_id = 0;
    for(const auto& c : str){
        int word = c - OFFSET;
        if(nodes[node_id].child[word] == -1){
            return false;
        }
        node_id = nodes[node_id].child[word];
    }
    return nodes[node_id].is_Terminal;
}

int main() {
	//0 : 트라이 초기화
	//1 : 문자열 삽입
	//2 : 문자열 삭제
	//3 : 문자열 탐색
    //99 : 종료
    init();

	int cmd;
    string str;
	for (;;) {
		cin >> cmd;
		switch (cmd) {
		case 0:
			init();
			break;

		case 1:
			cin >> str;
			insert(str);
			break;

		case 2:
			cin >> str;
			remove(str);
			break;

		case 3:
			cin >> str;
			cout << (find(str) ? "found" : "not found") << '\n';
			break;

        case 99:
            return 0;
		}
	}
}