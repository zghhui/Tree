#include<iostream>
#include<cstdlib>
#include"Binstree.h"
using namespace std;

Binstree InsertBinstree(Binstree BST,int x)
{
	if (!BST)
	{
		BST = (Binstree)malloc(sizeof(tree));
		BST->data = x;
		BST->left = BST->right = NULL;
	}
	else
	{
		if (x > BST->data)
		{
			BST->right=InsertBinstree(BST->right, x);
		}
		else if(x < BST->data)
		{
			BST->left=InsertBinstree(BST->left, x);
		}
		//相等不做处理
	}
	return BST;
}

Binstree BST,T;

int main()
{
	for (int i = 1; i <= 7; i++)//输入四个
	{
		int tem;
		cin >> tem;
		BST=InsertBinstree(BST, tem);
	}

	//先序遍历
	PreorderTraveral(BST);
	cout << endl;

	//查找最大值
	T = DFindMax(BST);
	cout << T->data;
	cout << endl;

	//查找
	if (Find(BST, 10)) cout << "yes" << endl;
	else cout << "no" << endl;

	//删除
	if (Deletetree(BST, 2))   cout << "成功"<<endl;
	PreorderTraveral(BST);
}