/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:22:00 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/30 11:22:01 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace ft
{
template<class T, class Alloc = std::allocator<T> > class vector
{
	public:
		typedef typename Alloc::reference				reference;
		typedef typename Alloc::const_reference			const_reference;
		typedef T*										iterator;
		typedef const T*								const_iterator;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef T										value_type;
		typedef Alloc									allocator_type;
		typedef typename Alloc::pointer					pointer;
		typedef typename Alloc::const_pointer			const_pointer;
		typedef std::reverse_iterator<iterator>			reverse_iterator;
		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
	private:
		allocator_type	_alloc;
		iterator		_begin;
		iterator		_end;
		size_type		_size;
		size_type		_capacity;
	public:
		/* Constructor & Destructor ***************************************** */
		explicit vector(const Alloc& alloc = Alloc());
		explicit vector(size_type n, const T& value = T(),
		const Alloc& = Alloc());
		// template <class InputIterator>
		// vector(InputIterator first, InputIterator last,
		// const Alloc& = Alloc());
		vector(const vector<T,Alloc>& x);
		~vector();
		vector<T,Alloc>& operator=(const vector<T,Alloc>& x);
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
		void assign(size_type n, const T& u);
		allocator_type get_allocator() const{return(_alloc);}

		/* Iterators ******************************************************** */
		iterator begin(){return(_begin);}
		const_iterator begin() const{return(_begin);}
		iterator end(){return(_end);}
		const_iterator end() const{return(_end);}
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		/* Capacity ********************************************************* */
		size_type size() const{return(_size);}
		size_type max_size() const{return(_alloc.max_size());}
		void resize(size_type new_size, T c = T());
		size_type capacity() const{return(_capacity);}
		bool empty() const;
		void reserve(size_type n);

		/* Element access *************************************************** */
		reference operator[](size_type n){return (_begin[n]);}
		const_reference operator[](size_type n) const{return (_begin[n]);}
		const_reference at(size_type n) const{return (_begin[n]);}
		reference at(size_type n){return (_begin[n]);}
		reference front(){return(*_begin);}
		const_reference front() const{return(*_begin);}
		reference back(){return(*(_end - 1));}
		const_reference back() const{return(*(_end)- 1);}

		/* Modifiers ******************************************************** */
		void push_back(const T& x);
		void pop_back();
		iterator insert(iterator position, const T& x);
		void insert(iterator position, size_type n, const T& x);
		template <class InputIterator>
		void insert(iterator position,
		InputIterator first, InputIterator last);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap(vector<T,Alloc>& x);
		void clear();
};

/* Constructor & Destructor ************************************************* */

template<class T, class Alloc>
vector<T, Alloc>::vector(const Alloc& alloc)
: _alloc(alloc), _begin(NULL), _end(NULL), _size(0), _capacity(0)
{
}

template<class T, class Alloc>
vector<T, Alloc>::vector(size_type n, const T& value, const Alloc& alloc)
: _alloc(alloc), _begin(NULL), _end(NULL), _size(n), _capacity(n)
{
	_begin = _alloc.allocate(n);
	_end = _begin;
	for (; n--; _end++)
		_alloc.construct(_end, value);
}

template<class T, class Alloc>
vector<T, Alloc>::vector(const vector<T, Alloc> &copy)
{
	*this = copy;
}

template<class T, class Alloc>
vector<T, Alloc>::~vector()
{
	_alloc.deallocate(_begin, _size);
}

template<class T, class Alloc>
vector<T, Alloc> &vector<T, Alloc>::operator=(const vector<T, Alloc> &copy)
{
	_alloc = copy._alloc;
	_begin = _alloc.allocate(copy._size);
	_end = _begin;
	for (size_type n = 0; n < copy._size; n++)
	{
		_alloc.construct(_end, *(copy._begin + n));
		_end++;
	}
	_size = copy._size;
	_capacity = copy._capacity;
	return (*this);
}

template<class T, class Alloc>
void vector<T, Alloc>::assign(size_type n, const T& u)
{
	_alloc.deallocate(_begin, _size);
	_size = n;
	_capacity = n;
	_begin = _alloc.allocate(n);
	_end = _begin;
	for (; n--; _end++)
		_alloc.construct(_end, u);
}

/* Iterators **************************************************************** */

template<class T, class Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
{
	return(static_cast<reverse_iterator>(_end));
}

template<class T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator
vector<T, Alloc>::rbegin() const
{
	return(static_cast<const_reverse_iterator>(_end));
}

template<class T, class Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
{
	return(static_cast<reverse_iterator>(_begin));
}

template<class T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator
vector<T, Alloc>::rend() const
{
	return(static_cast<const_reverse_iterator>(_begin));
}

/* Capacity ***************************************************************** */

template<class T, class Alloc>
void vector<T, Alloc>::resize(size_type new_size, T c)
{
	if (_size == new_size)
		return ;
	iterator	new_begin = _alloc.allocate(new_size);
	iterator	new_end = new_begin;
	size_type	i;

	for (i = 0; i < new_size && i < _size; i++)
		_alloc.construct(new_end++, *(_begin + i));
	for (; i < new_size; i++)
		_alloc.construct(new_end++, c);
	_alloc.deallocate(_begin, _size);
	_begin = new_begin;
	_end = new_end;
	_size = new_size;
	_capacity = new_size;

}

template<class T, class Alloc>
bool vector<T, Alloc>::empty() const
{
	if (_size == 0)
		return (true);
	return (false);
}

template<class T, class Alloc>
void vector<T, Alloc>::reserve(size_type n)
{
	if (_size >= n)
		return ;
	iterator	new_begin = _alloc.allocate(n);
	iterator	new_end = new_begin;
	size_type	i;

	for (i = 0; i < _size; i++)
		_alloc.construct(new_end++, *(_begin + i));
	_alloc.deallocate(_begin, _size);
	_begin = new_begin;
	_end = new_end;
	_capacity = n;
}

/* Element access *********************************************************** */



/* Modifiers **************************************************************** */

template<class T, class Alloc>
void vector<T, Alloc>::push_back(const T& x)
{
	iterator	new_begin = _alloc.allocate(_size + 1);

	_end = new_begin;
	for (size_type n = 0; n < _size; n++)
	{
		_alloc.construct(_end, *(_begin + n));
		_end++;
	}
	_alloc.construct(_end, x);
	_end++;
	_alloc.deallocate(_begin, _size);
	_begin = new_begin;
	_size++;
	_capacity++;
}

template<class T, class Alloc>
void vector<T, Alloc>::pop_back()
{
	iterator	new_begin = _alloc.allocate(_size - 1);

	_end = new_begin;
	for (size_type n = 0; n < _size - 1; n++)
	{
		_alloc.construct(_end, *(_begin + n));
		_end++;
	}
	_alloc.deallocate(_begin, _size);
	_begin = new_begin;
	_size--;
	_capacity--;
}

template<class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator position,
const T& x)
{
	iterator	new_begin = _alloc.allocate(_size + 1);
	iterator	new_end = new_begin;
	iterator	ret;

	for (iterator it = _begin; it != position; it++)
		_alloc.construct(new_end++, *it);
	ret = new_end;
	_alloc.construct(new_end, x);
	new_end++;
	for (; position != _end; position++)
		_alloc.construct(new_end++, *position);
	_alloc.deallocate(_begin, _size);
	_begin = new_begin;
	_end = new_end;
	_size++;
	_capacity++;
	return (ret);
}

