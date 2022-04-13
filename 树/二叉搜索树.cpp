#include<iostream>
using namespace std;
typedef struct tree* BinStree;
struct tree {
	int data;
	BinStree left;
	BinStree right;
};

BinStree InsertBinStree(BinStree BST, int x)
{
	if (!BST)
	{
		BST = (BinStree)malloc(sizeof(tree));
		BST->data = x;
		BST->left = BST->right = NULL;
	}
	else
	{
		if (BST->data > x)
		{
			BST = InsertBinStree(BST->left, x);
		}
		else if (BST->data < x)
		{
			BST = InsertBinStree(BST->right, x);
		}
		
		
	}
	return BST;
}
/*BinStree InsertBinStree(BinStree BST, int x)
{
	if (!BST)
	{
		BST = (BinStree)malloc(sizeof(tree));
		BST->data = x;
		BST->left = BST->right = NULL;
	}
	else
	{
		if (BST->data < x)
		{
			 BST->right= InsertBinStree(BST->right,x);
		}
		else if (BST->data > x)
		{
			BST->left= InsertBinStree(BST->left,x);
		}
		
		//���ʱ��������
	}
	return BST;
}*/

BinStree FindTree(BinStree BST,int x)//�ݹ����
{
	if (!BST)
	{
		cout << "ֵ������" << endl;
	}
	else
	{
		if (BST->data < x)
		{
			return FindTree(BST->right, x);
		}
		else if (BST->data > x)
		{
			return  FindTree(BST->left, x);
		}
		else return BST;
	}
}

BinStree FindBinStree(BinStree BST, int x)
{
	
	while (BST)
	{
		if (BST->data > x) BST = BST->left;
		else if (BST->data < x) BST = BST->right;
		else break;
	}
	if (!BST) cout << "ֵ������";
	return BST;
}

BinStree FindMaxStree(BinStree BST)
{
	if (BST)
	{
		while (BST->right) BST = BST->right;
		return BST;
	}
	
}
BinStree DeleteBinStree(BinStree BST, int x)
{
	if (BST->data > x)
	{
		BST->left = DeleteBinStree(BST->left, x);
	}
	else if (BST->data < x)
	{
		BST->right= DeleteBinStree(BST->right, x);
	}
	else
	{
		if (BST->left && BST->right)
		{
			BinStree tem = FindMaxStree(BST->left);
			BST->data = tem->data;
			BST->left = DeleteBinStree(BST->left, BST->data);
		}
		else
		{
			BinStree tem = BST;
			if (BST->right) BST = BST->right;
			else if (BST->left) BST = BST->left;
			free(tem);
		}
		
	}
	return BST;
}

void preorder(BinStree p)//�������
{
	if (p)
	{
		//cout<<" ���� ";
		preorder(p->left);
		cout << p->data << " ";
		preorder(p->right);
	}
}

BinStree tt,temm,deltem;
int main()
{
	int tem;
	for (int i = 1; i <= 5; i++)
	{
		cin >> tem;
		tt = InsertBinStree(tt, tem);
	}
	preorder(tt);
	//temm = FindBinStree(tt, 0);
	cout << endl;
	deltem = DeleteBinStree(tt, 4);
	preorder(deltem);
}