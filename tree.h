#include <iostream>
#include "node.h"
#include <vector>
#include <string>
#include <fstream>

#ifndef tree_h
#define tree_h
#endif

node * buildTree(std::string*, int);
void printPreorder(node *, std::ofstream *, int);
void printPostorder(node *, std::ofstream *, int);
void printInorder(node *, std::ofstream *, int);
