/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:01:01 by frrusso           #+#    #+#             */
/*   Updated: 2023/02/01 16:01:05 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

// Debug
#include <vector>

namespace ft
{
template<class T, class Container = std::vector<T> > class stack
{
	public:
		typedef typename Container::value_type	value_type;
		typedef typename Container::size_type	size_type;
		typedef Container						container_type;
	protected:
		Container	c;
	public:
		explicit stack(const Container& container = Container());
		bool empty() const{return c.empty();}
		size_type size() const{return c.size();}
		value_type& top(){return c.back(); }
		const value_type& top() const{return c.back();}
		void push(const value_type& x){c.push_back(x);}
		void pop(){c.pop_back();}
};

template <class T, class Container>
stack<T, Container>::stack(const Container& container) : c(container)
{
}

template <class T, class Container>
bool operator==(const stack<T, Container>& x, const stack<T, Container>& y)
{
	if (x == y)
		return (true);
	return (false);
}

template <class T, class Container>
bool operator< (const stack<T, Container>& x, const stack<T, Container>& y)
{
	if (x < y)
		return (true);
	return (false);
}

template <class T, class Container>
bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y)
{
	if (x != y)
		return (true);
	return (false);
}

template <class T, class Container>
bool operator> (const stack<T, Container>& x, const stack<T, Container>& y)
{
	if (x > y)
		return (true);
	return (false);
}

template <class T, class Container>
bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y)
{
	if (x >= y)
		return (true);
	return (false);
}

template <class T, class Container>
bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y)
{
	if (x <= y)
		return (true);
	return (false);
}
}

#endif
