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
		//��Ȳ�������
	}
	return BST;
}

Binstree BST,T;

int main()
{
	for (int i = 1; i <= 7; i++)//�����ĸ�
	{
		int tem;
		cin >> tem;
		BST=InsertBinstree(BST, tem);
	}

	//�������
	PreorderTraveral(BST);
	cout << endl;

	//�������ֵ
	T = DFindMax(BST);
	cout << T->data;
	cout << endl;

	//����
	if (Find(BST, 10)) cout << "yes" << endl;
	else cout << "no" << endl;

	//ɾ��
	if (Deletetree(BST, 2))   cout << "�ɹ�"<<endl;
	PreorderTraveral(BST);
}