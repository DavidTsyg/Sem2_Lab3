#pragma once
#include "stdafx.h"
#include <iostream>
#include "binarytree.h"

using namespace std;

class avltree : public binarytree
{
public:

	int height(node* leaf) {
		int left, right;

		if (leaf == NULL)
			return 0;
		left = height(leaf->left);
		right = height(leaf->right);
		if (left > right)
			return left + 1;
		else
			return right + 1;
	}

	void rotateLeftOnce(node*& leaf) {
		node* otherNode;

		otherNode = leaf->left;
		leaf->left = otherNode->right;
		otherNode->right = leaf;
		leaf = otherNode;
	}


	void rotateLeftTwice(node*& leaf) {
		rotateRightOnce(leaf->left);
		rotateLeftOnce(leaf);
	}


	void rotateRightOnce(node*& leaf) {
		node *otherNode;

		otherNode = leaf->right;
		leaf->right = otherNode->left;
		otherNode->left = leaf;
		leaf = otherNode;
	}


	void rotateRightTwice(node*& leaf) {
		rotateLeftOnce(leaf->right);
		rotateRightOnce(leaf);
	}

	void newinsert(double key) {
		if (search_serve(key, root) == NULL)
		{
			if (root == NULL) {
				root = new node(key);
			}
			else
				insert(root, key);
		}
		else cout << "Key already exists !" << endl;
	}

	node* insert(node*& leaf, double key)
	{
		if (leaf == NULL)
			leaf = new node(key);
		else if (key < leaf->key_value)
		{
			insert(leaf->left, key);
			if (height(leaf->left) - height(leaf->right) == 2) {
				if (key < leaf->left->key_value)
					rotateLeftOnce(leaf);
				else
					rotateLeftTwice(leaf);
			}
		}
		else if (key > leaf->key_value)
		{
			insert(leaf->right, key);
			if (height(leaf->right) - height(leaf->left) == 2) {
				if (key > leaf->right->key_value)
					rotateRightOnce(leaf);
				else
					rotateRightTwice(leaf);
			}
		}
		return leaf;
	}

	node* deleteNode(node* leaf, double key)
	{
		if (leaf == NULL)
			return leaf;
		if (key < leaf->key_value)
			leaf->left = deleteNode(leaf->left, key);
		else if (key > leaf->key_value)
			leaf->right = deleteNode(leaf->right, key);
		else
		{
			if ((leaf->left == NULL) || (leaf->right == NULL))
			{
				node* temp = leaf->left ? leaf->left :
					leaf->right;

				// нет детей
				if (temp == NULL)
				{
					temp = leaf;
					leaf = NULL;
				}
				else // один ребенок
					*leaf = *temp;
				delete temp;
			}
			else
			{
				//два ребенка
				node* temp = findmin(leaf->right);
				leaf->key_value = temp->key_value;
				leaf->right = deleteNode(leaf->right, temp->key_value);
			}
		}
		if (leaf == NULL)
			return leaf;

		else if (key < leaf->key_value)
		{
			insert(leaf->left, key);
			if (height(leaf->left) - height(leaf->right) == 2) {
				if (key < leaf->left->key_value)
					rotateLeftOnce(leaf);
				else
					rotateLeftTwice(leaf);
			}
		}

		if (height(leaf->right) - height(leaf->left) == 2) {
			if (key > leaf->right->key_value)
				rotateRightOnce(leaf);
			else
				rotateRightTwice(leaf);
		}

		return leaf;
	}

	void deletenode_test(double key)
	{
		if(search_serve(key, root) != NULL)
			deleteNode(root, key);
		else cout << "Key doesn't exist !" << endl;
	}
	void showheight()
	{
		cout << height(root) << endl;
	}


};