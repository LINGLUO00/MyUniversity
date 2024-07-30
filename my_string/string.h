#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<assert.h>
namespace YL
{
	
	class string
	{
	public:
		string(const char* str = "")
			: _size(strlen(str))
			,_capacity(_size)
		{
			_str = (new char[_capacity + 1]);
			strcpy(_str, str);
		
		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}
		string(const string& s)
			:_str(nullptr)
			,_size(0)
			,_capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}
		~string()
		{
			delete[]_str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		size_t size()const
		{
			return _size;
		}
		const char* c_str()const
		{
			return _str;
		}
		void reserve(size_t n)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
			_capacity = n;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}
		void resize(int n, char x)
		{
			if (n <= _size)
			{
				_str[n] = '\0';
				_size = n;

			}
			else
			{
				reserve(n);
				while (_size < n)
				{
					_str[_size] = x;
					_size++;
				}
				_str[_size] = '\0';
			}
		}
		size_t find(char ch, size_t pos = 0)
		{
			for (int i = 0; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* ch, size_t pos = 0)
		{
			const char* p = strstr(_str + pos, ch);
			if (p)
			{
				return p - _str;

			}
			else
			{
				return npos;
			}
		}
		string substr(size_t pos, size_t len = npos)
		{
			string s;
			size_t end = len + pos;
			if (len == npos || len + pos > _size)
			{
				len = _size - pos;
				end = _size;
			}
			s.reserve(len);
			for (size_t i = pos; i < end; i++)
			{
				s += _str[i];
			}
			return s;
		}
		void push_back(char x)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);

			}
			_str[_size++] = x;
			_str[_size] = '\0';

		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);

			}
			strcpy(_str + _size, str);
			_size += len;
		}
		string& operator+=(const char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* sub)
		{
			append(sub);
			return *this;
		}
		string& operator=(string tmp)
		{
			swap(tmp);
			return *this;
		}
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}
		size_t capacity()
		{
			return _capacity;
		}

		size_t size()
		{
			return _size;
		}
		const char* c_str()
		{
			return _str;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size;
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];
				end--;
			}
			strncpy(_str + pos, str, len);
			_size += len;
		}
		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end ] = _str[end - 1];
				end--;
			}
			_str[pos] = ch;
			_size++;
		}
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos <= _size);
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t begin = pos + len;
				while (begin <= _size)
				{
					_str[begin - len] = _str[begin];
					begin++;
				}
				_size = _size - len;
			}
		}
		

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		bool operator<(const string& s) const

		{

			return strcmp(_str, s._str) < 0;

		}

		bool operator==(const string& s) const

		{

			return strcmp(_str, s._str) == 0;

		}

		bool operator<=(const string& s) const

		{

			return *this < s || *this == s;

		}

		bool operator>(const string& s) const

		{

			return !(*this <= s);

		}

		bool operator>=(const string& s) const

		{

			return !(*this < s);

		}

		bool operator!=(const string& s) const

		{

			return !(*this == s);

		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		const static size_t npos = 1;

	};



}