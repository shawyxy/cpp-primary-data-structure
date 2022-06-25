#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
////ºóÐò±éÀú
//void Order(NTNODE* root)
//{
//	if (root == NULL)
//	{
//		printf("# ");
//		return;
//	}
//	Order(root->left);
//	Order(root->right);
//	printf("%d ", root->data);
//
//}

//
//if (left == NULL)
//{
//	return 0;
//}
//if (leaf->left == NULL && leaf->right == NULL)
//{
//	return 1;
//}
//return f(leaf->left) + f(leaf->right);

//BTNODE* Find(BTNODE* root, int k)
//{
//	if (root == NULL)
//	{
//		return NULL;
//	}
//	if (root->data == k)
//	{
//		return root;
//	}
//	BTNODE* ret1 = Find(root->right);
//	BTNODE* ret2 = Find(root->left);
//	if (ret1)
//		return 1;
//	return ret2;
//
//
//}