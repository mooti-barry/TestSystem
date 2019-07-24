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
	T key; //关键字
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
		
	//前序遍历
	void preOrder();
	//中序遍历
	void inOrder();
	//后续遍历
	void postOrder();
	
	//递归实现查找红黑树中值为Key的节点
	RBTNode<T>* search(T key);
	//非递归实现查找红黑树中值为key的节点
	RBTNode<T>* iterativeSearch(T key);

	//找到最小节点并返回键值
	T minimum();
	//找到最大节点并返回键值
	T maximum();

	//找到节点x的后继节点。即：找到"红黑树中数值大于该节点"的"最小节点"。
	RBTNode<T>* successor(RBTNode<T>* x);
	//找到节点x的前驱节点。即：查找"红黑树中数值小于该结点"的"最大结点"。
	RBTNode<T>* predecessor(RBTNode<T>* x);

	//将节点（key为节点键值）插入红黑树中
	void insert(T key);

	//删除节点（key为节点键值）
	void remove(T key);

	//销毁红黑树
	void destroy();

	//打印红黑树
	void print();

private:
	//前序遍历红黑树
	void preOrder(RBTNode<T>* tree) const;
	//中序遍历红黑树
	void inOrder(RBTNode<T>* tree) const;
	//后续遍历红黑树
	void postOrder(RBTNode<T>* tree) const;

	// (递归实现)查找"红黑树x"中键值为key的节点
	RBTNode<T>* search(RBTNode<T>* x, T key) const;
	// (非递归实现)查找"红黑树x"中键值为key的节点
	RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;

	// 查找最小结点：返回tree为根结点的红黑树的最小结点。
	RBTNode<T>* minimum(RBTNode<T>* tree);
	// 查找最大结点：返回tree为根结点的红黑树的最大结点。
	RBTNode<T>* maximum(RBTNode<T>* tree);

	// 左旋
	void leftRotate(RBTNode<T>* &root, RBTNode<T>* x);
	// 右旋
	void rightRotate(RBTNode<T>* &root, RBTNode<T>* y);
	// 插入函数
	void insert(RBTNode<T>* &root, RBTNode<T>* node);
	// 插入修正函数
	void insertFixUp(RBTNode<T>* &root, RBTNode<T>* node);
	// 删除函数
	void remove(RBTNode<T>* &root, RBTNode<T> *node);
	// 删除修正函数
	void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node);

	// 销毁红黑树
	void destroy(RBTNode<T>* &tree);

	// 打印红黑树
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

	// 1. 将红黑树当作一颗二叉查找树，将节点添加到二叉查找树中。
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

	// 2. 设置节点的颜色为红色
	node->color = RED;

	// 3. 将它重新修正为一颗二叉查找树
	insertFixUp(root, node);
}


template <class T>
void RBTree<T>::insert(T key)
{
	RBTNode<T> *z = NULL;

	// 如果新建结点失败，则返回。
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
