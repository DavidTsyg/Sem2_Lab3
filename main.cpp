// BinaryTrees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "binarytree.h"
#include "avltree.h"

using namespace std;

int main()
{
	binarytree tree1;
	avltree tree2;
	
	
	tree1.insert(10); tree1.insert(5); tree1.insert(15); tree1.insert(1); 
	tree1.insert(2); tree1.insert(16); tree1.print(); tree1.destroynode(16); tree1.print();
	
	tree2.newinsert(10); tree2.newinsert(5); tree2.newinsert(15); tree2.newinsert(1); tree2.newinsert(2); 
	tree2.newinsert(16); tree2.print(); tree2.deletenode_test(16); tree2.print();
	



	_getch();
	return 0;
}

