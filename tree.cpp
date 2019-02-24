#include "tree.h"
#include "node.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

static void insertNode(node *, string);

node * buildTree(string * arr, int length) {

	node * root = new node;
	root->left = NULL;
	root->right = NULL;
	root->value = "";
	
	for (int i = 0; i != length; i++)
		insertNode(root, arr[i]);

	return root;	
}

void printPreorder(node * root, ofstream * outfile, int level) {

	
	if (root == NULL)
		return;
	
	for (int i = 0; i != level; i++)
		*outfile << " "; 

	*outfile << root->value << endl;

	printPreorder(root->left, outfile, level + 1);
	
	printPreorder(root->right, outfile, level + 1);
	

}

void printPostorder(node * root, ofstream * outfile, int level) {

	if (root == NULL)
		return;

	printPostorder(root->left, outfile, level + 1);

	printPostorder(root->right, outfile, level + 1);
	
	for (int i = 0; i != level; i++)
                *outfile << " ";

	*outfile << root->value << endl;

} 

void printInorder(node * root, ofstream * outfile, int level) {

	if (root == NULL)
		return;

	printInorder(root->left, outfile, level + 1);

	for (int i = 0; i != level; i++)
                *outfile << " ";

	*outfile << root->value << endl;

	printInorder(root->right, outfile, level + 1);

}

static void insertNode(node * root, string value) {
	
	if (root->value == "") {
		
		root->value = value;
		return;

	}
	else if (value > root->value) {
		
		if (root->right == NULL) {
					
			node * newNode = new node;
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->value = value;
			root->right = newNode;
			return;

		}
		else {

			insertNode(root->right, value);

		}
	
	}
	else if (value < root->value) {

		if (root->left == NULL) {

			node * newNode = new node;
                        newNode->left = NULL;
                        newNode->right = NULL;
                        newNode->value = value;
			root->left = newNode;
			return;

		}
		else {
			
			insertNode(root->left, value);
		
		}

	}

}
