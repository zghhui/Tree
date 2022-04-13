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

void PostorderTraveral(Bintree BST)//�������
{
	if (BST)
	{
		PostorderTraveral(BST->left);
		PostorderTraveral(BST->right);
		cout << BST->data << " ";
	}

}

