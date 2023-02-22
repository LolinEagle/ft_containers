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

	/* Size ***************************************************************** */
	if (DEBUG || fa.size() != sa.size())
	{
		std::cout << CROSS << "Size\n" << RESET <<
		"size=" << fa.size() << '\n' <<
		"size=" << sa.size() << std::endl;
	}
	else
		std::cout << CHECK << "Size" << ENDL;

	/* Push & Top *********************************************************** */
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

	/* Pop & Empty ********************************************************** */
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

void	print_ft_vector(ft::vector<int>& f)
{
	std::cout << '[';
	for (ft::vector<int>::iterator it = f.begin(); it != f.end(); ++it)
		std::cout << *it << ", ";
	std::cout << "end]" << std::endl;
}

void	print_std_vector(std::vector<int>& f)
{
	std::cout << '[';
	for (std::vector<int>::iterator it = f.begin(); it != f.end(); ++it)
		std::cout << *it << ", ";
	std::cout << "end]" << std::endl;
}

bool	vector_test(ft::vector<int>& ft, std::vector<int>& std)
{
	bool	ret = false;

	if (ft.size() != std.size())
	{
		std::cout << YELLOW <<
		"ft  size=" << ft.size() << '\n' <<
		"std size=" << std.size() << ENDL;
		ret = true;
	}
	if (ft.capacity() < ft.size() || std.capacity() < std.size())
	{
		std::cout << YELLOW <<
		"ft  capacity=" << ft.capacity() << '\n' <<
		"std capacity=" << std.capacity() << ENDL;
		ret = true;
	}
	return (ret);
}

