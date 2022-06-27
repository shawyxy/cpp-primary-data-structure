#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
#include "Queue.h"
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* str, int* pi)
{
	if (str[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}

	BTNode* root = CreateBTNode(str[(*pi)++]);
	root->left = BinaryTreeCreate(str, pi);
	root->right = BinaryTreeCreate(str, pi);
	return root;
}
// ����������
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	/*if (root == NULL)
		return 0;
	return   BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;*/
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k >= 1);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1) + 1;
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
	{
		printf("%d\n", root->data);
		return root;

	}
	BinaryTreeFind(root->left, x);
	BinaryTreeFind(root->right, x);
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	printf("%d ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%d ", root->data);
	BinaryTreeInOrder(root->right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%d ", root->data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	//��������ʼ������
	Queue q;
	QueueInit(&q);
	//�Ѹ�������
	if (root)
	{
		QueuePush(&q, root);
	}
	//ÿ��ֻȡ��ͷԪ��(��ǰ�ĸ����),
	//Ȼ�󽫵�ǰ�����ķǿպ��ӽ�����
	//��ֹ����:�ӿ�
	while (!QueueEmpty(&q))
	{
		//ȡ��ͷԪ�غ�pop
		BTNode* front = QueueFront(&q);
		printf("%d ", front->data);
		QueuePop(&q);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	QueueDestory(&q);
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
	{
		QueuePush(&q, root);
	}
	//�������
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		//�����ս����ͣ
		else
		{
			break;
		}
	}
	//�ж�ʣ�µĿս���Ƿ���������
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueueDestory(&q);
			printf("no\n");
			return false;
		}
	}
	QueueDestory(&q);
	printf("yes\n");
	return true;
}
//�������
BTNode* CreateBTNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}