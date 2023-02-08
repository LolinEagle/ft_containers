/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:03:45 by frrusso           #+#    #+#             */
/*   Updated: 2023/01/30 13:03:47 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.hpp>
#include <vector.hpp>
#include <stack>
#include <vector>

#define DEBUG	false
#define CHECK	"\U00002705 "
#define LINE	"______________________________________________________________"

void	ft_stack(void)
{
	ft ::stack<int>	fa;
	std::stack<int>	sa;

	std::cout << "___Stack_" << LINE << "\nDefault :" << std::endl;

	// Size
	if (DEBUG || fa.size() != sa.size())
	{
		std::cout <<
		"size=" << fa.size() << '\n' <<
		"size=" << sa.size() << std::endl;
	}
	else
		std::cout << CHECK << "size" << std::endl;

	// Push & Top
	fa.push(1);
	sa.push(1);
	if (DEBUG || fa.top() != sa.top())
	{
		std::cout <<
		"top=" << fa.top() << '\n' <<
		"top=" << sa.top() << std::endl;
	}
	else
		std::cout << CHECK << "push & top" << std::endl;

	// Pop & Empty
	fa.pop();
	sa.pop();
	if (DEBUG || fa.empty() != sa.empty())
	{
		std::cout <<
		"empty=" << fa.empty() << '\n' <<
		"empty=" << sa.empty() << '\n' <<
		std::endl;
	}
	else
		std::cout << CHECK << "pop & empty" << std::endl;
}

void	ft_vector(void)
{
	ft ::vector<int>	fa;
	std::vector<int>	va;

	std::cout << "___Vector" << LINE << "\nDefault :" << std::endl;

	// Size
	if (DEBUG || fa.size() != va.size())
	{
		std::cout <<
		"size=" << fa.size() << '\n' <<
		"size=" << va.size() << '\n' <<
		std::endl;
	}
	else
		std::cout << CHECK << "size" << std::endl;

	// Max size
	if (DEBUG || fa.max_size() != va.max_size())
	{
		std::cout <<
		"max_size=" << fa.max_size() << '\n' <<
		"max_size=" << va.max_size() << '\n' <<
		std::endl;
	}
	else
		std::cout << CHECK << "max_size" << std::endl;

	// Push back
	fa.push_back(1);
	va.push_back(1);
	if (DEBUG || fa.size() != va.size())
	{
		std::cout <<
		"size=" << fa.size() << '\n' <<
		"size=" << va.size() << '\n' <<
		std::endl;
	}
	else
		std::cout << CHECK << "push_back & size" << std::endl;

	// Pop back
	fa.pop_back();
	va.pop_back();
	if (DEBUG || fa.size() != va.size())
	{
		std::cout <<
		"size=" << fa.size() << '\n' <<
		"size=" << va.size() << '\n' <<
		std::endl;
	}
	else
		std::cout << CHECK << "pop_back & size" << std::endl;

	// Insert


	// Erase


	// Swap


	// Clear


	// Begin


	// End


	// Rbegin


	// Rend


	// Resize


	// Capacity


	// Empty


	// Reserve


	// Operator []


	// At


	// Front


	// Back


	ft ::vector<int>	fb(8, 8);
	std::vector<int>	vb(8, 8);

	std::cout << "Fill :" << std::endl;



	std::cout << "Range :" << std::endl;



	ft ::vector<int>	fd(fa);
	std::vector<int>	vd(va);

	std::cout << "Copy :" << std::endl;


}

int		main(void)
{
	ft_vector();
	ft_stack();
	return (0);
}
