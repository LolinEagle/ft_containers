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

void	ft_stack(void)
{
	ft ::stack<int>	fa;
	std::stack<int>	sa;

	std::cout << "___Stack___________________________________________________\n"
	<< "Default :\n"
	<< "size=" << fa.size() << "\tempty=" << fa.empty() << "" << '\n'
	<< "size=" << sa.size() << "\tempty=" << sa.empty() << "" << '\n'
	<< std::endl;

	fa.push(7);
	sa.push(7);

	std::cout
	<< "size=" << fa.size() << "\tempty=" << fa.empty() << "" << "\ttop="
	<< fa.top() << '\n'
	<< "size=" << sa.size() << "\tempty=" << sa.empty() << "" << "\ttop="
	<< sa.top() << '\n'
	<< std::endl;
}

void	ft_vector(void)
{
	ft ::vector<int>	fa;
	std::vector<int>	va;

	std::cout << "___Vector__________________________________________________\n"
	<< "Default :\n"
	<< "size=" << fa.size() << "\tmax_size=" << fa.max_size() << '\n'
	<< "size=" << va.size() << "\tmax_size=" << va.max_size() << '\n'
	<< std::endl;

	for (int i = 1; i < 9; i++)
	{
		// fa.push_back(i);
		// va.push_back(i);
	}

	std::cout
	// << "size=" << fa.size() << "\t[0]=" << fa[0] << "\t[7]=" << fa.at(7) << '\n'
	// << "size=" << va.size() << "\t[0]=" << va[0] << "\t[7]=" << va.at(7) << '\n'
	<< std::endl;

	ft ::vector<int>	fb(6, 6);
	std::vector<int>	vb(6, 6);

	std::cout
	<< "Fill :\n"
	<< "size=" << fb.size() << "\t[0]=" << fb[0] << "\t[5]=" << fb.at(5) << '\n'
	<< "size=" << vb.size() << "\t[0]=" << vb[0] << "\t[5]=" << vb.at(5) << '\n'
	<< std::endl;
	
	ft ::vector<int>	fd(fa);
	std::vector<int>	vd(va);

	std::cout
	<< "Copy :\n"
	<< "size=" << fd.size() << "\tmax_size=" << fd.max_size() << '\n'
	<< "size=" << vd.size() << "\tmax_size=" << vd.max_size() << '\n'
	// << "size=" << fd.size() << "\t[0]=" << fd[0] << "\t[5]=" << fd.at(5) << '\n'
	// << "size=" << vd.size() << "\t[0]=" << vd[0] << "\t[5]=" << vd.at(5) << '\n'
	<< std::endl;
}

int		main(void)
{
	ft_vector();
	ft_stack();
	return (0);
}
