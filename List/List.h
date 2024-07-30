#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
namespace YL
{
	template<class T>
	struct list_node
	{
		T data;
		list_node<T>* _next;
		list_node<T>* _prev;
		list_node(const T& x = T())
			:data(x)
			,_next(nullptr)
			,_prev(nullptr)
		{}

	};
	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		Node* _node;
		__list_iterator(Node* node)
			:_node(node)
		{}
		self& operator++ ()
		{
			_node = _node->_next;
			return *this;
		}



		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}
		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

		bool operator==(const self& s)//////’‚¿Ô
		{
			return _node == s._node;
		}



	};







	template<class T>
	class list
	{

	public:
		typedef list_node<T> Node;
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		const_iterator begin()const
		{
			return _head->_next;
		}
		const_iterator end()const
		{
			return _head;
		}
		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = nullptr;
			_head->_prev = nullptr;
			_size = 0;
		}
		list()
		{
			empty_init();
		}

		list(const list<T>& lt)
		{
			empty_init();
			for (auto e : lt)
			{
				push_back(e);
			}
		}
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}


		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}



		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
			_size = 0;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		iterator insert(iterator pos , const T& x)
		{
			Node* cur = pos->_node;
			Node* newnode = new Node(x);
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = newnode;
			newnode->_prev = prev;
			next->_prev = newnode;
			newnode->_next = next;
			_size++;
			return iterator(next);



		}
		iterator erase(iterator pos)
		{
			Node* prev = pos->_node->_prev;
			Node* next = pos->_node->_next;
			delete pos->_node;

			next = prev->_next;
			prev = next->_prev;
			_size--;

			return iterator(next);

		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			erase(begin());
		}

		void pop_back()
		{
			erase(--end());
		}
		size_t size()
		{
			return _size;
		}
	private:
		Node* _head;
		size_t _size;

	};
}