#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int data)
{
	Node* newNode = new Node();
	if (!newNode) {
		cout << "Memory error\n";
		return NULL;
	}
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* InsertNode(Node* root, int data)
{
	// If the tree is empty, assign new node address to root.
	if (root == NULL) {
		root = CreateNode(data);
		return root;
	}

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);
		else {
			temp->left = CreateNode(data);
			return root;
		}

		if (temp->right != NULL)
			q.push(temp->right);
		else {
			temp->right = CreateNode(data);
			return root;
		}
	}
}

void preorder(struct Node* node) {
	if (node == NULL) return ;
	cout << node->data << "->";
	preorder(node->left);
	preorder(node->right);
}

void inorder(struct Node* node) {
	if (node == NULL) return ;
	inorder(node->left);
	cout << node->data << "->";
	inorder(node->right);
}

void postorder(struct Node* node) {
	if (node == NULL) return ;
	postorder(node->left);
	postorder(node->right);
	cout << node->data << "->";
}

int main()
{
	Node* root = CreateNode(1);
	root = InsertNode(root, 2);
	root = InsertNode(root, 3);
	root = InsertNode(root, 4);
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	return 0;
}

