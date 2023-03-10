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

	/* reverse_iterator ***************************************************** */
	#define REVERSE_IT typename iterator_traits<Iterator>
	template<class Iterator>
	class reverse_iterator : public std::iterator<
	REVERSE_IT::iterator_category,
	REVERSE_IT::value_type,
	REVERSE_IT::difference_type,
	REVERSE_IT::pointer,
	REVERSE_IT::reference>
	{
		public:
			typedef Iterator					iterator_type;
			typedef REVERSE_IT::difference_type	difference_type;
			typedef REVERSE_IT::reference		reference;
			typedef REVERSE_IT::pointer			pointer;
		protected:
			Iterator	current;
		public:
			reverse_iterator() : current(){}
			explicit reverse_iterator(Iterator x) : current(x){}
			template<class U>
			reverse_iterator(const reverse_iterator<U>& u)
			{
				current = u.base();
			}
			Iterator base() const
			{
				return (current);
			}
			reference			operator*() const
			{
				Iterator	tmp = current;
				return (*(--tmp));
			}
			pointer				operator->() const
			{
				return &(operator*());
			}
			reverse_iterator&	operator++()
			{
				current--;
				return (*this);
			}
			reverse_iterator	operator++(int)
			{
				reverse_iterator	tmp = *this;
				current--;
				return (tmp);
			}
			reverse_iterator&	operator--()
			{
				current++;
				return (*this);
			}
			reverse_iterator	operator--(int)
			{
				reverse_iterator	tmp = *this;
				current++;
				return (tmp);
			}
			reverse_iterator	operator+ (difference_type n) const
			{
				return (reverse_iterator(current - n));
			}
			reverse_iterator&	operator+=(difference_type n)
			{
				current -= n;
				return (*this);
			}
			reverse_iterator	operator- (difference_type n) const
			{
				return (reverse_iterator(current + n));
			}
			reverse_iterator&	operator-=(difference_type n)
			{
				current += n;
				return (*this);
			}
			reference			operator[](difference_type n) const
			{
				return (current[-n - 1]);
			}
	};
	template<class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& x,
	const reverse_iterator<Iterator2>& y)
	{
		return (x.base() == y.base());
	}
	template<class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1>& x,
	const reverse_iterator<Iterator2>& y)
	{
		return (x.base() > y.base());
	}
	template<class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& x,
	const reverse_iterator<Iterator2>& y)
	{
		return (x.base() != y.base());
	}
	template<class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1>& x,
	const reverse_iterator<Iterator2>& y)
	{
		return (x.base() < y.base());
	}
	template<class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1>& x,
	const reverse_iterator<Iterator2>& y)
	{
		return (x.base() <= y.base());
	}
	template<class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& x,
	const reverse_iterator<Iterator2>& y)
	{
		return (x.base() >= y.base());
	}
	template<class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator-(
	const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y)
	{
		return (y.base() - x.base());
	}
	template<class Iterator>
	reverse_iterator<Iterator> operator+(
	typename reverse_iterator<Iterator>::difference_type n,
	const reverse_iterator<Iterator>& x)
	{
		return (reverse_iterator<Iterator>(x.base() - n));
	}

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
	template<class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1,
	InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	/* lexicographical_compare ********************************************** */
	template<class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
	InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

	/* pair ***************************************************************** */
	template<typename T1, typename T2>
	class pair
	{
		public:
			T1	first;
			T2	second;

			pair() : first(), second(){}
			pair(const T1& t1, const T2& t2) : first(t1), second(t2){}

			const T1&	get_first() const{return(first);}
			T1&			get_first(){return(first);}

			const T2&	get_second() const{return(second);}
			T2&			get_second(){return(second);}
	};

	/* make_pair ************************************************************ */
	template<typename T1, typename T2>
	pair<T1, T2> make_pair(const T1& t1, const T2& t2)
	{
		return(pair<T1, T2>(t1, t2));
	}
}

#endif
