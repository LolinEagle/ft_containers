/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:46:57 by frrusso           #+#    #+#             */
/*   Updated: 2023/02/13 17:47:00 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
#define FT_CONTAINERS_HPP

#include <iostream>

namespace ft
{
	/* iterator_traits ****************************************************** */
	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t							difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef std::random_access_iterator_tag			iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t							difference_type;
		typedef T										value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef std::random_access_iterator_tag			iterator_category;
	};

	/* enable_if ************************************************************ */
	template<bool B, typename T = void>
	struct enable_if{};

	template<typename T>
	struct enable_if<true, T>{typedef T type;};
	
	/* is_integral ********************************************************** */
	template<typename T>
	struct is_integral{static const bool value = false;};

	template<>
	struct is_integral<bool>{static const bool value = true;};

	template<>
	struct is_integral<char>{static const bool value = true;};

	template<>
	struct is_integral<signed char>{static const bool value = true;};

	template<>
	struct is_integral<unsigned char>{static const bool value = true;};

	template<>
	struct is_integral<short>{static const bool value = true;};

	template<>
	struct is_integral<unsigned short>{static const bool value = true;};

	template<>
	struct is_integral<int>{static const bool value = true;};

	template<>
	struct is_integral<unsigned int>{static const bool value = true;};

	template<>
	struct is_integral<long>{static const bool value = true;};

	template<>
	struct is_integral<unsigned long>{static const bool value = true;};

	template<>
	struct is_integral<long long>{static const bool value = true;};

	template<>
	struct is_integral<unsigned long long>{static const bool value = true;};

	/* equal **************************************************************** */


	/* lexicographical_compare ********************************************** */


	/* pair ***************************************************************** */


	/* make_pair ************************************************************ */

}

#endif
