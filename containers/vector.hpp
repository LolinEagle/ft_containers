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

#include <ft_containers.hpp>

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
		typedef std::random_access_iterator_tag			iterator_category;
	private:
		allocator_type	_alloc;
		iterator		_begin;
		size_type		_size;
		size_type		_capacity;
	public:
		/* Constructor & Destructor ***************************************** */
		explicit vector(const Alloc& alloc = Alloc());
		explicit vector(size_type n, const T& value = T(),
		const Alloc& alloc = Alloc());
		template<class InputIt>
		vector(InputIt first, InputIt last, const Alloc& alloc = Alloc(),
		typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type*
		= NULL)
		{
			_alloc = alloc;
			_size = last - first;
			_capacity = _size;
			_begin = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_begin + i, *(first + i));
		}
		vector(const vector<T,Alloc>& x);
		~vector();
		vector<T,Alloc>& operator=(const vector<T,Alloc>& x);
		template<class InputIt>
		void assign(InputIt first, InputIt last,
		typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type*
		= NULL)
		{
			size_type	new_size = last - first;
			iterator	new_begin = _alloc.allocate(new_size);
			
			for (size_type i = 0; i < new_size; i++)
				_alloc.construct(new_begin + i, *(first + i));
			_alloc.deallocate(_begin, _size);
			_begin = new_begin;
			_size = new_size;
			_capacity = new_size;
		}
		void assign(size_type n, const T& u);
		allocator_type get_allocator() const{return(_alloc);}

		/* Iterators ******************************************************** */
		iterator begin(){return(_begin);}
		const_iterator begin() const{return(_begin);}
		iterator end(){return(_begin + _size);}
		const_iterator end() const{return(_begin + _size);}
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
		reference operator[](size_type n)
		{
			if (n < 0 || n >= _size)
				throw (std::out_of_range("out of range exception"));
			return (_begin[n]);
		}
		const_reference operator[](size_type n) const
		{
			if (n < 0 || n >= _size)
				throw (std::out_of_range("out of range exception"));
			return (_begin[n]);
		}
		const_reference at(size_type n) const
		{
			if (n < 0 || n >= _size)
				throw (std::out_of_range("out of range exception"));
			return (_begin[n]);
		}
		reference at(size_type n)
		{
			if (n < 0 || n >= _size)
				throw (std::out_of_range("out of range exception"));
			return (_begin[n]);
		}
		reference front(){return(*_begin);}
		const_reference front() const{return(*_begin);}
		reference back(){return(*(_begin + _size - 1));}
		const_reference back() const{return(*(_begin + _size - 1));}

		/* Modifiers ******************************************************** */
		void push_back(const T& x);
		void pop_back();
		iterator insert(iterator position, const T& x);
		void insert(iterator position, size_type n, const T& x);
		template<class InputIt>
		void insert(iterator position, InputIt first, InputIt last,
		typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type*
		= NULL)
		{
			size_type	new_size = last - first;
			iterator	new_begin = _alloc.allocate(_size + new_size);
			iterator	tmp = new_begin;

			for (iterator it = _begin; it != position; it++)
				_alloc.construct(tmp++, *it);
			for (size_type i = 0; i < new_size; i++)
				_alloc.construct(tmp++, *(first + i));
			for (; position != _begin + _size; position++)
				_alloc.construct(tmp++, *position);
			_alloc.deallocate(_begin, _size);
			_begin = new_begin;
			_size += new_size;
			_capacity = _size;
		}
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap(vector<T,Alloc>& x);
		void clear();
};

/* Constructor & Destructor ************************************************* */

template<class T, class Alloc>
vector<T, Alloc>::vector(const Alloc& alloc)
: _alloc(alloc), _begin(NULL), _size(0), _capacity(0)
{
}