void	ft_vector(void)
{
	/* Default ************************************************************** */
	ft ::vector<int>	fa;
	std::vector<int>	va;

	std::cout << BLUE << "___Vector" << LINE << "\nDefault :" << ENDL;

	/* Max size ************************************************************* */
	if (DEBUG || vector_test(fa, va) || fa.max_size() != va.max_size())
	{
		std::cout << CROSS << "Max size\n" << RESET <<
		"max_size=" << fa.max_size() << '\n' <<
		"max_size=" << va.max_size() << std::endl;
	}
	else
		std::cout << CHECK << "Max size" << ENDL;

	/* Empty **************************************************************** */
	if (DEBUG || vector_test(fa, va) || fa.empty() != va.empty())
	{
		std::cout << CROSS << "Empty\n" << RESET <<
		"empty=" << fa.empty() << '\n' <<
		"empty=" << va.empty() << std::endl;
	}
	else
		std::cout << CHECK << "Empty" << ENDL;

	/* Push back ************************************************************ */
	fa.push_back(1);
	va.push_back(1);
	if (DEBUG || vector_test(fa, va) || fa.size() != va.size())
	{
		std::cout << CROSS << "Push back\n" << RESET <<
		"size=" << fa.size() << '\n' <<
		"size=" << va.size() << std::endl;
	}
	else
		std::cout << CHECK << "Push back" << ENDL;

	/* Pop back ************************************************************* */
	fa.pop_back();
	va.pop_back();
	if (DEBUG || vector_test(fa, va) || fa.size() != va.size())
	{
		std::cout << CROSS << "Pop back\n" << RESET <<
		"size=" << fa.size() << '\n' <<
		"size=" << va.size() << std::endl;
	}
	else
		std::cout << CHECK << "Pop back" << ENDL;

	fa.push_back(1);
	va.push_back(1);
	fa.push_back(4);
	va.push_back(4);
	fa.push_back(5);
	va.push_back(5);

	/* Insert single element ************************************************ */
	ft ::vector<int>::iterator itf = fa.insert(fa.begin() + 1, 2);
	std::vector<int>::iterator itv = va.insert(va.begin() + 1, 2);
	if (DEBUG || vector_test(fa, va) || *itf != *itv)
	{
		std::cout << CROSS << "Insert single element\n" << RESET <<
		"*itf=" << *itf << '\n' <<
		"*itv=" << *itv << std::endl;
		print_ft_vector(fa);
		print_std_vector(va);
	}
	else
		std::cout << CHECK << "Insert single element" << ENDL;

	/* Insert fill ********************************************************** */
	fa.insert(fa.begin() + 2, 3, 0);
	va.insert(va.begin() + 2, 3, 0);
	if (DEBUG || vector_test(fa, va) || *(fa.begin() + 3) != *(va.begin() + 3))
	{
		std::cout << CROSS << "Insert fill\n" << RESET <<
		"*(fa.begin() + 3)=" << *(fa.begin() + 3) << '\n' <<
		"*(va.begin() + 3)=" << *(va.begin() + 3) << std::endl;
		print_ft_vector(fa);
		print_std_vector(va);
	}
	else
		std::cout << CHECK << "Insert fill" << ENDL;

	/* Insert range ********************************************************* */
	fa.insert(fa.begin() + 2, fa.begin(), fa.end());
	va.insert(va.begin() + 2, va.begin(), va.end());
	if (DEBUG || vector_test(fa, va) || *(fa.begin() + 3) != *(va.begin() + 3))
	{
		std::cout << CROSS << "Insert range\n" << RESET <<
		"*(fa.begin() + 3)=" << *(fa.begin() + 3) << '\n' <<
		"*(va.begin() + 3)=" << *(va.begin() + 3) << std::endl;
		print_ft_vector(fa);
		print_std_vector(va);
	}
	else
		std::cout << CHECK << "Insert range" << ENDL;

	/* Erase single element ************************************************* */
	ft ::vector<int>::iterator itf2 = fa.erase(fa.begin());
	std::vector<int>::iterator itv2 = va.erase(va.begin());
	if (DEBUG || vector_test(fa, va) || *itf2 != *itv2)
	{
		std::cout << CROSS << "Erase single element\n" << RESET <<
		"*itf2=" << *itf2 << '\n' <<
		"*itv2=" << *itv2 << std::endl;
		print_ft_vector(fa);
		print_std_vector(va);
	}
	else
		std::cout << CHECK << "Erase single element" << ENDL;

	/* Erase range ********************************************************** */
	ft ::vector<int>::iterator itf3 = fa.erase(fa.begin(), fa.begin() + 2);
	std::vector<int>::iterator itv3 = va.erase(va.begin(), va.begin() + 2);
	if (DEBUG || vector_test(fa, va) || *itf3 != *itv3)
	{
		std::cout << CROSS << "Erase range\n" << RESET <<
		"*itf3=" << *itf3 << '\n' <<
		"*itv3=" << *itv3 << std::endl;
		print_ft_vector(fa);
		print_std_vector(va);
	}
	else
		std::cout << CHECK << "Erase range" << ENDL;

	/* Swap ***************************************************************** */
	ft ::vector<int>	fa_swap;
	std::vector<int>	va_swap;
	fa_swap.push_back(0);
	va_swap.push_back(0);
	fa_swap.push_back(1);
	va_swap.push_back(1);
	fa.swap(fa_swap);
	va.swap(va_swap);
	if (DEBUG || vector_test(fa, va) || fa.size() != va.size())
	{
		std::cout << CROSS << "Swap\n" << RESET <<
		"size=" << fa.size() << '\n' <<
		"size=" << va.size() << std::endl;
	}
	else
		std::cout << CHECK << "Swap" << ENDL;

	/* Swap ***************************************************************** */
	swap(fa, fa_swap);
	swap(va, va_swap);
	if (DEBUG || vector_test(fa, va) || fa.size() != va.size())
	{
		std::cout << CROSS << "Swap\n" << RESET <<
		"size=" << fa.size() << '\n' <<
		"size=" << va.size() << std::endl;
	}
	else
		std::cout << CHECK << "Swap" << ENDL;

	/* Clear **************************************************************** */
	fa.clear();
	va.clear();
	if (DEBUG || vector_test(fa, va) || fa.size() != va.size())
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

	/* Begin **************************************************************** */
	if (DEBUG || vector_test(fa, va) || *fa.begin() != *va.begin())
	{
		std::cout << CROSS << "Begin\n" << RESET <<
		"begin=" << *fa.begin() << '\n' <<
		"begin=" << *va.begin() << std::endl;
	}
	else
		std::cout << CHECK << "Begin" << ENDL;

	/* End ****************************************************************** */
	if (DEBUG || vector_test(fa, va) || *(fa.end() - 1) != *(va.end() - 1))
	{
		std::cout << CROSS << "End\n" << RESET <<
		"end=" << *(fa.end() - 1) << '\n' <<
		"end=" << *(va.end() - 1) << std::endl;
	}
	else
		std::cout << CHECK << "End" << ENDL;

	/* Rbegin *************************************************************** */
	if (DEBUG || vector_test(fa, va) || *fa.rbegin() != *va.rbegin())
	{
		std::cout << CROSS << "Rbegin\n" << RESET <<
		"rbegin=" << *fa.rbegin() << '\n' <<
		"rbegin=" << *va.rbegin() << std::endl;
	}
	else
		std::cout << CHECK << "Rbegin" << ENDL;

	/* Rend ***************************************************************** */
	if (DEBUG || vector_test(fa, va) || *(fa.rend() - 1) != *(va.rend() - 1))
	{
		std::cout << CROSS << "Rend\n" << RESET <<
		"rend=" << *(fa.rend() - 1) << '\n' <<
		"rend=" << *(va.rend() - 1) << std::endl;
	}
	else
		std::cout << CHECK << "Rend" << ENDL;

	/* Resize *************************************************************** */
	fa.resize(4);
	va.resize(4);
	if (DEBUG || vector_test(fa, va) || *(fa.end() - 1) != *(va.end() - 1))
	{
		std::cout << CROSS << "Resize\n" << RESET <<
		"end=" << *(fa.end() - 1) << '\n' <<
		"end=" << *(va.end() - 1) << std::endl;
		print_ft_vector(fa);
		print_std_vector(va);
	}
	else
		std::cout << CHECK << "Resize" << ENDL;

	/* Resize *************************************************************** */
	fa.resize(8, 99);
	va.resize(8, 99);
	if (DEBUG || vector_test(fa, va) || *(fa.end() - 1) != *(va.end() - 1))
	{
		std::cout << CROSS << "Resize\n" << RESET <<
		"end=" << *(fa.end() - 1) << '\n' <<
		"end=" << *(va.end() - 1) << std::endl;
		print_ft_vector(fa);
		print_std_vector(va);
	}
	else
		std::cout << CHECK << "Resize" << ENDL;

	/* Empty **************************************************************** */
	if (DEBUG || vector_test(fa, va) || fa.empty() != va.empty())
	{
		std::cout << CROSS << "Empty\n" << RESET <<
		"empty=" << fa.empty() << '\n' <<
		"empty=" << va.empty() << std::endl;
	}
	else
		std::cout << CHECK << "Empty" << ENDL;

	/* Reserve ************************************************************** */
	fa.reserve(64);
	va.reserve(64);
	if (DEBUG || vector_test(fa, va) || fa.capacity() != va.capacity())
	{
		std::cout << CROSS << "Reserve\n" << RESET <<
		"capacity=" << fa.capacity() << '\n' <<
		"capacity=" << va.capacity() << std::endl;
	}
	else
		std::cout << CHECK << "Reserve" << ENDL;

	/* Operator [] ********************************************************** */
	if (DEBUG || vector_test(fa, va) || fa[1] != va[1])
	{
		std::cout << CROSS << "Operator []\n" << RESET <<
		"fa[1]=" << fa[1] << '\n' <<
		"va[1]=" << va[1] << std::endl;
	}
	else
		std::cout << CHECK << "Operator []" << ENDL;

	/* At ******************************************************************* */
	for (size_t i = 0; i < va.size(); i++)
	{
		if (DEBUG || vector_test(fa, va) || fa.at(i) != va.at(i))
		{
			std::cout << CROSS << "At\n" << RESET <<
			"at=" << fa.at(i) << '\n' <<
			"at=" << va.at(i) << std::endl;
		}
		else if (i == va.size() - 1)
			std::cout << CHECK << "At" << ENDL;
	}

	/* Front **************************************************************** */
	if (DEBUG || vector_test(fa, va) || fa.front() != va.front())
	{
		std::cout << CROSS << "Front\n" << RESET <<
		"front=" << fa.front() << '\n' <<
		"front=" << va.front() << std::endl;
	}
	else
		std::cout << CHECK << "Front" << ENDL;

	/* Back ***************************************************************** */
	if (DEBUG || vector_test(fa, va) || fa.back() != va.back())
	{
		std::cout << CROSS << "Back\n" << RESET <<
		"back=" << fa.back() << '\n' <<
		"back=" << va.back() << std::endl;
	}
	else
		std::cout << CHECK << "Back" << ENDL;

	/* Assign range ********************************************************* */
	ft ::vector<int>	frange;
	std::vector<int>	vrange;

	frange.assign(fa.begin(), fa.end());
	vrange.assign(va.begin(), va.end());
	if (DEBUG || vector_test(frange, vrange))
		std::cout << CROSS << "Assign range" << ENDL;
	else
		std::cout << CHECK << "Assign range" << ENDL;

	/* Assign fill ********************************************************** */
	ft ::vector<int>	ffill;
	std::vector<int>	vfill;

	ffill.assign(8, 8);
	vfill.assign(8, 8);
	if (DEBUG || vector_test(ffill, vfill))
		std::cout << CROSS << "Assign fill" << ENDL;
	else
		std::cout << CHECK << "Assign fill" << ENDL;
	
	/* Fill ***************************************************************** */
	ft ::vector<int>	fb(8, 8);
	std::vector<int>	vb(8, 8);

	std::cout << BLUE << "Fill :" << ENDL;

	if (DEBUG || vector_test(fb, vb))
		std::cout << CROSS << "Fill" << ENDL;
	else
		std::cout << CHECK << "Fill" << ENDL;

	/* Range ***************************************************************** */
	ft ::vector<int>	fc(fa.begin(), fa.end());
	std::vector<int>	vc(va.begin(), va.end());

	std::cout << BLUE << "Range :" << ENDL;

	if (DEBUG || vector_test(fc, vfill))
		std::cout << CROSS << "Range" << ENDL;
	else
		std::cout << CHECK << "Range" << ENDL;

	/* Copy ***************************************************************** */
	ft ::vector<int>	fd(fa);
	std::vector<int>	vd(va);

	std::cout << BLUE << "Copy :" << ENDL;

	if (DEBUG || vector_test(fd, vd))
		std::cout << CROSS << "Copy" << ENDL;
	else
		std::cout << CHECK << "Copy" << ENDL;

	/* Relational operators ************************************************* */
	std::cout << BLUE << "Relational operators :" << ENDL;

	if ((fa == fb) == (va == vb))
		std::cout << CHECK << "==" << ENDL;
	else
		std::cout << CROSS << "==" << ENDL;
	if ((fa != fb) == (va != vb))
		std::cout << CHECK << "!=" << ENDL;
	else
		std::cout << CROSS << "!=" << ENDL;
	if ((fa <  fb) == (va <  vb))
		std::cout << CHECK << "< " << ENDL;
	else
		std::cout << CROSS << "< " << ENDL;
	if ((fa <= fb) == (va <= vb))
		std::cout << CHECK << "<=" << ENDL;
	else
		std::cout << CROSS << "<=" << ENDL;
	if ((fa >  fb) == (va >  vb))
		std::cout << CHECK << "> " << ENDL;
	else
		std::cout << CROSS << "> " << ENDL;
	if ((fa >= fb) == (va >= vb))
		std::cout << CHECK << ">=" << ENDL;
	else
		std::cout << CROSS << ">=" << ENDL;

	/* Implement ************************************************************ */
	std::cout << BLUE << "Implement :" << ENDL;

	/* iterator_traits ****************************************************** */
	typedef ft::iterator_traits<ft::vector<int> >	traits;
	if (typeid(traits::iterator_category) ==
	typeid(std::random_access_iterator_tag))
		std::cout << CHECK << "iterator_traits" << ENDL;
	else
		std::cout << CROSS << "iterator_traits" << ENDL;

	/* reverse_iterator ***************************************************** */
	for (size_t i = 0; i < va.size(); i++)
	{
		ft ::reverse_iterator<ft ::vector<int>::iterator>f_it = fa.rbegin() + i;
		std::reverse_iterator<std::vector<int>::iterator>v_it = va.rbegin() + i;

		if (DEBUG || vector_test(fa, va) || *f_it != *v_it)
		{
			std::cout << CROSS << "reverse_iterator\n" << RESET <<
			"*f_it=" << *f_it << '\n' <<
			"*v_it=" << *v_it << std::endl;
		}
		else if (i == va.size() - 1)
			std::cout << CHECK << "reverse_iterator" << ENDL;
	}
}

void	ft_map(void)
{
	/* Default ************************************************************** */
	ft ::map<int, std::string>	fa;
	std::map<int, std::string>	ma;

	std::cout << BLUE << "___Map___" << LINE << "\nDefault :" << ENDL;

	/* Range ***************************************************************** */
	// ft ::map<int, std::string>	fb(fa.begin(), fa.end());
	// std::map<int, std::string>	mb(ma.begin(), ma.end());

	std::cout << BLUE << "Range :" << ENDL;

	/* Copy ***************************************************************** */
	ft ::map<int, std::string>	fc(fa);
	std::map<int, std::string>	vc(ma);

	std::cout << BLUE << "Copy :" << ENDL;
}

int		main(int ac, char **av)
{
	if (ac < 2 || av[1][0] == 's')
		ft_stack();
	if (ac < 2 || av[1][0] == 'v')
		ft_vector();
	if (ac < 2 || av[1][0] == 'm')
		ft_map();
	return (0);
}
