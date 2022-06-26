#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
BTNode* Test1()
{
	BTNode* node1 = CreateBTNode(1);
	BTNode* node2 = CreateBTNode(2);
	BTNode* node3 = CreateBTNode(3);
	BTNode* node4 = CreateBTNode(4);
	BTNode* node5 = CreateBTNode(5);
	BTNode* node6 = CreateBTNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

int main()
{
	BTNode* node = Test1();

	BinaryTreePrevOrder(node);
	printf("\n");
	BinaryTreeInOrder(node);
	printf("\n");
	BinaryTreePostOrder(node);
	printf("\n");

	int size = BinaryTreeSize(node);
	printf("%d\n", size);

	printf("%d\n", BinaryTreeLeafSize(node));

	printf("%d\n", BinaryTreeLevelKSize(node,2));
	BinaryTreeFind(node, 1);

	return 0;
}