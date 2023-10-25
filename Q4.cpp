#include<bits/stdc++.h>
using namespace std;

// An AVL tree node
class Node
{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};

// function to get height of the tree
int height(Node *root)
{
	if (root == NULL)
		return 0;
	return root->height;
}

// function to get maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }

Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

// function to right-rotate subtree rooted with y
Node *rightRotation(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	// rotation
	x->right = y;
	y->left = T2;

	// update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// return new root
	return x;
}

// function to left-rotate subtree rooted with x
Node *leftRotation(Node *x)
{
	/* YOUR CODE HERE
	*
	*
	*/
}

//get balance factor of node N
int getBalance(Node *root)
{
	if (root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

// recursive function that inserts a key into the subtree rooted with a given node and returns the new root of the subtree.
Node* insert(Node* node, int key)
{
	// normal BST insert
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // equal keys not allowed in BST
		return node;

	//update height of this ancestor node
	node->height = 1 + max(height(node->left), height(node->right));

	// get the balance factor of this ancestor node to check if this node became unbalanced
	int balance = getBalance(node);

	// node is unbalanced,
	// 4 different cases

	// Left-Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotation(node);

	// Right-Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotation(node->right);
		return leftRotation(node);
	}

	// Left-Right Case
	/* YOUR CODE HERE
	*
	*
	*/

	// Right-Right Case
	/* YOUR CODE HERE
	*
	*
	*/

	// return the node pointer
	return node;
}

// function to print preorder traversal of the tree.
void preOrder(Node *root)
{
	if(root != NULL)
	{
		cout << root->key << " ";
		/* YOUR CODE HERE
		*
		*
		*/
	}
}

int main()
{
	Node *root = NULL;

	/* construct a tree */
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	cout << "Preorder traversal of the AVL tree is \n";
	preOrder(root);

	return 0;
}
