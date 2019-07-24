#pragma once
#include "stdafx.h"
#include<iostream>
#include <iomanip>
using namespace std;
enum TreeNodeColor{RED,BLACK};

template<class T>
class RBTNode
{
public:
	T key; //�ؼ���
	TreeNodeColor color;//color
	RBTNode *parent;
	RBTNode *left;
	RBTNode *right;
	RBTNode(T value, TreeNodeColor c, RBTNode *p, RBTNode *l, RBTNode *r) :
		key(value), color(c), parent(), left(l), right(r) {}
};


template<class T>
class RBTree
{
private:
	RBTNode<T>* mRoot;

public:
	RBTree();
	~RBTree();
		
	//ǰ�����
	void preOrder();
	//�������
	void inOrder();
	//��������
	void postOrder();
	
	//�ݹ�ʵ�ֲ��Һ������ֵΪKey�Ľڵ�
	RBTNode<T>* search(T key);
	//�ǵݹ�ʵ�ֲ��Һ������ֵΪkey�Ľڵ�
	RBTNode<T>* iterativeSearch(T key);

	//�ҵ���С�ڵ㲢���ؼ�ֵ
	T minimum();
	//�ҵ����ڵ㲢���ؼ�ֵ
	T maximum();

	//�ҵ��ڵ�x�ĺ�̽ڵ㡣�����ҵ�"���������ֵ���ڸýڵ�"��"��С�ڵ�"��
	RBTNode<T>* successor(RBTNode<T>* x);
	//�ҵ��ڵ�x��ǰ���ڵ㡣��������"���������ֵС�ڸý��"��"�����"��
	RBTNode<T>* predecessor(RBTNode<T>* x);

	//���ڵ㣨keyΪ�ڵ��ֵ������������
	void insert(T key);

	//ɾ���ڵ㣨keyΪ�ڵ��ֵ��
	void remove(T key);

	//���ٺ����
	void destroy();

	//��ӡ�����
	void print();

private:
	//ǰ����������
	void preOrder(RBTNode<T>* tree) const;
	//������������
	void inOrder(RBTNode<T>* tree) const;
	//�������������
	void postOrder(RBTNode<T>* tree) const;

	// (�ݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
	RBTNode<T>* search(RBTNode<T>* x, T key) const;
	// (�ǵݹ�ʵ��)����"�����x"�м�ֵΪkey�Ľڵ�
	RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;

	// ������С��㣺����treeΪ�����ĺ��������С��㡣
	RBTNode<T>* minimum(RBTNode<T>* tree);
	// ��������㣺����treeΪ�����ĺ����������㡣
	RBTNode<T>* maximum(RBTNode<T>* tree);

	// ����
	void leftRotate(RBTNode<T>* &root, RBTNode<T>* x);
	// ����
	void rightRotate(RBTNode<T>* &root, RBTNode<T>* y);
	// ���뺯��
	void insert(RBTNode<T>* &root, RBTNode<T>* node);
	// ������������
	void insertFixUp(RBTNode<T>* &root, RBTNode<T>* node);
	// ɾ������
	void remove(RBTNode<T>* &root, RBTNode<T> *node);
	// ɾ����������
	void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node);

	// ���ٺ����
	void destroy(RBTNode<T>* &tree);

	// ��ӡ�����
	void print(RBTNode<T>* tree, T key, int direction);

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};

template<class T>
RBTree<T>::RBTree() :mRoot(NULL)
{
	mRoot = NULL;
}

template<class T>
RBTree<T>::~RBTree()
{
	destroy();
}

