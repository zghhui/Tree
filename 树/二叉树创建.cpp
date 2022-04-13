#include<iostream>
#include<cstdlib> 
#include<queue>
using namespace std;
typedef struct tree* Bintree;
struct tree {
	int data;
	Bintree left;
	Bintree right;
};

queue<Bintree> q;

Bintree CreatBintree()
{
	Bintree p;
	int rootdata;
	cin >> rootdata;
	if (!rootdata)
	{
		return NULL;
	}
	else
	{
		p = (Bintree)malloc(sizeof(tree));
		p->data = rootdata;
		p->left = p->right = NULL;
		q.push(p);
	}
	while (!q.empty())
	{
		Bintree tem = q.front();
		q.pop();
		int zuodata, youdata;
		cin >> zuodata;
		if (!zuodata)
		{
			tem->left = NULL;
		}
		else
		{
			tem->left = (Bintree)malloc(sizeof(tree));
			tem->left->data = zuodata;
			tem->left->left = tem->left->right = NULL;
			q.push(tem->left);
		}

		cin >> youdata;
		if (!youdata)
		{
			tem->right = NULL;
		}
		else
		{
			tem->right = (Bintree)malloc(sizeof(tree));
			tem->right->data = youdata;
			tem->right->left = tem->right->right = NULL;
			q.push(tem->right);
		}

	}
	return p;
}

void preorder(Bintree p)//中序遍历
{
	if (p)
	{
		//cout<<" 工作 ";
		preorder(p->left);
		cout << p->data << " ";
		preorder(p->right);
	}
}
int main()
{
	Bintree p;
	p = CreatBintree();
	preorder(p);
}