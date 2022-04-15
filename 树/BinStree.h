#pragma once
#pragma once
#include<iostream>
using namespace std;
typedef struct tree* Binstree;
struct tree
{
	int data;
	Binstree left;
	Binstree right;
};

void InorderTraveral(Binstree BST)//中序遍历
{
	if (BST)
	{
		InorderTraveral(BST->left);
		cout << BST->data << " ";
		InorderTraveral(BST->right);
	}

}

void PreorderTraveral(Binstree BST)//先序遍历
{
	//cout << "gan";
	if (BST)
	{
		//cout << "gan";
		cout << BST->data << " ";
		PreorderTraveral(BST->left);
		PreorderTraveral(BST->right);
	}

}

void PostorderTraveral(Binstree BST)//后序遍历
{
	if (BST)
	{
		PostorderTraveral(BST->left);
		PostorderTraveral(BST->right);
		cout << BST->data << " ";
	}

}

Binstree FindMax(Binstree BST)//非递归查找最大值
{
	if (BST)
	{
		while (BST->right) BST = BST->right;
	}
	return BST;
}

Binstree FindMin(Binstree BST)//非递归查到最小值
{
	if (BST)
	{
		while (BST->left) BST = BST->left;
	}
	return BST;
}

Binstree DFindMax(Binstree BST)//递归查找最大值
{
	if (!BST) return NULL;
	else if (!BST->right) return BST;
	else return DFindMax(BST->right);
}

Binstree DFind(Binstree BST, int k)//递归查找
{
	if (BST)
	{
		if (k > BST->data) return DFind(BST->right, k);
		else if (k < BST->data) return DFind(BST->left, k);
		else return BST;
	}
	else return NULL;
}

Binstree Find(Binstree BST, int k)//非递归查找
{
	while (BST)
	{
		if (k > BST->data) BST = BST->right;
		else if (k < BST->data) BST = BST->left;
		else if (k == BST->data) return BST;
	}
	return NULL;
}


Binstree Deletetree(Binstree BST, int k)
{
	if (BST)
	{
		if (BST->data > k) return Deletetree(BST->left,k);
		else if (BST->data < k) return Deletetree(BST->right,k);
		else
		{
			if (BST->left && BST->right)
			{
				Binstree tem = FindMax(BST->left);
				BST->data = tem->data;
				BST->left = Deletetree(BST->right, tem->data);
			}
			else
			{
				if (BST->left) BST = BST->left;
				else if (BST->right) BST = BST->right;
				else BST = NULL;
			}	
		}
	}
	else
	{
		cout << "没找到";
	}
	return BST;
}