/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:22:09 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/30 11:22:11 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <ft_containers.hpp>

namespace ft
{
template<class Key, class T, class Compare = std::less<Key>,
class Alloc = std::allocator<pair<const Key, T> > > class map
{
	public:
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef pair<const Key, T>						value_type;
		typedef Compare									key_compare;
		typedef Alloc									allocator_type;
		typedef typename Alloc::reference				reference;
		typedef typename Alloc::const_reference			const_reference;
		typedef T*										iterator;
		typedef const T*								const_iterator;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef typename Alloc::pointer					pointer;
		typedef typename Alloc::const_pointer			const_pointer;
		typedef std::reverse_iterator<iterator>			reverse_iterator;
		typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
		class value_compare :
		public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c){}
			public:
				bool operator()(const value_type& x, const value_type& y) const
				{
					return (comp(x.first, y.first));
				}
		};
	private:
		
	public:
		/* Constructor & Destructor ***************************************** */
		explicit map(const Compare& comp = Compare(),
		const Alloc& = Alloc());
		template <class InputIterator>
		map(InputIterator first, InputIterator last,
		const Compare& comp = Compare(), const Alloc& = Alloc());
		map(const map<Key,T,Compare,Alloc>& x);
		~map();
		map<Key,T,Compare,Alloc>&operator=(const map<Key,T,Compare,Alloc>& x);

		/* Iterators ******************************************************** */
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		/* Capacity ********************************************************* */
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		/* Element access *************************************************** */
		T& operator[](const key_type& x);
		
		/* Modifiers ******************************************************** */
		pair<iterator, bool> insert(const value_type& x);
		iterator insert(iterator position, const value_type& x);
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last);
		void erase(iterator position);
		size_type erase(const key_type& x);
		void erase(iterator first, iterator last);
		void swap(map<Key,T,Compare,Alloc>&);
		void clear();

		/* Observers ******************************************************** */
		key_compare key_comp() const;
		value_compare value_comp() const;

		/* Map operations *************************************************** */
		iterator find(const key_type& x);
		const_iterator find(const key_type& x) const;
		size_type count(const key_type& x) const;
		iterator lower_bound(const key_type& x);
		const_iterator lower_bound(const key_type& x) const;
		iterator upper_bound(const key_type& x);
		const_iterator upper_bound(const key_type& x) const;
		pair<iterator,iterator>
		equal_range(const key_type& x);
		pair<const_iterator,const_iterator>
		equal_range(const key_type& x) const;
};

/* Non-member function overloads ******************************************** */
template <class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key,T,Compare,Alloc>& x,
const map<Key,T,Compare,Alloc>& y)
{
	(void)x;
	(void)y;
	return (false);
}
template <class Key, class T, class Compare, class Alloc>
bool operator< (const map<Key,T,Compare,Alloc>& x,
const map<Key,T,Compare,Alloc>& y)
{
	(void)x;
	(void)y;
	return (false);
}
template <class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key,T,Compare,Alloc>& x,
const map<Key,T,Compare,Alloc>& y)
{
	(void)x;
	(void)y;
	return (false);
}
template <class Key, class T, class Compare, class Alloc>
bool operator> (const map<Key,T,Compare,Alloc>& x,
const map<Key,T,Compare,Alloc>& y)
{
	(void)x;
	(void)y;
	return (false);
}
template <class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key,T,Compare,Alloc>& x,
const map<Key,T,Compare,Alloc>& y)
{
	(void)x;
	(void)y;
	return (false);
}
template <class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key,T,Compare,Alloc>& x,
const map<Key,T,Compare,Alloc>& y)
{
	(void)x;
	(void)y;
	return (false);
}

/* specialized algorithms *************************************************** */
template <class Key, class T, class Compare, class Alloc>
void swap(map<Key,T,Compare,Alloc>& x,
map<Key,T,Compare,Alloc>& y)
{
	(void)x;
	(void)y;
}
}

#endif
