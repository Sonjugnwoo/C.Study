// ���� 4 ,   ���� ��� ����� 
#include<stdio.h>
#include<stdlib.h>

//����ü ����
typedef struct Node
{
	int data;
	struct Node* nextnode; /* ���� ��带 ����Ű�� �κ� */
	struct Node* prevnode; /* ���� ��带 ����Ű�� �κ� */
}node;

struct Node* CreateNode(int data);	//��� ����
struct Node* InsertNode(node* current, int data);	//��� ����

void DestroyNode(node* destroy, node* head);	//��� ����
void PrintNodeFrom(node* from);	// ���
void AllFreeNode(node* head);	//��ü �޸� ����
int SearchNode(node* head, node* search);	//��� �˻� 
int CountNode(struct Node* head);	//��� ���� 


int main()
{
	// ��� ����� �� ���� 
	node* Node1 = CreateNode(100);
	node* Node2 = InsertNode(Node1, 200);
	node* Node3 = InsertNode(Node2, 300);
	node* Node4 = InsertNode(Node3, 400);

	printf("%d��\n", CountNode(Node2));	//��� �� ���

	PrintNodeFrom(Node1);	//���� �ִ� ��� ���
	printf("ã�� ����� �� : %d", SearchNode(Node1, Node3));

	return 0;
}

// ��� ���� �Լ�
node* CreateNode(int data)
{
	node* new_node = (node*)malloc(sizeof(node));	//���ο� ��忡 �����Ҵ�

	new_node->data = data;	//��忡 �Է°� �ֱ�
	new_node->nextnode = new_node;	// NULL�� �ʱ�ȭ (���� ���� ����)
	new_node->prevnode = new_node;
	return new_node;
}

// ��� ���� �Լ� 
node* InsertNode(node* current, int data)
{
	node* after = current->nextnode;	// ���� ����� ���� ��带 ����Ű�� ������
	node* new_node = (node*)malloc(sizeof(node));	// ���ο� ��� ���� 

	new_node->data = data;	//��忡 �Է°� �ֱ�
	new_node->nextnode = after;	// �� ����� ���� ��带 ������ ���� ���(after)�� ����
	new_node->prevnode = current;	// �� ����� ���� ��带 ����(current)�� ����

	current->nextnode = new_node;	// ���� ����� ������ �� ���� ����
	after->prevnode = new_node;
	return new_node;
}

// ��� ���� �Լ� 
void DestroyNode(node* destroy, node* head)
{
	node* next = head;	// ����Ʈ�� ���� ��带 ����Ű�� ������

   //���� ������ ���� �ؾ��� ���̶� ������ �ٷ� ���� 
	if (head == destroy)
	{
		free(destroy);	//������ ��� �޸� ����
		return;
	}
	destroy->nextnode->prevnode = destroy->prevnode;	// ���� ���(next)�� ������ ����� ���� ���� ����ǵ��� ������ �缳��
	destroy->prevnode->nextnode = destroy->nextnode;	//������ ����� ���� ���� ������ ����� ���� ��带 ���� 
	
	free(destroy);	//������ ��� �޸� ����
}

// ��� �Լ�
void PrintNodeFrom(struct Node* from)
{
	if (from == NULL)	return ;	//from NULL �Ͻ� �ٷ� ����
	node* current = from;
	
	//���� ����Ʈ�� ������ ��� ��� �ѹ��� ����� ���� 
	do 
	{
		printf("����� ������ : %d \n", current->data);
		current = current->nextnode;
	} while (current != from);
}

// ��ü �޸� ���� �Լ� 
void AllFreeNode(node* head)
{
	if (head == NULL) return;	//�� ����Ʈ�� �ٷ� ����

	node* current = head->nextnode;
	while (current != head)		//�ٽ� head�� ���ƿ� ������ �ݺ�
	{
		node* next = current->nextnode;	 // ���� ��� �ּ� �̸� ����
		free(current);
		current = next;
	}
	free(head);
}

// ��� �˻� �Լ� 
int SearchNode(node* head, node* search)
{
	if (head == NULL || search == NULL) return -1; //����Ʈ�� �˻� ��尡 NULL�̸� -1 ��ȯ

	node* current = head;

	do {
		//�� ����� �����Ͱ��� ������ �� ������ ��� 
		if (current->data == search->data)
			return current->data;

		current = current->nextnode;
	} while (current != head); //�� ���� ��ȸ�� ������ �ݺ�

	return -1; // ã�� ���ϸ� -1 ��ȯ
}

// ��� ���� �Լ�
int CountNode(node* head)
{
	if (head == NULL) return 0;

	node* temp = head->nextnode;
	int count = 1;
	//head�� NULL�� �ɋ����� count ���� 
	while (temp!=head)
	{
		//�����̱� ������ �Ӹ� �� ���ƿ��� �Լ� ����
		count++;
		temp = temp->nextnode;	// ���� ��带 ����Ű�� ����
	}
	return count;
}