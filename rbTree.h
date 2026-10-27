#ifndef RBTREE
#define RBTREE

#define RED 0
#define BLACK 1

typedef struct node{
	int key;
	int color;
	struct node *parent;
	struct node *left;
	struct node *right;
} Node;

typedef struct tree{
	Node sentinel;
	Node *root;
} Tree;

int initTree(Tree *t);
int insertKey(Tree *t, int key);
int insertNode(Tree *t, Node* newNode);
int insertFixup(Tree *t, Node *node);
#endif
