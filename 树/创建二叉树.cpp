#include<iostream>
#include<cstdlib>
#include<queue>
#include"Bintree.h"
using namespace std;
Bintree CreatBintree()
{
	queue<Bintree> q;
	int temdata;
	Bintree BT,T;

	cin >> temdata;
	if (temdata)//用0来标记有没有值 有则建立一个结点
	{
		BT = (Bintree)malloc(sizeof(tree));
		BT->data = temdata;
		BT->left = BT->right = NULL;
		q.push(BT);
	}
	else return NULL;
	while (!q.empty())
	{
		T = q.front();
		q.pop();
		cin >> temdata;
		if (temdata)
		{
			T->left = (Bintree)malloc(sizeof(tree));
			T->left->data = temdata;
			T->left->left = T->left->right = NULL;
			q.push(T->left);
		}
		else T->left = NULL;
		cin >> temdata;
		if (temdata)
		{
			T->right = (Bintree)malloc(sizeof(tree));
			T->right->data = temdata;
			T->right->left = T->right->right = NULL;
			q.push(T->right);
		}
		else T->right = NULL;

	}
	return BT;
}
int main()
{
	Bintree BST;
	BST=CreatBintree();
	InorderTraveral(BST);
	cout << endl;
	PreorderTraveral(BST);
	cout << endl;
	return 0;
}