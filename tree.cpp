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

void printPreorder(node * root, ofstream * outfile) {

	
	if (root == NULL)
		return;

	*outfile << root->value << " ";

	printPreorder(root->left, outfile);
	
	printPreorder(root->right, outfile);
	

}

void printPostorder(node * root, ofstream * outfile) {

	if (root == NULL)
		return;

	printPostorder(root->left, outfile);

	printPostorder(root->right, outfile);
	
	*outfile << root->value << " ";

} 

void printInorder(node * root, ofstream * outfile) {

	if (root == NULL)
		return;

	printInorder(root->left, outfile);

	*outfile << root->value << " ";

	printInorder(root->right, outfile);

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
