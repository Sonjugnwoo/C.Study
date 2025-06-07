// 문제 2 , 원하는 노드의 데이터 값을 출력하는 int SearchNode(Node*head, Node* search) 함수

#include<stdio.h>
#include<stdlib.h>

//구조체 정의
typedef struct Node {
	int data;
	struct Node* nextnode;
}node;

//함수 원형
struct Node* CreateNode(int data);	//노드 생성
struct Node* InsertNode(node* current, int data);	//노드 삽입

void DestroyNode( node* destroy, node* head);	//노드 삭제
void PrintNodeFrom( node* from);	// 출력
void AllFreeNode( node* head);	//전체 메모리 삭제
int SearchNode(node* head, node* search);	//노드 검색 

int main()
{
	// 노드 만들기 및 삽입 
	node* Node1 = CreateNode(100);
	node* Node2 = InsertNode(Node1, 200);
	node* Node3 = InsertNode(Node2, 300);
	node* Node4 = InsertNode(Node3, 400);

	printf("%d",SearchNode(Node1, Node3));
	AllFreeNode(Node1);
	return 0;
}

// 노드 생성 함수
node* CreateNode(int data)
{
	node* new_node = (struct Node*)malloc(sizeof(struct Node));	//새로운 노드에 동적할당

	new_node->data = data;	//노드에 입력값 넣기
	new_node->nextnode = NULL;	// NULL로 초기화 (다음 값은 없다)

	return new_node;
}

// 노드 삽입 함수 
node* InsertNode(node * current, int data)
{
	node* after = current->nextnode;// 현재 노드의 다음 노드를 가리키는 포인터

	node* new_node = (struct Node*)malloc(sizeof(struct Node));	// 새로운 노드 생성 

	new_node->data = data;	//노드에 입력값 넣기
	new_node->nextnode = after;	// 새 노드의 다음 노드를 기존의 다음 노드(after)로 연결

	current->nextnode = new_node;	// 현재 노드의 다음을 새 노드로 연결

	return new_node;
}

// 노드 삭제 함수 
void DestroyNode(node* destroy,  node* head)
{
	 node* next = head;	// 리스트의 시작 노드를 가리키는 포인터

	//시작 지점이 삭제 해야할 값이랑 같으면 바로 종료 
	if (head == destroy)
	{
		free(destroy);	//삭제할 노드 메모리 해제
		return;
	}
	// 리스트 전체를 순회하여 삭제할 노드의 이전 노드를 찾음
	while (next)
	{
		if (destroy == next->nextnode)
		{
			next->nextnode = destroy->nextnode;	// 이전 노드(next)가 삭제할 노드의 다음 노드와 연결되도록 포인터 재설정
		}
		next = next->nextnode;
	}
	free(destroy);	//삭제할 노드 메모리 해제
}

// 출력 함수
void PrintNodeFrom(struct Node* from)
{
	//리스트 전체 순회 하며 NULL전까지 출력
	while (from)
	{
		printf("노드의 데이터 : %d \n", from->data);
		from = from->nextnode;
	}
}

// 전체 메모리 해제 함수 
void AllFreeNode(node* head)
{
	node* next;	//다음 노드 주소 저장할 변수 
	while (head)
	{
		next = head->nextnode;	//다음 노드 주소 미리 저장
		free(head);	//현재 노드 메모리 해제
		head = next;
	}
}

// 노드 검색 함수 
int SearchNode(node* head, node* search)
{
	//리스트 전체 순회
	while (head)
	{
		//두 노드의 데이터값이 같을때 그 데이터 출력 
		if (head->data == search->data)
		{
			return head->data;
		}
		head = head->nextnode;
	}
	return -1;	//찾지 못할시 -1 반환
}