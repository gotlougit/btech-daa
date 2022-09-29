#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class BSTNode {
	BSTNode *parent;
	BSTNode *left;
	BSTNode *right;
	
	public:
		int key;
		
		BSTNode(int k, BSTNode *p, BSTNode *l, BSTNode *r) {
			key = k;
			parent = p;
			left = l;
			right = r;
		}

		void inorderTraversal(void) {
			if (left) {
				left->inorderTraversal();
			}
			cout << key << " ";
			if (right) {
				right->inorderTraversal();
			}
		}

		BSTNode* search(int k) {
			if (k == key) {
				return this;
			}
			if (left && k < key) {
				return left->search(k);
			}
			if (right && k > key) {
				return right->search(k);
			}
			return NULL;
		}

		BSTNode* min(void) {
			if (left) {
				return left->min();
			}
			return this;
		}

		BSTNode* max(void) {
			if (right) {
				return right->max();
			}
			return this;
		}

		BSTNode* successor(void) {
			if (right) {
				return right->min();
			}
			BSTNode *cur = this;
			BSTNode *par = parent;

			while (par && cur == parent->right) {
				cur = parent;
				par = par->parent;
			}
			return par;
		}

		BSTNode* predecessor(void) {
			if (left) {
				return left->max();
			}
			BSTNode *cur = this;
			BSTNode *par = parent;

			while (par && cur == parent->left) {
				cur = parent;
				par = par->parent;
			}
			return par;
		}

		void insert(BSTNode *newnode) {
			BSTNode *x = this;
			BSTNode *y = NULL;
			while (x) {
				y = x;
				if (newnode->key < x->key) {
					x = x->left;
				} else {
					x = x->right;
				}
			}
			newnode->parent = y;
			if (y == NULL) {
				return;
			} else if (newnode->key < y->key) {
				y->left = newnode;
			} else {
				y->right = newnode;
			}
		}

		void transplant(BSTNode *u, BSTNode *v) {
			if (u == NULL) {
				return;
			}
			if (u->parent == NULL) {
				if (v == NULL) {
					this->key = 0;
					this->parent = NULL;
					this->left = NULL;
					this->right = NULL;
				} else {
					this->key = v->key;
					this->parent = v->parent;
					this->left = v->left;
					this->right = v->right;
				}
			} else if (u == u->parent->left) {
				u->parent->left = v;
			} else {
				u->parent->right = v;
			}

			if (v == NULL) {
				v->parent = u->parent;
			}
		}

		void deleteNode(BSTNode *z) {
			if (z->left == NULL) {
				this->transplant(z, z->right);
			} else if (z->right == NULL) {
				this->transplant(z, z->left);
			} else {
				BSTNode *y = z->right->min();
				if (y != z->right) {
					this->transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				this->transplant(z,y);
				y->left = z->left;
				y->left->parent = y;
			}
		}
		
};

int main(void) {

	BSTNode root = BSTNode(2,NULL, NULL, NULL);
	BSTNode node1 = BSTNode(1,NULL, NULL, NULL);
	BSTNode node2 = BSTNode(3,NULL, NULL, NULL);
	BSTNode node3 = BSTNode(5,NULL, NULL, NULL);
	BSTNode node4 = BSTNode(9,NULL, NULL, NULL);
	BSTNode node5 = BSTNode(0,NULL, NULL, NULL);

	cout << "Inserting nodes into BST" << endl;
	root.insert(&node1);
	root.insert(&node2);
	root.insert(&node3);
	root.insert(&node4);
	root.insert(&node5);
	cout << "Inorder traversal: ";
	root.inorderTraversal();
	cout << endl;

	int res = root.search(3)->key;
	cout << "Found " << res << endl;

	cout << "Root predecessor: " << root.predecessor()->key << endl;
	cout << "5's successor: " << node3.successor()->key << endl;
	cout << "Min element: " << root.min()->key << endl;
	cout << "Max element: " << root.max()->key << endl;

	cout << "Deleting an element from bst" <<  endl;
	root.deleteNode(&node1);
	cout << "Inorder traversal: ";
	root.inorderTraversal();
	cout << endl;

	return 0;
}
