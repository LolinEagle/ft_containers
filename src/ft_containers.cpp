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

#include <header.hpp>
#include <stack.hpp>
#include <vector.hpp>
#include <stack>
#include <vector>

void	ft_stack(void)
{
	ft ::stack<int>	fa;
	std::stack<int>	sa;

	std::cout << BLUE << "___Stack_" << LINE << "\nDefault :" << ENDL;

	// Size
	if (DEBUG || fa.size() != sa.size())
	{
		std::cout << CROSS << "Size\n" << RESET <<
		"size=" << fa.size() << '\n' <<
		"size=" << sa.size() << std::endl;
	}
	else
		std::cout << CHECK << "Size" << ENDL;

	// Push & Top
	fa.push(1);
	sa.push(1);
	if (DEBUG || fa.top() != sa.top())
	{
		std::cout << CROSS << "Push & Top\n" << RESET <<
		"top=" << fa.top() << '\n' <<
		"top=" << sa.top() << std::endl;
	}
	else
		std::cout << CHECK << "Push & Top" << ENDL;

	// Pop & Empty
	fa.pop();
	sa.pop();
	if (DEBUG || fa.empty() != sa.empty())
	{
		std::cout << CROSS << "Pop & Empty\n" << RESET <<
		"empty=" << fa.empty() << '\n' <<
		"empty=" << sa.empty() << std::endl;
	}
	else
		std::cout << CHECK << "Pop & Empty" << ENDL;
}

void	print_vector(ft::vector<int> f)
{
	std::cout << '[';
	for (ft::vector<int>::iterator it = f.begin(); it != f.end(); ++it)
		std::cout << *it << ", ";
	std::cout << "NULL]" << std::endl;
}

void	ft_vector(void)
{
	ft ::vector<int>	fa;
	std::vector<int>	va;

	std::cout << BLUE << "___Vector" << LINE << "\nDefault :" << ENDL;

	// Size
	if (DEBUG || fa.size() != va.size())
	{
		std::cout << CROSS << "Size\n" << RESET <<
		"size=" << fa.size() << '\n' <<
		"size=" << va.size() << std::endl;
	}
	else
		std::cout << CHECK << "Size" << ENDL;

	// Max size
	if (DEBUG || fa.max_size() != va.max_size())
	{
		std::cout << CROSS << "Max size\n" << RESET <<
		"max_size=" << fa.max_size() << '\n' <<
		"max_size=" << va.max_size() << std::endl;
	}
	else
		std::cout << CHECK << "Max size" << ENDL;

	// Push back
	fa.push_back(1);
	va.push_back(1);
	if (DEBUG || fa.size() != va.size())
	{
		std::cout << CROSS << "Push back & Size\n" << RESET <<
		"size=" << fa.size() << '\n' <<
		"size=" << va.size() << std::endl;
	}
	else
		std::cout << CHECK << "Push back & Size" << ENDL;

	// Pop back
	fa.pop_back();
	va.pop_back();
	if (DEBUG || fa.size() != va.size())
	{
		std::cout << CROSS << "Pop back & Size\n" << RESET <<
		"size=" << fa.size() << '\n' <<
		"size=" << va.size() << std::endl;
	}
	else
		std::cout << CHECK << "Pop back & Size" << ENDL;

	// Insert


	// Erase


	// Swap


	// Clear


	/* Iterators ************************************************************ */
	for (int i = 1; i < 9; i++)
	{
		fa.push_back(i);
		va.push_back(i);
	}

	// Begin
	if (DEBUG || *fa.begin() != *va.begin())
	{
		std::cout << CROSS << "Begin\n" << RESET <<
		"begin=" << *fa.begin() << '\n' <<
		"begin=" << *va.begin() << std::endl;
	}
	else
		std::cout << CHECK << "Begin" << ENDL;

	// End
	if (DEBUG || *(fa.end() - 1) != *(va.end() - 1))
	{
		std::cout << CROSS << "End\n" << RESET <<
		"end=" << *(fa.end() - 1) << '\n' <<
		"end=" << *(va.end() - 1) << std::endl;
	}
	else
		std::cout << CHECK << "End" << ENDL;

	// Rbegin
	if (DEBUG || *fa.rbegin() != *va.rbegin())
	{
		std::cout << CROSS << "Rbegin\n" << RESET <<
		"rbegin=" << *fa.rbegin() << '\n' <<
		"rbegin=" << *va.rbegin() << std::endl;
	}
	else
		std::cout << CHECK << "Rbegin" << ENDL;

	// Rend
	if (DEBUG || *(fa.rend() - 1) != *(va.rend() - 1))
	{
		std::cout << CROSS << "Rend\n" << RESET <<
		"rend=" << *(fa.rend() - 1) << '\n' <<
		"rend=" << *(va.rend() - 1) << std::endl;
	}
	else
		std::cout << CHECK << "Rend" << ENDL;

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

	std::cout << BLUE << "Fill :" << ENDL;



	std::cout << BLUE << "Range :" << ENDL;



	ft ::vector<int>	fd(fa);
	std::vector<int>	vd(va);

	std::cout << BLUE << "Copy :" << ENDL;


}

int		main(void)
{
	ft_vector();
	std::cout << std::endl;
	ft_stack();
	return (0);
}
