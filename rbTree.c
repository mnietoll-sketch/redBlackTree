#include "rbTree.h"
#include <stdlib.h>

#define RBT_ROTATE_FAIL -3
#define RBT_ALLOC_FAIL -2
#define RBT_DUPLICATE -1
#define RBT_OK 0
#define ISROOT(t, node) ((t)->root == (node))
#define ISSENTINEL(t, node) (&(t)->sentinel == (node))
#define ISLEFTCHILD(node) ((node) && (node)->parent && (node)->parent->left == (node))
#define ISRIGHTCHILD(node) ((node) && (node)->parent && (node)->parent->right == (node))
#define REDNODE(t, key) (initNode((key), RED, &((t)->sentinel), &((t)->sentinel), &((t)->sentinel)))
#define BLACKNODE(t, key) (initNode((key), BLACK, &((t)->sentinel), &((t)->sentinel), &((t)->sentinel)))

static Node *getUncle(Node *node){
	if(ISLEFTCHILD(node))
		return node->parent->right;
	if(ISRIGHTCHILD(node))
		return node->parent->left;
	return NULL;
}

static int leftRotate(Tree *t, Node *x){
	if(x == NULL) return RBT_ROTATE_FAIL;
	if(ISSENTINEL(t, x->right)) return RBT_ROTATE_FAIL;
	
	Node *y = x->right;

	x->right = y->left;
	if(!ISSENTINEL(t, y->left)) y->left->parent = x;

	y->parent = x->parent;
	if(ISSENTINEL(t, y->parent))
		t->root = y;
	else if(ISLEFTCHILD(x))
		y->parent->left = y;
	else
		y->parent->right = y;

	y->left = x;
	x->parent = y;
	return RBT_OK;
}

static int rightRotate(Tree *t, Node *x){
	if(x == NULL) return RBT_ROTATE_FAIL;
	if(ISSENTINEL(t, x->left)) return RBT_ROTATE_FAIL;

	Node *y = x->left;

	x->left = y->right;
	if(!ISSENTINEL(t, y->right)) y->right->parent = x;

	y->parent = x->parent;
	if(ISSENTINEL(t, y->parent))
		t->root = y;
	else if(ISLEFTCHILD(x))
		y->parent->left = y;
	else
		y->parent->right = y;

	y->right = x;
	x->parent = y;
	return RBT_OK;
}

static Node *initNode(int key, int color, Node *parent, Node *left, Node *right){
	Node *newNode = NULL;
	newNode = (Node *)malloc(sizeof(Node));
	
	if(newNode == NULL)
		return NULL;
	newNode->key = key;
	newNode->color = color;
	newNode->parent = parent;
	newNode->left = left;
	newNode->right = right;
	return newNode;
}

int initTree(Tree *t){
	t->sentinel.color = BLACK;
	t->root = &(t->sentinel);
	return RBT_OK;
}

int insertKey(Tree *t, int key){
	Node *newNode = REDNODE(t, key);
	if(newNode == NULL)
		return RBT_ALLOC_FAIL;

	int insertNodeResult = insertNode(t, newNode);
	if(insertNodeResult == RBT_DUPLICATE){
		free(newNode);
		return RBT_DUPLICATE;
	}
	return RBT_OK;
}

int insertNode(Tree *t, Node *newNode){
	//TODO
	return 0;
}

int insertFixup(Tree *t, Node *node){
	//TODO
	return 0;

}
