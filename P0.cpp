#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include "node.h"
#include "tree.h"
using namespace std;

int main(int argc, char ** argv) {

	//loop counters	
	int i, j;
	
	ifstream input;
	string line;
	
	string filename;

	//lineArray holds each line of input
	//textArray holds the parsed words from lines
	vector<string> lineArray;
	vector<string> textArray;
	
	bool isFileGiven = false;

	if (argc > 2) {
		cout << "Too many parameters\n";
		exit(-1);
	}
	if (argc == 1) { //if no file is passed, reads from stdin
		
		isFileGiven = false;

	}
	else { //filename was given as a parameter
		isFileGiven = true;
		filename = argv[1];
		filename += ".input1";
		input.open(filename.c_str());
		if (input == NULL) {
			fprintf(stderr, "No such file or directory: %s\n", filename.c_str());
			exit(-1);
		}
	}
	
	if (isFileGiven) {

		//stores each line into a string vector
		while (getline(input, line)) {

			lineArray.push_back(line + "\n");

		}
	}
	else {
	
		while (getline(cin, line)) {

                        lineArray.push_back(line + "\n");

                }
	}

	//iterates through each line and parses into strings separated by whitespace	
	for (i = 0; i != lineArray.size(); i++) {
		
		//integer for keeping track of substrings between whitespace in each line
		int temp = 0;
		
		for (j = 0; j != lineArray[i].length(); j++) {
		
			//if whitespace is found, substring from temp value to found whitespace
			
			if (isspace(lineArray[i][j])) {
			
				textArray.push_back(lineArray[i].substr(temp, j - temp));
				temp = j + 1;

			}	
		}
	}
		
	//remove duplicates
	for (i = 0; i != textArray.size(); i++) {

		for (j = 0; j != textArray.size(); j++) {

			if (i == j)
				continue;
			else if (textArray[i] == textArray[j]) {
				textArray.erase(textArray.begin() + i);
				i--;
				break;
			}
		}
	}	
	

	//using string array to pass as parameter
	string * strPtr = &textArray[0];
		
	node * root = buildTree(strPtr, textArray.size());
	
	ofstream outfile; 
	
	if (isFileGiven) {

		outfile.open((filename.substr(0, filename.find(".")) + ".preorder").c_str(), fstream::out);
		printPreorder(root, &outfile);
		outfile.close();
		outfile.open((filename.substr(0, filename.find(".")) + ".postorder").c_str(), fstream::out);	
		printPostorder(root, &outfile);
		outfile.close();
		outfile.open((filename.substr(0, filename.find(".")) + ".inorder").c_str(), fstream::out);
		printInorder(root, &outfile);
		outfile.close();

	}

	else {
		
		outfile.open("out.preorder", fstream::out);
		printPreorder(root, &outfile);
		outfile.close();
		outfile.open("out.postorder", fstream::out);
		printPostorder(root, &outfile);
		outfile.close();
		outfile.open("out.inorder", fstream::out);
		printInorder(root, &outfile);
		outfile.close();

	}
	
	/*		
	printPreorder(root);
	cout << endl;
	printPostorder(root);
	cout << endl;
	printInorder(root);
	*/
	input.close();	

	return 0;
}