template<class T>
void RBTree<T>::preOrder(RBTNode<T> *tree) const
{
	if (tree)
	{
		cout << tree->key << " ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

template<class T>
void RBTree<T>::preOrder()
{
	preOrder(mRoot);
}

template<class T>
void RBTree<T>::inOrder(RBTNode<T> *tree) const
{
	if (tree)
	{
		inOrder(tree->left);
		cout << tree->key << " ";
		inOrder(tree->right);
	}
}

template<class T>
void RBTree<T>::inOrder()
{
	inOrder(mRoot);
}

template<class T>
void RBTree<T>::postOrder(RBTNode<T> *tree) const
{
	if (tree)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->key << " ";
	}
}


template<class T>
void RBTree<T>::postOrder()
{
	postOrder(mRoot);
}

template<class T>
RBTNode<T>* RBTree<T>::search(RBTNode<T> *x, T key) const
{
	if (x == NULL || x->key == key)
		return x;
	if (key < x->key)
		return search(x->left, key);
	else
		return search(x->right, key);
}

template<class T>
RBTNode<T>* RBTree<T>::search(T key)
{
	search(mRoot, key);
}

template<class T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T> *x, T key) const
{
	while (x&&x->key != key)
	{
		if (key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

template<class T>
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
	iterativeSearch(mRoot, key);
}

template<class T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T> *tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->left)
	{
		tree = tree->left;
	}
	return tree;
}

template<class T>
T RBTree<T>::minimum()
{
	RBTNode<T> *p = minimum(mRoot);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}

template<class T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T> *tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->right)
		tree = tree->right;
	return tree;
}

template<class T>
T RBTree<T>::maximum()
{
	RBTNode<T> *p = maximum(mRoot);
	if (p != NULL)
		return p->key;
	return (T)NULL;
}