template<class T, class Alloc>
void vector<T, Alloc>::insert(iterator position, size_type n, const T& x)
{
	iterator	new_begin = _alloc.allocate(_size + n);
	iterator	new_end = new_begin;

	for (iterator it = _begin; it != position; it++)
		_alloc.construct(new_end++, *it);
	for (size_type i = 0; i < n; i++)
		_alloc.construct(new_end++, x);
	for (; position != _end; position++)
		_alloc.construct(new_end++, *position);
	_alloc.deallocate(_begin, _size);
	_begin = new_begin;
	_end = new_end;
	_size += n;
	_capacity += n;
}

template<class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
{
	iterator	new_begin = _alloc.allocate(_size - 1);
	iterator	new_end = new_begin;
	iterator	ret;

	for (iterator it = _begin; it != position; it++)
		_alloc.construct(new_end++, *it);
	ret = new_end;
	position++;
	for (; position != _end; position++)
		_alloc.construct(new_end++, *position);
	_alloc.deallocate(_begin, _size);
	_begin = new_begin;
	_end = new_end;
	_size--;
	_capacity--;
	return (ret);
}

template<class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first,
iterator last)
{
	iterator	new_begin = _alloc.allocate(_size - (last - first));
	iterator	new_end = new_begin;
	iterator	ret;
	iterator	position;

	for (iterator it = _begin; it != first; it++)
		_alloc.construct(new_end++, *it);
	ret = new_end;
	position = first + 1;
	for (; position != last; position++)
		_alloc.construct(new_end++, *position);
	_alloc.deallocate(_begin, _size);
	_begin = new_begin;
	_end = new_end;
	_size -= last - first;
	_capacity -= last - first;
	return (ret);
}

template<class T, class Alloc>
void vector<T, Alloc>::swap(vector<T,Alloc>& x)
{
	(void)x;
}

template<class T, class Alloc>
void vector<T, Alloc>::clear()
{
	while (_size != 0)
		pop_back();
}

/* Non-member function overloads ******************************************** */

template <class T, class Alloc>
bool operator==(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
{
	if (x == y)
		return (true);
	return (false);
}

template <class T, class Alloc>
bool operator< (const vector<T,Alloc>& x, const vector<T,Alloc>& y)
{
	if (x < y)
		return (true);
	return (false);
}

template <class T, class Alloc>
bool operator!=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
{
	if (x != y)
		return (true);
	return (false);
}

template <class T, class Alloc>
bool operator> (const vector<T,Alloc>& x, const vector<T,Alloc>& y)
{
	if (x > y)
		return (true);
	return (false);
}

template <class T, class Alloc>
bool operator>=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
{
	if (x >= y)
		return (true);
	return (false);
}

template <class T, class Alloc>
bool operator<=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
{
	if (x <= y)
		return (true);
	return (false);
}

template <class T, class Alloc>
void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	(void)x;
	(void)y;
}
}

#endif
