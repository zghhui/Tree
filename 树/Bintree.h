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

void InorderTraveral(Bintree BST)//中序遍历
{
	if (BST)
	{
		InorderTraveral(BST->left);
		cout << BST->data << " ";
		InorderTraveral(BST->right);
	}

}

void PreorderTraveral(Bintree BST)//先序遍历
{
	if (BST)
	{
		cout << BST->data << " ";
		PreorderTraveral(BST->left);
		PreorderTraveral(BST->right);
	}

}

void PostorderTraveral(Bintree BST)//后序遍历
{
	if (BST)
	{
		PostorderTraveral(BST->left);
		PostorderTraveral(BST->right);
		cout << BST->data << " ";
	}

}

