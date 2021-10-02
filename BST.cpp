#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data){
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data){
	if(root == NULL){
		root = GetNewNode(data);
	}
	else if(data <= root->data){
		root->left = Insert(root->left, data);
	}
	else{
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(BstNode* root, int data){
	if(root==NULL)	
		return false;
	else if(root->data == data)	
		return true;
	else if(data <= root->data)
		return Search(root->left, data);
	else
		return Search(root->right, data);
}

// Iterative 
int FindMinIterative(BstNode* root){
	if(root==NULL){
		cout<<"Error: Tree is Empty.\n";
		return -1;
	}
	while(root->left != NULL){
		root = root->left;
	}
	return root->data;
}

// Recursive
int FindMinRecursive(BstNode* root){
	if(root==NULL){
		cout<<"Error: Tree is Empty";
		return -1;
	}
	else if(root->left == NULL){
		return root->data;
	}

	return FindMinRecursive(root->left);
}

int FindHeight(BstNode* root){
	if(root==NULL)
		return -1;
	int leftHeight = FindHeight(root->left);
	int rightHeight = FindHeight(root->right);

	return max(leftHeight, rightHeight) + 1;
}

void LevelOrder(BstNode* root){
	if(root==NULL)
		return;
	queue<BstNode*> Q;
	Q.push(root);

	// while there is at least one discovered node
	while(!Q.empty()){
		BstNode* current = Q.front();
		
		cout<<current->data<<" ";

		if(current->left != NULL)	Q.push(current->left);
		if(current->right != NULL)	Q.push(current->right);

		Q.pop();
	}
}

void Preorder(BstNode *root){
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(BstNode *root){
	if(root == NULL)
		return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

void Postorder(BstNode *root){
	if(root == NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<" ";
}

BstNode* Delete(BstNode *root, int data){
	if(root == NULL)
		return root;
	else if(data < root->data) 
		root->left = Delete(root->left, data);
	else if(data > root->data) 
		root->right = Delete(root->right, data);
	else{	// I found node to be deletes.
		// Case 1: No Child
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}
		// Case 2: One Child
		else if(root->left == NULL){
			BstNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL){
			BstNode *temp = root;
			root = root->left;
			delete temp;
		}
		// Case 3: 2 Children
		else{
			int Min = FindMinIterative(root->right);
			root->data = Min;
			root->right = Delete(root->right, Min);
		}
	}
	return root;
}

/*
BstNode* FindMin(BstNode* root){
	if(root == NULL)
		return NULL;
	while(root->left != NULL)
		root = root->left;
	return root;
}

BstNode* GetSuccessor(BstNode *root, int data){
	BstNode* current = Find(root, data);
	if(current == NULL)
		return NULL;

	// Case 1: Node has right subtree
	if(current->right != NULL)
		return FindMin(current->right);

	// Case 2: No right subtree
	else{
		BstNode *successor = NULL;
		BstNode *ancestor = root;
		while(ancestor != current){
			if(current->data < ancestor->data){
				successor = ancestor;
				ancestor = ancestor->left;
			}
			else{
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
}
*/

int main() {
	BstNode* root = NULL;
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	cout<<Search(root, 20)<<endl;
	cout<<Search(root, 120)<<endl;
	cout<<"Minimum Iterative: "<<FindMinIterative(root)<<endl;
	cout<<"Minimum Recursive: "<<FindMinRecursive(root)<<endl;
	root = Insert(root, 12);
	cout<<"Height of BST is: "<<FindHeight(root)<<endl;
	
	cout<<"Level Order Traversal : ";
	LevelOrder(root);
	
	cout<<endl<<"Preorder Traversal : ";
	Preorder(root);
	
	root = Delete(root, 20);
	cout<<endl<<"Preorder Traversal : ";
	Preorder(root);

	cout<<endl<<"Inorder Traversal : ";
	Inorder(root);
	
	cout<<endl<<"Postorder Traversal : ";
	Postorder(root);
}