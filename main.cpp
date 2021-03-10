#include <iostream>
using namespace std;

struct Node{
	int value;
	Node *next;
};

void display(Node *root){
	
	while(root!=NULL){
		cout<<root->value<<" ";
		root = root->next;
	}
	cout<<endl;
}

void insertEnd(Node **root, int val)
{
	Node *newNode = new Node;
	newNode->value = val;
	newNode->next = NULL;
	//
	if (*root == NULL)
		*root = newNode;
	else{
		//I have list before
		Node *ptr = *root;
		while (ptr->next != NULL)
			ptr = ptr->next;
		//
		ptr->next = newNode;
	}
}

void insertMiddle(Node **root, int val)
{
	Node *newNode = new Node;
	newNode->value = val;
	//
	Node *ptr;
	Node *p = *root;
	
	while (p->value < val){
		ptr = p;
		p = p->next;
	}
	//
	ptr->next = newNode;
	newNode->next = p;
}
void insertBegin(Node **root, int val)
{
	Node *newNode = new Node;
	newNode->value = val;
	//
	newNode->next = *root;
	*root = newNode;
}

int main(int argc, char** argv) 
{
	Node *root = NULL;
	//
	insertEnd(&root, 24);
	insertEnd(&root, 31);
	insertEnd(&root, 33);
	insertEnd(&root, 41);
	//
	display(root);
	//
	insertMiddle(&root, 32);
	//
	display(root);
	//
	insertBegin(&root, 20);
	display(root);
	
	return 0;
}
