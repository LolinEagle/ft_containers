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
		
	};

	template <class T, class Container>
	bool operator==(const stack<T, Container>& x, const stack<T, Container>& y)
	{
		(void)x, y;
		return (false);
	}

	template <class T, class Container>
	bool operator< (const stack<T, Container>& x, const stack<T, Container>& y)
	{
		(void)x, y;
		return (false);
	}

	template <class T, class Container>
	bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y)
	{
		(void)x, y;
		return (false);
	}

	template <class T, class Container>
	bool operator> (const stack<T, Container>& x, const stack<T, Container>& y)
	{
		(void)x, y;
		return (false);
	}

	template <class T, class Container>
	bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y)
	{
		(void)x, y;
		return (false);
	}

	template <class T, class Container>
	bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y)
	{
		(void)x, y;
		return (false);
	}
}

#endif