template<class T, class Alloc>
vector<T, Alloc>::vector(size_type n, const T& value, const Alloc& alloc)
: _alloc(alloc), _begin(NULL), _size(n), _capacity(n)
{
	_begin = _alloc.allocate(n);
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_begin + i, value);
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
	_begin = _alloc.allocate(copy._capacity);
	for (size_type i = 0; i < copy._size; i++)
		_alloc.construct(_begin + i, *(copy._begin + i));
	_size = copy._size;
	_capacity = copy._capacity;
	return (*this);
}

template<class T, class Alloc>
void vector<T, Alloc>::assign(size_type n, const T& u)
{
	_alloc.deallocate(_begin, _size);
	_begin = _alloc.allocate(n);
	for (size_type i = 0; i < n; i++)
		_alloc.construct(_begin + i, u);
	_size = n;
	_capacity = n;
}

/* Iterators **************************************************************** */

template<class T, class Alloc>
typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
{
	return(static_cast<reverse_iterator>(_begin + _size));
}

template<class T, class Alloc>
typename vector<T, Alloc>::const_reverse_iterator
vector<T, Alloc>::rbegin() const
{
	return(static_cast<const_reverse_iterator>(_begin + _size));
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
	iterator	new_begin = _alloc.allocate(new_size);
	size_type	i;

	for (i = 0; i < new_size && i < _size; i++)
		_alloc.construct(new_begin + i, *(_begin + i));
	for (; i < new_size; i++)
		_alloc.construct(new_begin + i, c);
	_alloc.deallocate(_begin, _size);
	_begin = new_begin;
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
	size_type	i;

	for (i = 0; i < _size; i++)
		_alloc.construct(new_begin + i, *(_begin + i));
	_alloc.deallocate(_begin, _size);
	_begin = new_begin;
	_capacity = n;
}

/* Modifiers **************************************************************** */

template<class T, class Alloc>
void vector<T, Alloc>::push_back(const T& x)
{
	if (_size >= _capacity)
	{
		iterator	new_begin = _alloc.allocate(_size + 1);
		size_type	i;

		for (i = 0; i < _size; i++)
			_alloc.construct(new_begin + i, *(_begin + i));
		_alloc.construct(new_begin + i, x);
		_alloc.deallocate(_begin, _size);
		_begin = new_begin;
		_size++;
		_capacity++;
	}
	else
	{
		_alloc.construct(end(), x);
		_size++;
	}
}

template<class T, class Alloc>
void vector<T, Alloc>::pop_back()
{
	_alloc.destroy(end() - 1);
	_size--;
}

template<class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator position,
const T& x)
{
	iterator	ret;

	if (_size >= _capacity)
	{
		iterator	new_begin = _alloc.allocate(_size + 1);
		iterator	tmp = new_begin;

		for (iterator it = _begin; it != position; it++)
			_alloc.construct(tmp++, *it);
		ret = tmp;
		_alloc.construct(tmp, x);
		tmp++;
		for (; position != _begin + _size; position++)
			_alloc.construct(tmp++, *position);
		_alloc.deallocate(_begin, _size);
		_begin = new_begin;
		_capacity++;
	}
	else
	{
		value_type	i[2];
		iterator	tmp = _begin;

		while (tmp != position)
			tmp++;
		ret = tmp;
		i[0] = *tmp;
		_alloc.destroy(tmp);
		_alloc.construct(tmp, x);
		tmp++;
		while (tmp != _begin + _size)
		{
			i[1] = *tmp;
			_alloc.destroy(tmp);
			_alloc.construct(tmp, i[0]);
			tmp++;
			i[0] = i[1];
		}
		_alloc.construct(tmp, i[0]);
	}
	_size++;
	return (ret);
}

