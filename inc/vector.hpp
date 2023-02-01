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
	template<class T, class Allocator = std::allocator<T> > class vector
	{
		public:
			// Member types
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::pointer			iterator;
			typedef typename allocator_type::const_pointer		const_iterator;
			// everse_iterator;
			// const_reverse_iterator;
			typedef std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;
		private:
			value_type	*_value;
			size_type	_size;
			size_type	_max_size;
		public:
			// Constructor & Destructor
			vector(void);
			vector(const vector &copy);
			~vector();

			// Operator overload
			vector		&operator=(const vector &copy);
			value_type	&operator[](size_type i);

			// Iterators

			// Capacity
			size_type	size() const{return(_size);}
			size_type	max_size() const{return(_max_size);}

			// Element access

			// Modifiers
			
			// Allocator
	};

	template<class T, class Alloc>
	vector<T, Alloc>::vector(void) : _value(NULL), _size(0), _max_size(0)
	{
	}

	template<class T, class Alloc>
	vector<T, Alloc>::vector(const vector<T, Alloc> &copy)
	{
		*this = copy;
	}

	template<class T, class Alloc> vector<T, Alloc>::~vector()
	{
		delete [] (_value);
	}

	template<class T, class Alloc>
	vector<T, Alloc> &vector<T, Alloc>::operator=(const vector<T, Alloc> &copy)
	{
		_value = new T[copy._size];
		for (size_t i = 0; i < copy._size; i++)
			_value[i] = copy._value[i];
		_size = copy._size;
		_max_size = copy._max_size;
		return (*this);
	}

	template<class T, class Alloc> typename vector<T, Alloc>::value_type
	&vector<T, Alloc>::operator[](size_type i)
	{
		return (_value[i]);
	}

	/* Non-member function overloads **************************************** */

	template <class T, class Allocator>
	bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		(void)x, y;
		return (false);
	}

	template <class T, class Allocator>
	bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		(void)x, y;
		return (false);
	}

	template <class T, class Allocator>
	bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		(void)x, y;
		return (false);
	}

	template <class T, class Allocator>
	bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		(void)x, y;
		return (false);
	}

	template <class T, class Allocator>
	bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		(void)x, y;
		return (false);
	}

	template <class T, class Allocator>
	bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	{
		(void)x, y;
		return (false);
	}

	template <class T, class Allocator>
	void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
	{
		(void)x, y;
		return ;
	}
}

#endif

/* To do: */

/* Member functions: */
// (constructor) 2 / 4

/* Iterators: */
// begin
// end
// rbegin
// rend

/* Capacity: */
// resize
// capacity
// empty
// reserve

/* Element access: */
// operator[]
// at
// front
// back

/* Modifiers: */
// assign
// push_back
// pop_back
// insert
// erase
// swap
// clear

/* Allocator: */
// get_allocator

/* Non-member function overloads: */
// relational operators
// swap
