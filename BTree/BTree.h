#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
template<class K,size_t M>
struct BTreeNode
{
	K _keys[M];
	BTreeNode<K, M>* _subs[M + 1];
	BTreeNode<K, M>* _parent;
	size_t _n;//record how many keys are actually stored
	BTreeNode()
	{
		for (size_t i = 0; i < M; i++)
		{
			_keys[i] = K();
			_subs[i] = nullptr;
		}
		_subs[M] = nullptr;
		_n = 0;
		_parent = nullptr;

	}
};

template<class K, size_t M>
class BTree
{
	typedef BTreeNode<K, M> Node;
public:
	pair<Node*, int> Find(const K& key)
	{
		int i = 0;
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			while (i < cur->_n)
			{
				if (key < cur->_keys[i])
				{
					break;
				}
				else if (key > cur->_keys[i])
				{
					i++;
				}
				else
				{
					return make_pair(cur, i);
				}
			}
			parent = cur;
			cur = cur->_subs[i];
		}
		return make_pair (parent, -1);
	}
	void InsertKey(Node* node, const K& key, Node* child)
	{
		int end = node->_n - 1;
		while (end >= 0)
		{
			if (key < node->_keys[end])
			{
				node->_keys[end + 1] = node->_keys[end];
				node->_subs[end + 2] = node->_subs[end + 1];
				end--;
			}
			else
			{
				break;
			}
		}
		node->_keys[end + 1] = key;
		node->_subs[end + 2] = child;
		if (child)
		{
			child->_parent = node;
		}
		node->_n++;
	}
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node;
			_root->_keys[0] = key;
			_root->_n++;
			return true;
		}

		//if the key already exists,insertion is not allowed
		pair<Node*, int> ret = Find(key);
		if (ret.second >= 0)
		{
			return false;
		}

		//if the key is not find ,use the returned leaf node
		Node* parent = ret.first;
		Node* child = nullptr;
		K newKey = key;
		while (1)
		{
			InsertKey(parent, newKey, child);
			if (parent->_n < M)
			{
				return true;
			}
			else
			{
				size_t mid = M / 2;
				Node* brother = new Node;
				size_t i = mid + 1;
				size_t j = 0;
				for (; i < M; i++)
				{
					brother->_keys[j] = parent->_keys[i];
					brother->_subs[j] = parent->_subs[i];
					brother->_n++;
					if (parent->_subs[i])
					{
						parent->_subs[i]->_parent = brother;
					}
					j++;
					parent->_keys[i] = K();
					parent->_subs[i] = nullptr;
				}
				//copy the last right child
				brother->_subs[j] = parent->_subs[i];
				if (parent->_subs[i])
				{
					parent->_subs[i]->_parent = brother;
				}
				parent->_subs[i] = nullptr;

				brother->_n = j;
				parent->_n -= (brother->_n + 1);

				K midKey = parent->_keys[mid];
				parent->_keys[mid] = K();
				if (parent->_parent == nullptr)
				{
					_root = new Node;
					_root->_keys[0] = midKey;
					_root->_subs[0] = parent;
					_root->_subs[1] = brother;
					_root->_n++;
					parent->_parent = _root;
					brother->_parent = _root;
					break;
				}
				else
				{
					newKey = midKey;
					parent = parent->_parent;
					child = brother;
				}

			}

		}
		return true;
	}
	void _Inorder(Node* cur)
	{
		if (cur == nullptr)
			return;
		int i = 0;
		for (; i < cur->_n; i++)
		{
			_Inorder(cur->_subs[i]);
			cout << cur->_keys[i] << " ";
		}
		_Inorder(cur->_subs[i]);
	}
	void Inorder()
	{
		_Inorder(_root);
	}
private:
	Node* _root = nullptr;
};