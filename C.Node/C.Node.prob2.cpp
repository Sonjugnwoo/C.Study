// ���� 2 , ���ϴ� ����� ������ ���� ����ϴ� int SearchNode(Node*head, Node* search) �Լ�

#include<stdio.h>
#include<stdlib.h>

//����ü ����
typedef struct Node {
	int data;
	struct Node* nextnode;
}node;

//�Լ� ����
struct Node* CreateNode(int data);	//��� ����
struct Node* InsertNode(node* current, int data);	//��� ����

void DestroyNode( node* destroy, node* head);	//��� ����
void PrintNodeFrom( node* from);	// ���
void AllFreeNode( node* head);	//��ü �޸� ����
int SearchNode(node* head, node* search);	//��� �˻� 

int main()
{
	// ��� ����� �� ���� 
	node* Node1 = CreateNode(100);
	node* Node2 = InsertNode(Node1, 200);
	node* Node3 = InsertNode(Node2, 300);
	node* Node4 = InsertNode(Node3, 400);

	printf("%d",SearchNode(Node1, Node3));
	AllFreeNode(Node1);
	return 0;
}

// ��� ���� �Լ�
node* CreateNode(int data)
{
	node* new_node = (struct Node*)malloc(sizeof(struct Node));	//���ο� ��忡 �����Ҵ�

	new_node->data = data;	//��忡 �Է°� �ֱ�
	new_node->nextnode = NULL;	// NULL�� �ʱ�ȭ (���� ���� ����)

	return new_node;
}

// ��� ���� �Լ� 
node* InsertNode(node * current, int data)
{
	node* after = current->nextnode;// ���� ����� ���� ��带 ����Ű�� ������

	node* new_node = (struct Node*)malloc(sizeof(struct Node));	// ���ο� ��� ���� 

	new_node->data = data;	//��忡 �Է°� �ֱ�
	new_node->nextnode = after;	// �� ����� ���� ��带 ������ ���� ���(after)�� ����

	current->nextnode = new_node;	// ���� ����� ������ �� ���� ����

	return new_node;
}

// ��� ���� �Լ� 
void DestroyNode(node* destroy,  node* head)
{
	 node* next = head;	// ����Ʈ�� ���� ��带 ����Ű�� ������

	//���� ������ ���� �ؾ��� ���̶� ������ �ٷ� ���� 
	if (head == destroy)
	{
		free(destroy);	//������ ��� �޸� ����
		return;
	}
	// ����Ʈ ��ü�� ��ȸ�Ͽ� ������ ����� ���� ��带 ã��
	while (next)
	{
		if (destroy == next->nextnode)
		{
			next->nextnode = destroy->nextnode;	// ���� ���(next)�� ������ ����� ���� ���� ����ǵ��� ������ �缳��
		}
		next = next->nextnode;
	}
	free(destroy);	//������ ��� �޸� ����
}

// ��� �Լ�
void PrintNodeFrom(struct Node* from)
{
	//����Ʈ ��ü ��ȸ �ϸ� NULL������ ���
	while (from)
	{
		printf("����� ������ : %d \n", from->data);
		from = from->nextnode;
	}
}

// ��ü �޸� ���� �Լ� 
void AllFreeNode(node* head)
{
	node* next;	//���� ��� �ּ� ������ ���� 
	while (head)
	{
		next = head->nextnode;	//���� ��� �ּ� �̸� ����
		free(head);	//���� ��� �޸� ����
		head = next;
	}
}

// ��� �˻� �Լ� 
int SearchNode(node* head, node* search)
{
	//����Ʈ ��ü ��ȸ
	while (head)
	{
		//�� ����� �����Ͱ��� ������ �� ������ ��� 
		if (head->data == search->data)
		{
			return head->data;
		}
		head = head->nextnode;
	}
	return -1;	//ã�� ���ҽ� -1 ��ȯ
}