template<class T, class Alloc>
void vector<T, Alloc>::insert(iterator position, size_type n, const T& x)
{
	if (n <= 0)
		return ;
	if (_size + n > _capacity)
	{
		iterator	new_begin = _alloc.allocate(_size + n);
		iterator	tmp = new_begin;

		for (iterator it = _begin; it != position; it++)
			_alloc.construct(tmp++, *it);
		for (size_type i = 0; i < n; i++)
			_alloc.construct(tmp++, x);
		for (; position != _begin + _size; position++)
			_alloc.construct(tmp++, *position);
		_alloc.deallocate(_begin, _size);
		_begin = new_begin;
		_size += n;
		_capacity = _size;
	}
	else
	{
		value_type	i[2];
		iterator	tmp = _begin;
		iterator	tmptmp;

		while (tmp != position)
			tmp++;
		i[0] = *tmp;
		_alloc.destroy(tmp);
		_alloc.construct(tmp, x);
		tmptmp = tmp + n;
		tmp++;
		while (tmp != _begin + _size)
		{
			while (tmptmp < _begin + _size)
			{
				i[1] = *tmptmp;
				_alloc.destroy(tmptmp);
				_alloc.construct(tmptmp, i[0]);
				tmptmp += n;
				i[0] = i[1];
			}
			_alloc.construct(tmptmp, i[0]);
			i[0] = *tmp;
			_alloc.destroy(tmp);
			_alloc.construct(tmp, x);
			tmptmp = tmp + n;
			tmp++;
		}
		_alloc.construct(tmp, i[0]);
	}
}

template<class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
{
	iterator	new_begin = _alloc.allocate(_size - 1);
	iterator	tmp = new_begin;
	iterator	ret;

	for (iterator it = _begin; it != position; it++)
		_alloc.construct(tmp++, *it);
	ret = tmp;
	position++;
	for (; position != _begin + _size; position++)
		_alloc.construct(tmp++, *position);
	_alloc.deallocate(_begin, _size);
	_begin = new_begin;
	_size--;
	_capacity--;
	return (ret);
}

template<class T, class Alloc>
typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first,
iterator last)
{
	size_type	new_size = last - first;
	iterator	new_begin = _alloc.allocate(_size - new_size);
	iterator	tmp = new_begin;
	iterator	ret;

	for (iterator it = _begin; it != first; it++)
		_alloc.construct(tmp++, *it);
	ret = tmp;
	for (iterator it = last; it != _begin + _size; it++)
		_alloc.construct(tmp++, *it);
	_alloc.deallocate(_begin, _size);
	_begin = new_begin;
	_size -= new_size;
	_capacity = _size;
	return (ret);
}

template<class T, class Alloc>
void vector<T, Alloc>::swap(vector<T,Alloc>& x)
{
	allocator_type	tmp_alloc = _alloc;
	iterator		tmp_begin = _begin;
	size_type		tmp_size = _size;
	size_type		tmp_capacity = _capacity;

	_alloc = x._alloc;
	_begin = x._begin;
	_size = x._size;
	_capacity = x._capacity;
	x._alloc = tmp_alloc;
	x._begin = tmp_begin;
	x._size = tmp_size;
	x._capacity = tmp_capacity;
}

template<class T, class Alloc>
void vector<T, Alloc>::clear()
{
	while (_size != 0)
		pop_back();
}

/* Non-member function overloads ******************************************** */

template<class T, class Alloc>
bool operator==(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
{
	if (x.size() == y.size() && equal(x.begin(), x.end(), y.begin()))
		return (true);
	return (false);
}

template<class T, class Alloc>
bool operator< (const vector<T,Alloc>& x, const vector<T,Alloc>& y)
{
	if (lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()))
		return (true);
	return (false);
}

template<class T, class Alloc>
bool operator!=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
{
	if (x.size() != y.size() || !equal(x.begin(), x.end(), y.begin()))
		return (true);
	return (false);
}

template<class T, class Alloc>
bool operator> (const vector<T,Alloc>& x, const vector<T,Alloc>& y)
{
	if (lexicographical_compare(y.begin(), y.end(), x.begin(), x.end()))
		return (true);
	return (false);
}

template<class T, class Alloc>
bool operator>=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
{
	if (!lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()))
		return (true);
	return (false);
}

template<class T, class Alloc>
bool operator<=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
{
	if (!lexicographical_compare(y.begin(), y.end(), x.begin(), x.end()))
		return (true);
	return (false);
}

template<class T, class Alloc>
void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}
}

#endif
