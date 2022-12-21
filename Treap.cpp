#include <bits/stdc++.h>
using namespace std;

struct node
{
	int k, p;
	node *lnode, *rnode;
};


node *RotationLeft(node *a)
{
	node *b = a->rnode, *T2 = b->lnode;	
	b->lnode = a;
	a->rnode = T2;
	return b; 
}

node *RotationRight(node *b)
{
	node *a = b->lnode, *T2 = a->rnode;
	a->rnode = b;
	b->lnode = T2;
	return a;
}

node* insert_new(int k)
{
	node* a = new node;
	a->k = k;
	a->p = rand()%100;
	a->lnode = a->rnode = NULL;
	return a;
}

void Treap(node* NodeRoot)
{
	if (NodeRoot)
	{
		Treap(NodeRoot->lnode);
		cout << ">> (Key,Priority): ( "<< NodeRoot->k<<","<< NodeRoot->p<<" ) ";
		if (NodeRoot->lnode)
		{
			cout << "\n ->Left Child: " << NodeRoot->lnode->k;
		}
		if (NodeRoot->rnode)
		{
			cout << "\n ->Right Child: " << NodeRoot->rnode->k;
		}
		cout << endl;
		Treap(NodeRoot->rnode);
	}
}

node* Node_Insert(node* NodeRoot, int k)
{
	if (!NodeRoot)
	{
		return insert_new(k);
	}
	if (k <= NodeRoot->k)
	{
		NodeRoot->lnode = Node_Insert(NodeRoot->lnode, k);
		if (NodeRoot->lnode->p > NodeRoot->p)
		{
			NodeRoot = RotationRight(NodeRoot);
		}
	}
	else 
	{
		NodeRoot->rnode = Node_Insert(NodeRoot->rnode, k);
		if (NodeRoot->rnode->p > NodeRoot->p)
		{
			NodeRoot = RotationLeft(NodeRoot);
		}
	}
	return NodeRoot;
}

node* Node_Delete(node* NodeRoot, int k)
{
	if (NodeRoot == NULL)
	{
		return NodeRoot;
	}
	if (k < NodeRoot->k)
	{
		NodeRoot->lnode = Node_Delete(NodeRoot->lnode, k);
	}
	else if (k > NodeRoot->k)
	{
		NodeRoot->rnode = Node_Delete(NodeRoot->rnode, k);
	}
	else if (NodeRoot->lnode == NULL)
	{
		node *b = NodeRoot->rnode;
		delete(NodeRoot);
		NodeRoot = b; 
	}
	else if (NodeRoot->rnode == NULL)
	{
		node *b = NodeRoot->lnode;
		delete(NodeRoot);
		NodeRoot = b;
	}

	else if (NodeRoot->lnode->p < NodeRoot->rnode->p)
	{
		NodeRoot = RotationLeft(NodeRoot);
		NodeRoot->lnode = Node_Delete(NodeRoot->lnode, k);
	}
	else
	{
		NodeRoot = RotationRight(NodeRoot);
		NodeRoot->rnode = Node_Delete(NodeRoot->rnode, k);
	}

	return NodeRoot;
}

node* NodeSearch(node* NodeRoot, int k)
{
	if (NodeRoot == NULL || NodeRoot->k == k){
		return NodeRoot;
	}
	if (NodeRoot->k < k){
		return NodeSearch(NodeRoot->rnode, k);
		return NodeSearch(NodeRoot->lnode, k);
	}
}

int main()
{
	struct node *NodeRoot = NULL;
	srand(time(NULL));
	NodeRoot = Node_Insert(NodeRoot, 90);
	NodeRoot = Node_Insert(NodeRoot, 25);
	NodeRoot = Node_Insert(NodeRoot, 30);
	NodeRoot = Node_Insert(NodeRoot, 55);
	NodeRoot = Node_Insert(NodeRoot, 5);
	NodeRoot = Node_Insert(NodeRoot, 57);
	NodeRoot = Node_Insert(NodeRoot, 22);

	cout << "TREAP TREE (KEY,PRIORITY): \n";
	Treap(NodeRoot);
	
	cout << "\nINSERT KEY 34\n";
	NodeRoot = Node_Insert(NodeRoot, 34);
	Treap(NodeRoot);

	cout << "\nDELETE KEY 55\n";
	NodeRoot = Node_Delete(NodeRoot, 55);
	Treap(NodeRoot);
	
	cout << "\nSEARCH KEY 30\n";
	node *search  = NodeSearch(NodeRoot, 30);
	(search == NULL)? cout << ">>30 Not Found ":
				cout << ">>30 found";
	return 0;
}