// BinaryTrees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "binarytree.h"

using namespace std;

int main()
{
	binarytree tree;
	double key;
	unsigned int answer;
	bool flag = true;
	cout << "Press 1 to add a node; 2 to delete a node; 3 to search for a node;" << endl;
	cout << "      4 to print the path to a node; 5 to print the tree" << endl << endl << endl;
	while (flag)
	{
		cout << "Choose" << endl << endl;
		cin >> answer;
		switch (unsigned int(answer))
		{
		case 1:
		{
			cout << "Input the key" << endl << endl;
			cin >> key;
			tree + key;
			break;
		}
		case 2:
		{
			cout << "Input the key" << endl << endl;
			cin >> key;
			tree - key;
			break;
		}
		case 3:
		{
			cout << "Input the key" << endl << endl;
			cin >> key;
			tree.search(key);
			break;
		}
		case 4:
		{
			cout << "Input the key" << endl << endl;
			cin >> key;
			tree.printpath(key);
			break;
		}
		case 5:
		{
			tree.print();
			break;
		}
		default: { flag = false; cout << "Exiting the cycle" << endl << endl; }
		}
	}



	_getch();
	return 0;
}

