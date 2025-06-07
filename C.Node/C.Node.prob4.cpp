// 문제 4 ,   원형 노드 만들기 
#include<stdio.h>
#include<stdlib.h>

//구조체 정의
typedef struct Node
{
	int data;
	struct Node* nextnode; /* 다음 노드를 가리키는 부분 */
	struct Node* prevnode; /* 이전 노드를 가리키는 부분 */
}node;

struct Node* CreateNode(int data);	//노드 생성
struct Node* InsertNode(node* current, int data);	//노드 삽입

void DestroyNode(node* destroy, node* head);	//노드 삭제
void PrintNodeFrom(node* from);	// 출력
void AllFreeNode(node* head);	//전체 메모리 삭제
int SearchNode(node* head, node* search);	//노드 검색 
int CountNode(struct Node* head);	//노드 개수 


int main()
{
	// 노드 만들기 및 삽입 
	node* Node1 = CreateNode(100);
	node* Node2 = InsertNode(Node1, 200);
	node* Node3 = InsertNode(Node2, 300);
	node* Node4 = InsertNode(Node3, 400);

	printf("%d개\n", CountNode(Node2));	//노드 수 출력

	PrintNodeFrom(Node1);	//남아 있는 노드 출력
	printf("찾는 노드의 값 : %d", SearchNode(Node1, Node3));

	return 0;
}

// 노드 생성 함수
node* CreateNode(int data)
{
	node* new_node = (node*)malloc(sizeof(node));	//새로운 노드에 동적할당

	new_node->data = data;	//노드에 입력값 넣기
	new_node->nextnode = new_node;	// NULL로 초기화 (다음 값은 없다)
	new_node->prevnode = new_node;
	return new_node;
}

// 노드 삽입 함수 
node* InsertNode(node* current, int data)
{
	node* after = current->nextnode;	// 현재 노드의 다음 노드를 가리키는 포인터
	node* new_node = (node*)malloc(sizeof(node));	// 새로운 노드 생성 

	new_node->data = data;	//노드에 입력값 넣기
	new_node->nextnode = after;	// 새 노드의 다음 노드를 기존의 다음 노드(after)로 연결
	new_node->prevnode = current;	// 새 노드의 이전 노드를 현재(current)로 연결

	current->nextnode = new_node;	// 현재 노드의 다음을 새 노드로 연결
	after->prevnode = new_node;
	return new_node;
}

// 노드 삭제 함수 
void DestroyNode(node* destroy, node* head)
{
	node* next = head;	// 리스트의 시작 노드를 가리키는 포인터

   //시작 지점이 삭제 해야할 값이랑 같으면 바로 종료 
	if (head == destroy)
	{
		free(destroy);	//삭제할 노드 메모리 해제
		return;
	}
	destroy->nextnode->prevnode = destroy->prevnode;	// 이전 노드(next)가 삭제할 노드의 다음 노드와 연결되도록 포인터 재설정
	destroy->prevnode->nextnode = destroy->nextnode;	//삭제할 노드의 다음 노드와 삭제할 노드의 이전 노드를 연결 
	
	free(destroy);	//삭제할 노드 메모리 해제
}

// 출력 함수
void PrintNodeFrom(struct Node* from)
{
	if (from == NULL)	return ;	//from NULL 일시 바로 종료
	node* current = from;
	
	//원형 리스트기 때문에 모든 노드 한번씩 출력후 종료 
	do 
	{
		printf("노드의 데이터 : %d \n", current->data);
		current = current->nextnode;
	} while (current != from);
}

// 전체 메모리 해제 함수 
void AllFreeNode(node* head)
{
	if (head == NULL) return;	//빈 리스트면 바로 종료

	node* current = head->nextnode;
	while (current != head)		//다시 head로 돌아올 때까지 반복
	{
		node* next = current->nextnode;	 // 다음 노드 주소 미리 저장
		free(current);
		current = next;
	}
	free(head);
}

// 노드 검색 함수 
int SearchNode(node* head, node* search)
{
	if (head == NULL || search == NULL) return -1; //리스트나 검색 노드가 NULL이면 -1 반환

	node* current = head;

	do {
		//두 노드의 데이터값이 같을때 그 데이터 출력 
		if (current->data == search->data)
			return current->data;

		current = current->nextnode;
	} while (current != head); //한 바퀴 순회할 때까지 반복

	return -1; // 찾지 못하면 -1 반환
}

// 노드 개수 함수
int CountNode(node* head)
{
	if (head == NULL) return 0;

	node* temp = head->nextnode;
	int count = 1;
	//head가 NULL이 될떄까지 count 증가 
	while (temp!=head)
	{
		//원형이기 때문에 머리 로 돌아오면 함수 종료
		count++;
		temp = temp->nextnode;	// 다음 노드를 가르키게 설정
	}
	return count;
}