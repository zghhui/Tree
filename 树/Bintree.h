#pragma once
#include<iostream>
using namespace std;
typedef struct tree* Bintree;
struct tree
{
	int data;
	Bintree left;
	Bintree right;
};

bool f(Bintree BT)
{
	if (!BT) return true;
	else
	{
		if (BT->left)
		{
			if (BT->data <= BT->left->data) return false;
			else f(BT->left);
		}
		if (BT->right)
		{
			if (BT->data >= BT->right->data) return false;
			else f(BT->right);
		}
	}
}

void InorderTraveral(Bintree BST)//�������
{
	if (BST)
	{
		InorderTraveral(BST->left);
		cout << BST->data << " ";
		InorderTraveral(BST->right);
	}

}



void PreorderTraveral(Bintree BST)//�������
{
	if (BST)
	{
		cout << BST->data << " ";
		PreorderTraveral(BST->left);
		PreorderTraveral(BST->right);
	}

}

void PreorderTraveral(Bintree BST,int k)//�������
{
	int tem = 0;
	if (BST)
	{
		//cout << BST->data << " ";
		tem++;
		if (tem == k) cout << BST->data;
		PreorderTraveral(BST->left);
		PreorderTraveral(BST->right);
	}

}

void PostorderTraveral(Bintree BST)//�������
{
	if (BST)
	{
		PostorderTraveral(BST->left);
		PostorderTraveral(BST->right);
		cout << BST->data << " ";
	}

}

