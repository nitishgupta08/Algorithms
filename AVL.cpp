#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	int height;
};

class AVL {
public:
	Node *root;
	AVL() {
		root = NULL;
	}

	int height(Node *p);
	int balance_factor(Node *p);
	void inorder(Node *p);
	Node *insert(Node *root, int key);
	Node *r_rotation(Node *p);
	Node *l_rotation(Node *p);
	bool search(Node *p,int key);
	Node *deletion(Node *p,int key);
	int inorder_predecessor(Node *p);
	int inorder_successor(Node *p);

};

int AVL::height(Node *p) {
	int left_h,right_h;
	left_h = (p && p->left) ? p->left->height : 0;
	right_h = (p && p->right) ? p->right->height : 0;

	return right_h>left_h ? right_h+1 : left_h+1;
}

int AVL::balance_factor(Node *p) {
	int left_h,right_h;
	left_h = (p && p->left) ? p->left->height : 0;
	right_h = (p && p->right) ? p->right->height : 0;

	return right_h-left_h;
}

void AVL::inorder(Node *p) {
	if(p) {
		inorder(p->left);
		cout << p->data << "	|	" <<  balance_factor(p) << endl;
		inorder(p->right);
	}
}


Node *AVL::insert(Node *root,int key) {
	Node *t = new Node();

	if(root==NULL) {
		t->data = key;
		t->left = NULL;
		t->right = NULL;
		t->height = 1;
		return t;
	}

	if(key < root->data) {
		root->left = insert(root->left,key);
	}
	else if(key > root->data) {
		root->right = insert(root->right,key);
	}

	root->height = height(root);

	if(balance_factor(root) == -2 && balance_factor(root->left) == -1) return r_rotation(root);
	if(balance_factor(root) == 2 && balance_factor(root->right) == 1) return l_rotation(root);
	if(balance_factor(root) == 2 && balance_factor(root->left) == 1) {
		root->left = l_rotation(root->left);
		return r_rotation(root);
	}
	if(balance_factor(root) == -2 && balance_factor(root->right) == -1) {
		root->right = r_rotation(root->right);
		return l_rotation(root);
	}

	return root;
}

Node *AVL::r_rotation(Node *p) {
	Node *l = p->left;
	Node *lr = l->right;


	l->right = p;
	p->left = lr;

	p->height = height(p);
	l->height = height(l);

	if(root == p) {
		root = l;
	}

	return l;
}

Node *AVL::l_rotation(Node *p) {
	Node *r = p->right;
	Node *rl = r->left;


	r->left = p;
	p->right = rl;

	p->height = height(p);
	r->height = height(r);

	if(root == p) {
		root = r;
	}

	return r;
}

bool AVL::search(Node *p,int key) {
	if(!p) return false;

	if(p->data == key) return true;

	if(key < p->data) {
		return search(p->left,key);
	}
	
	return search(p->right,key);
}


Node *AVL::deletion(Node *p, int key) {
	if(!p) {
        return NULL;
    }
	if(!p->left && !p->right) {
		if(p == root) root = NULL;
		delete p;
		return NULL;
	}
    
	if(key < p->data) {
		p->left = deletion(p->left,key);
	}
	else if(key > p->data) {
		p->right = deletion(p->right,key);
	}
	else {
		int q;
		if(height(p->left) > height(p->right)) {
			q = inorder_predecessor(p->left); 
			p->data = q;
			p->left = deletion(p->left,q);
		}
		else {
			q = inorder_successor(p->right);
			p->data = q;
			p->right = deletion(p->right,q);
		}
	}

	p->height = height(p);

	if(balance_factor(p) == -2 && balance_factor(p->left) == -1) return r_rotation(p);
	if(balance_factor(p) == 2 && balance_factor(p->right) == 1) return l_rotation(p);
	if(balance_factor(p) == 2 && balance_factor(p->left) == 1) {
		root->left = l_rotation(p->left);
		return r_rotation(p);
	}
	if(balance_factor(p) == -2 && balance_factor(p->right) == -1) {
		root->right = r_rotation(p->right);
		return l_rotation(p);
	}

	return p;
}

int AVL::inorder_predecessor(Node *p) {
	while(p && p->right) p = p->right;
	return p->data;
}

int AVL::inorder_successor(Node *p) {
	while(p && p->left) p = p->left;
	return p->data;
}


int main() {
	AVL *tree = new AVL();

	tree->root = tree->insert(NULL,30);
	tree->insert(tree->root,40);
	tree->insert(tree->root,50);
	tree->insert(tree->root,50);
	tree->insert(tree->root,60);
	tree->insert(tree->root,70);
	tree->insert(tree->root,80);
	tree->insert(tree->root,90);

	cout << endl;
	cout << "----Inorder traversal after insertion----" << endl;
	cout << "data" <<  "	| " << "balance factor" << endl;
	tree->inorder(tree->root);

	cout << endl;
	cout << "----Searching 40 and 65 in the AVL tree----" << endl;
	bool x = tree->search(tree->root,40);
	bool y = tree->search(tree->root,65);
	if(x) cout << "=> 40 found in tree" << endl;
	else cout << "=> 40 not found in tree" << endl;
	if(y) cout << "=> 65 found in tree" << endl;
	else cout << "=> 65 not found in tree" << endl;

	cout << endl;
	cout << "=> Deleting 60 from the AVL tree" << endl;
	tree->deletion(tree->root,60);
	cout << "------Inorder traversal after deletion------" << endl;
	cout << "data" <<  "	| " << "balance factor" << endl;
	tree->inorder(tree->root);

	cout << endl;
	cout << "----Searching 60 in the AVL tree----" << endl;
	bool z = tree->search(tree->root,60);
	if(z) cout << "=> 60 found in tree" << endl;
	else cout << "=> 60 not found in tree" << endl;

	cout << endl;
	return 0;
}