template<class T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T> *x)
{
	if (x->right)
		return minimum(x->right);
	RBTNode<T> *y = x->parent;
	while (y&&y->right == x)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

template<class T>
RBTNode<T>* RBTree<T>::predecessor(RBTNode<T> *x)
{
	if (x->left)
		return maximum(x->left);
	RBTNode<T> *y = x->parent;
	while (y&&y->left == x)
	{
		x = y;
		y = y->parent;
	}
	return y;
}

template<class T>
void RBTree<T>::leftRotate(RBTNode<T> *&root, RBTNode<T> *x)
{
	RBTNode<T> *y = x->right;
	x->right = y->left;
	if (y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		root = y;
	else
	{
		if (x = x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	x->parent = y;
	y->left = x;
}

template<class T>
void RBTree<T>::rightRotate(RBTNode<T> *&root, RBTNode<T> *x)
{
	RBTNode<T> *y = x->left;
	x->left = y->right;
	if (y->right)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		root = y;
	else
	{
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	y->right = x;
	x->parent = y;
}

template<class T>
void RBTree<T>::insertFixUp(RBTNode<T> *&root, RBTNode<T>* node)
{
	RBTNode<T> *parent, *gparent;
	while ((parent = rb_parent(node)) && rb_is_red(parent))
	{
		gparent = rb_parent(parent);
		if (parent == gparent->left)
		{
			RBTNode<T> *uncle = gparent->right;
			if (uncle&&rb_is_red(uncle))
			{
				rb_set_black(parent);
				rb_set_black(uncle);
				rb_set_red(gparent);
				node = gparent;
				continue;
			}
			else
			{
				if (node == parent->right)
				{
					leftRotate(root, parent);
					RBTNode<T> *tmp = parent;
					parent = node;
					node = tmp;
				}
				rb_set_black(parent);
				rb_set_red(gparent);
				rightRotate(root, gparent);
			}
		}
		else
		{
			RBTNode<T> *uncle = gparent->left;
			if (uncle&&rb_is_red(uncle))
			{
				rb_set_black(parent);
				rb_set_black(uncle);
				rb_set_red(gparent);
				node = gparent;
				continue;
			}
			else
			{
				if (node == parent->left)
				{
					rightRotate(root, parent);
					RBTNode<T> *tmp = parent;
					parent = node;
					node = tmp;
				}
				rb_set_black(parent);
				rb_set_red(gparent);
				leftRotate(root, gparent);
			}
		}
	}
	rb_set_black(root);
}

template <class T>
void RBTree<T>::insert(RBTNode<T>* &root, RBTNode<T>* node)
{
	RBTNode<T> *y = NULL;
	RBTNode<T> *x = root;

	// 1. �����������һ�Ŷ�������������ڵ���ӵ�����������С�
	while (x != NULL)
	{
		y = x;
		if (node->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	node->parent = y;
	if (y != NULL)
	{
		if (node->key < y->key)
			y->left = node;
		else
			y->right = node;
	}
	else
		root = node;

	// 2. ���ýڵ����ɫΪ��ɫ
	node->color = RED;

	// 3. ������������Ϊһ�Ŷ��������
	insertFixUp(root, node);
}


template <class T>
void RBTree<T>::insert(T key)
{
	RBTNode<T> *z = NULL;

	// ����½����ʧ�ܣ��򷵻ء�
	if ((z = new RBTNode<T>(key, BLACK, NULL, NULL, NULL)) == NULL)
		return;

	insert(mRoot, z);
}

template<class T>
void RBTree<T>::removeFixUp(RBTNode<T> *&root, RBTNode<T>* node)
{
	while (node != root&&rb_is_black(node))
	{
		RBTNode<T> *parent = rb_parent(node);
		if (node == parent->left)
		{
			RBTNode<T> *other = parent->right;
			if (rb_is_red(other))
			{
				rb_set_black(other);
				rb_set_red(parent);
				rightRotate(root, parent);
				other = parent->right;
			}
			if (rb_is_black(other->left) && rb_is_black(other->right))
			{
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (rb_is_black(other->right))
				{
					rb_set_black(other->left);
					rb_set_red(other);
					rightRotate(root, other);
					other = parent->right;
				}
				rb_set_color(other, rb_color(parent));
				rb_set_black(other->right);
				rb_set_black(parent);
				leftRotate(root, parent);
				node = root;
			}
		}
		else
		{
			RBTNode<T> *other = parent->left;
			if (rb_is_red(other))
			{
				rb_set_black(other);
				rb_set_red(parent);
				rightRotate(root, parent);
				other = parent->left;
			}
			if (rb_is_black(other->left) && rb_is_black(other->right))
			{
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (rb_is_black(other->left))
				{
					rb_set_black(other->right);
					rb_set_red(other);
					leftRotate(root, other);
					other = parent->left;
				}
				rb_set_color(other, rb_color(parent));
				rb_set_black(other->left);
				rb_set_black(parent);
				rightRotate(root, parent);
				node = root;
			}
		}
	}
	rb_set_black(node);
}

template<class T>
void RBTree<T>::remove(RBTNode<T> *&root, RBTNode<T> *node)
{
	RBTNode<T> *pnode, *rnode;
	if (node->left == NULL || node->right == NULL)
		pnode = node;
	else
		pnode = successor(node);
	if (pnode->left)
		rnode = pnode->left;
	else
		rnode = pnode->right;
	rnode->parent = pnode->parent;
	if (pnode->parent == NULL)
		root = rnode;
	else
	{
		if (pnode == pnode->parent->left)
			pnode->parent->left = rnode;
		else
			pnode->parent->right = rnode;
	}
	if (node != pnode)
	{
		node->key = pnode->key;
	}
	if (pnode->color == BLACK)
		removeFixUp(root, rnode);
	delete pnode;
	return;
}

template<class T>
void RBTree<T>::remove(T key)
{
	RBTNode<T> *node;
	if ((node = search(mRoot, key)) != NULL)
		remove(mRoot, node);
}

template<class T>
void RBTree<T>::destroy(RBTNode<T> *&tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		return destroy(tree->left);
	if (tree->right != NULL)
		return destroy(tree->left);
	delete tree;
	tree = NULL;
}

template <class T>
void RBTree<T>::destroy()
{
	destroy(mRoot);
}

template<class T>
void RBTree<T>::print(RBTNode<T> *tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)
			cout << setw(2) << tree->key << "(B) is root" << endl;
		else
			cout << setw(2) << tree->key << (rb_is_red(tree) ? "(R)" : "(B)") << " is " << setw(2)
			<< key << "'s " << setw(12) << (direction == 1 ? "right child" : "left child") << endl;
		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}

template<class T>
void RBTree<T>::print()
{
	if (mRoot)
		print(mRoot, mRoot->key, 0);
}
