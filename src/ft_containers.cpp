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

void	print_ft_vector(ft::vector<int> f)
{
	std::cout << '[';
	for (ft::vector<int>::iterator it = f.begin(); it != f.end(); ++it)
		std::cout << *it << ", ";
	std::cout << "end]" << std::endl;
}

void	print_std_vector(std::vector<int> f)
{
	std::cout << '[';
	for (std::vector<int>::iterator it = f.begin(); it != f.end(); ++it)
		std::cout << *it << ", ";
	std::cout << "end]" << std::endl;
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

	// Empty
	if (DEBUG || fa.empty() != va.empty())
	{
		std::cout << CROSS << "Empty\n" << RESET <<
		"empty=" << fa.empty() << '\n' <<
		"empty=" << va.empty() << std::endl;
	}
	else
		std::cout << CHECK << "Empty" << ENDL;

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

	fa.push_back(1);
	va.push_back(1);
	fa.push_back(4);
	va.push_back(4);
	fa.push_back(5);
	va.push_back(5);

	// Insert single element
	ft ::vector<int>::iterator itf = fa.insert(fa.begin() + 1, 2);
	std::vector<int>::iterator itv = va.insert(va.begin() + 1, 2);
	if (DEBUG || *itf != *itv)
	{
		std::cout << CROSS << "Insert single element\n" << RESET <<
		"*itf=" << *itf << '\n' <<
		"*itv=" << *itv << std::endl;
		print_ft_vector(fa);
		print_std_vector(va);
	}
	else
		std::cout << CHECK << "Insert single element" << ENDL;

	// Insert fill
	fa.insert(fa.begin() + 2, (size_t)3, 3);// Need a cast for some resson
	va.insert(va.begin() + 2, 3, 3);
	if (DEBUG || *(fa.begin() + 3) != *(va.begin() + 3))
	{
		std::cout << CROSS << "Insert fill\n" << RESET <<
		"*(fa.begin() + 3)=" << *(fa.begin() + 3) << '\n' <<
		"*(va.begin() + 3)=" << *(va.begin() + 3) << std::endl;
		print_ft_vector(fa);
		print_std_vector(va);
	}
	else
		std::cout << CHECK << "Insert fill" << ENDL;

	// Insert range
	

	// Erase single element
	ft ::vector<int>::iterator itf2 = fa.erase(fa.begin());
	std::vector<int>::iterator itv2 = va.erase(va.begin());
	if (DEBUG || *itf2 != *itv2)
	{
		std::cout << CROSS << "Erase single element\n" << RESET <<
		"*itf2=" << *itf2 << '\n' <<
		"*itv2=" << *itv2 << std::endl;
		print_ft_vector(fa);
		print_std_vector(va);
	}
	else
		std::cout << CHECK << "Erase single element" << ENDL;

	// Erase range
	ft ::vector<int>::iterator itf3 = fa.erase(fa.begin(), fa.begin() + 2);
	std::vector<int>::iterator itv3 = va.erase(va.begin(), va.begin() + 2);
	if (DEBUG || *itf3 != *itv3)
	{
		std::cout << CROSS << "Erase range\n" << RESET <<
		"*itf3=" << *itf3 << '\n' <<
		"*itv3=" << *itv3 << std::endl;
		print_ft_vector(fa);
		print_std_vector(va);
	}
	else
		std::cout << CHECK << "Erase range" << ENDL;

	// Swap


	// Clear
	fa.clear();
	va.clear();
	if (DEBUG || fa.size() != va.size())
	{
		std::cout << CROSS << "Clear\n" << RESET <<
		"size=" << fa.size() << '\n' <<
		"size=" << va.size() << std::endl;
	}
	else
		std::cout << CHECK << "Clear" << ENDL;

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
	fa.resize(4);
	va.resize(4);
	if (DEBUG || *(fa.end() - 1) != *(va.end() - 1))
	{
		std::cout << CROSS << "Resize\n" << RESET <<
		"end=" << *(fa.end() - 1) << '\n' <<
		"end=" << *(va.end() - 1) << std::endl;
		print_ft_vector(fa);
		print_std_vector(va);
	}
	else
		std::cout << CHECK << "Resize" << ENDL;

	// Resize
	fa.resize(8, 99);
	va.resize(8, 99);
	if (DEBUG || *(fa.end() - 1) != *(va.end() - 1))
	{
		std::cout << CROSS << "Resize\n" << RESET <<
		"end=" << *(fa.end() - 1) << '\n' <<
		"end=" << *(va.end() - 1) << std::endl;
		print_ft_vector(fa);
		print_std_vector(va);
	}
	else
		std::cout << CHECK << "Resize" << ENDL;

	// Capacity
	if (DEBUG || fa.capacity() != va.capacity())
	{
		std::cout << CROSS << "Capacity\n" << RESET <<
		"capacity=" << fa.capacity() << '\n' <<
		"capacity=" << va.capacity() << std::endl;
	}
	else
		std::cout << CHECK << "Capacity" << ENDL;

	// Empty
	if (DEBUG || fa.empty() != va.empty())
	{
		std::cout << CROSS << "Empty\n" << RESET <<
		"empty=" << fa.empty() << '\n' <<
		"empty=" << va.empty() << std::endl;
	}
	else
		std::cout << CHECK << "Empty" << ENDL;

	// Reserve
	fa.reserve(99);
	va.reserve(99);
	if (DEBUG || fa.capacity() != va.capacity())
	{
		std::cout << CROSS << "Reserve\n" << RESET <<
		"capacity=" << fa.capacity() << '\n' <<
		"capacity=" << va.capacity() << std::endl;
	}
	else
		std::cout << CHECK << "Reserve" << ENDL;

	// Operator []
	if (DEBUG || fa[1] != va[1])
	{
		std::cout << CROSS << "Operator []\n" << RESET <<
		"fa[1]=" << fa[1] << '\n' <<
		"va[1]=" << va[1] << std::endl;
	}
	else
		std::cout << CHECK << "Operator []" << ENDL;

	// At
	if (DEBUG || fa.at(4) != va.at(4))
	{
		std::cout << CROSS << "At\n" << RESET <<
		"at=" << fa.at(4) << '\n' <<
		"at=" << va.at(4) << std::endl;
	}
	else
		std::cout << CHECK << "At" << ENDL;

	// Front
	if (DEBUG || fa.front() != va.front())
	{
		std::cout << CROSS << "Front\n" << RESET <<
		"front=" << fa.front() << '\n' <<
		"front=" << va.front() << std::endl;
	}
	else
		std::cout << CHECK << "Front" << ENDL;

	// Back
	if (DEBUG || fa.back() != va.back())
	{
		std::cout << CROSS << "Back\n" << RESET <<
		"back=" << fa.back() << '\n' <<
		"back=" << va.back() << std::endl;
	}
	else
		std::cout << CHECK << "Back" << ENDL;

	// ft ::vector<int>	fb(8, 8);
	// std::vector<int>	vb(8, 8);

	// std::cout << BLUE << "Fill :" << ENDL;

	// // Size
	// if (DEBUG || fb.size() != vb.size())
	// {
	// 	std::cout << CROSS << "Size\n" << RESET <<
	// 	"size=" << fb.size() << '\n' <<
	// 	"size=" << vb.size() << std::endl;
	// }
	// else
	// 	std::cout << CHECK << "Size" << ENDL;

	// std::cout << BLUE << "Range :" << ENDL;



	// ft ::vector<int>	fd(fa);
	// std::vector<int>	vd(va);

	// std::cout << BLUE << "Copy :" << ENDL;

	// // Size
	// if (DEBUG || fd.size() != vd.size())
	// {
	// 	std::cout << CROSS << "Size\n" << RESET <<
	// 	"size=" << fd.size() << '\n' <<
	// 	"size=" << vd.size() << std::endl;
	// }
	// else
	// 	std::cout << CHECK << "Size" << ENDL;
}

int		main(void)
{
	ft_vector();
	std::cout << std::endl;
	ft_stack();
	return (0);
}
