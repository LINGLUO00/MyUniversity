#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_kv(kv)
		,_col(RED)
	{}
};

template<class K,class V>
struct AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;

			}
			else
			{
				return false;
			}

		}
		cur = new Node(key);
		if (parent->_kv.first < key)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL();
				}

				// 1、旋转让这颗子树平衡了
				// 2、旋转降低了这颗子树的高度，恢复到跟插入前一样的高度，所以对上一层没有影响，不用继续更新
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}





		void RotateL(Node * parent)
		{
			Node* subR = parent -> _right;
			Node* subRL = subR -> _left;

			parent->_right = subRL;
			subR->_left = parent;

			Node* parentParent = parent->_parent;

			parent->_parent = subR;
			if(subRL)
				subR->_parent = parent;
			if (_root == parent)
			{
				_root = subR;
				subR -> _parent = nullptr;
			}
			else
			{
				if (parentParent->_left == parent)
				{
					parentParent->_left = subR;
				}
				else
				{
					parentParent->_right = subR;
				}
				subR->_parent = parentParent;
			}
			parent->_bf = subR->_bf = 0;
		}




		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;

			Node* parentParent = parent->_parent;

			subL->_right = parent;
			parent->_parent = subL;

			if (_root == parent)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				if (parentParent->_left == parent)
				{
					parentParent->_left = subL;
				}
				else
				{
					parentParent->_right = subL;
				}

				subL->_parent = parentParent;
			}

			subL->_bf = parent->_bf = 0;
		}




		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			int bf = subRL->_bf;
			RotateR(parent->_right);
			RotateL(parent);
			if (bf == 0)
			{
				parent->_bf = subR->_bf = subRL->_bf = 0;
			}
			else if (bf == -1)
			{
				parent->_bf = 0;
				subRL->_bf = 0;
				subR->_bf = 1;
			}
			else if (bf == 1)
			{
				parent->_bf = -1;
				subRL->_bf = 0;
				subR->_bf = 0;
			}
			else
			{

			}
		}

private:
	Node* _root = nullptr;

};