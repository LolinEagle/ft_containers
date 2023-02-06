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
		allocator_type get_allocator() const;

		/* Iterators ******************************************************** */
		iterator begin(){return(_begin);}
		const_iterator begin() const{return(_begin);}
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		/* Capacity ********************************************************* */
		size_type size() const{return(_size);}
		size_type max_size() const{return(_alloc.max_size());}
		void resize(size_type sz, T c = T());
		size_type capacity() const;
		bool empty() const;
		void reserve(size_type n);

		/* Element access *************************************************** */
		reference operator[](size_type n){return (_begin[n]);}
		const_reference operator[](size_type n) const{return (_begin[n]);}
		const_reference at(size_type n) const;
		reference at(size_type n){return (_begin[n]);}
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

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
		void swap(vector<T,Alloc>&);
		void clear();
};

/* Constructor & Destructor ************************************************* */

template<class T, class Alloc>
vector<T, Alloc>::vector(const Alloc& alloc)
: _alloc(alloc), _begin(NULL), _end(NULL), _size(0)
{
}

template<class T, class Alloc>
vector<T, Alloc>::vector(size_type n, const T& value, const Alloc& alloc)
: _alloc(alloc), _begin(NULL), _end(NULL), _size(n)
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
	for (size_t n = 0; n < copy._size; _end++)
		_alloc.construct(_end, *(copy._begin + n));
	_size = copy._size;
	return (*this);
}

/* Iterators **************************************************************** */



/* Capacity ***************************************************************** */

template<class T, class Alloc>
void vector<T, Alloc>::resize(size_type sz, T c)
{
	(void)sz;
	(void)c;
}

/* Element access *********************************************************** */



/* Modifiers **************************************************************** */

template<class T, class Alloc>
void push_back(const T& x)
{
	(void)x;
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
