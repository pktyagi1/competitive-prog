#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

typedef struct node
{
	int val;
	struct node *left;
	struct node *right;
	int ht;

}node;
int height(node *root)
{
if(root==NULL)
	return 0;
else
	return max(height(root->left),height(root->right))+1;

}
int getBalance(node *root)
{
	if(root==NULL)
  return 0;
	else return (height(root->left)) - (height(root->right));
}

node* rightrotate(node *root)
{
node* newRoot=root->left;
root->left=newRoot->right;
newRoot->right=root;
root->ht=max(height(root->left),height(root->right))+1;
newRoot->ht=max(height(newRoot->left),height(newRoot->right))+1;
return newRoot;
}
node* leftrotate(node *root)
{
	node* newRoot=root->right;
	root->right=newRoot->left;
	newRoot->left=root;
	root->ht=max(height(root->left),height(root->right))+1;
	newRoot->ht=max(height(newRoot->left),height(newRoot->right))+1;
	return newRoot;

}
node *insert(node *root,int v)
{
if(root==NULL)
{
root=(node*)malloc(sizeof(node));
root->val=v;
root->ht=0;
root->left=NULL;
root->right=NULL;
return root;
}

if(v>root->val)
		root->right=insert(root->right,v);
	else
		root->left=insert(root->left,v);


root->ht=max(height(root->left),height(root->right))+1;
int bf=getBalance(root);
if(bf>1)
{
if(height(root->left->left)>=height(root->left->right))
	return rightrotate(root);
else
{
	root->left=leftrotate(root->left);
	return rightrotate(root);
	}
}
else if(bf<-1)
	{if(height(root->right->right)>=height(root->right->left))
		return leftrotate(root);
	else
	{
		root->right=rightrotate(root->right);
		return leftrotate(root);
		}
	}
return root;
}


int main()
{

node *root=NULL;




int v;
	root=insert(root,1);
	printf("value %d %d\n",root->val,root->ht);
	root=insert(root,2);
	printf("value %d %d\n",root->val,root->ht);
	root=insert(root,3);
	printf("value %d %d\n",root->val,root->ht);

return 0;
}
