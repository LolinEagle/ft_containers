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
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef T*										iterator;
			typedef const T*								const_iterator;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef T										value_type;
			typedef Allocator								allocator_type;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef std::reverse_iterator<iterator>			reverse_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
		private:
			iterator	_value;
			size_type	_size;
			size_type	_capacity;
		public:
			/* Constructor & Destructor ************************************* */
			explicit vector(const Allocator& alloc = Allocator());
			explicit vector(size_type n, const T& value = T(),
			const Allocator& = Allocator());
			// template <class InputIterator>
			// vector(InputIterator first, InputIterator last,
			// const Allocator& = Allocator());
			vector(const vector<T,Allocator>& x);
			~vector();
			vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last);
			void assign(size_type n, const T& u);
			allocator_type get_allocator() const;

			/* Iterators **************************************************** */
			iterator begin(){return(_value);}
			const_iterator begin() const{return(_value);}
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			/* Capacity ***************************************************** */
			size_type size() const{return(_size);}
			size_type max_size() const{return(_capacity);}
			void resize(size_type sz, T c = T());
			size_type capacity() const;
			bool empty() const;
			void reserve(size_type n);

			/* Element access *********************************************** */
			reference operator[](size_type n){return (_value[n]);}
			const_reference operator[](size_type n) const{return (_value[n]);}
			const_reference at(size_type n) const;
			reference at(size_type n);
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;

			/* Modifiers **************************************************** */
			void push_back(const T& x);
			void pop_back();
			iterator insert(iterator position, const T& x);
			void insert(iterator position, size_type n, const T& x);
			template <class InputIterator>
			void insert(iterator position,
			InputIterator first, InputIterator last);
			iterator erase(iterator position);
			iterator erase(iterator first, iterator last);
			void swap(vector<T,Allocator>&);
			void clear();
	};

	/* Constructor & Destructor ********************************************* */

	template<class T, class Allocator>
	vector<T, Allocator>::vector(const Allocator& alloc)
	: _value(NULL), _size(0), _capacity(alloc.max_size())
	{
	}

	template<class T, class Allocator>
	vector<T, Allocator>::vector(size_type n, const T& value, const Allocator& alloc)
	: _value(new T[n]), _size(n), _capacity(alloc.max_size())
	{
		for (size_t i = 0; i < n; i++)
			_value[i] = value;
	}

	template<class T, class Allocator>
	vector<T, Allocator>::vector(const vector<T, Allocator> &copy)
	{
		*this = copy;
	}

	template<class T, class Allocator>
	vector<T, Allocator>::~vector()
	{
		delete [] (_value);
	}

	template<class T, class Allocator>
	vector<T, Allocator> &vector<T, Allocator>::operator=(const vector<T, Allocator> &copy)
	{
		_value = new T[copy._size];
		for (size_t i = 0; i < copy._size; i++)
			_value[i] = copy._value[i];
		_size = copy._size;
		_capacity = copy._capacity;
		return (*this);
	}

	/* Iterators ************************************************************ */



	/* Capacity ************************************************************* */



	/* Modifiers ************************************************************ */



	/* Non-member function overloads **************************************** */

	// template <class T, class Allocator>
	// bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	// {
	// 	return (false);
	// }

	// template <class T, class Allocator>
	// bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	// {
	// 	return (false);
	// }

	// template <class T, class Allocator>
	// bool operator!=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	// {
	// 	return (false);
	// }

	// template <class T, class Allocator>
	// bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	// {
	// 	return (false);
	// }

	// template <class T, class Allocator>
	// bool operator>=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	// {
	// 	return (false);
	// }

	// template <class T, class Allocator>
	// bool operator<=(const vector<T,Allocator>& x, const vector<T,Allocator>& y)
	// {
	// 	return (false);
	// }

	// template <class T, class Allocator>
	// void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
	// {
	// }
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
