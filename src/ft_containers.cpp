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
	ft::stack<int>	fa;
	std::stack<int>	sa;

	(void)fa;
	(void)sa;
}

void	ft_vector(void)
{
	ft::vector<int>		fa;
	std::vector<int>	va;

	std::cout << "size=" << fa.size() << "\tmax_size=" << fa.max_size() << std::endl;
	std::cout << "size=" << va.size() << "\tmax_size=" << va.max_size() << std::endl;

	std::cout << "size=" << fa.size() << "\tmax_size=" << fa.max_size() << std::endl;
	std::cout << "size=" << va.size() << "\tmax_size=" << va.max_size() << std::endl;
	std::cout << std::endl;

	ft::vector<int>		fb(8, 8);
	std::vector<int>	vb(8, 8);

	std::cout << "size=" << fb.size() << "\t[0]=" << fb[0] << "\t[7]=" << fb.at(7) << std::endl;
	std::cout << "size=" << vb.size() << "\t[0]=" << vb[0] << "\t[7]=" << vb.at(7) << std::endl;
	// std::cout << "front=" << fb.front() << std::endl;
	std::cout << "front=" << vb.front() << std::endl;
	std::cout << std::endl;
	
	ft::vector<int>		fd(fa);
	std::vector<int>	vd(va);

	std::cout << "size=" << fd.size() << "\tmax_size=" << fd.max_size() << std::endl;
	std::cout << "size=" << vd.size() << "\tmax_size=" << vd.max_size() << std::endl;
}

int		main(void)
{
	ft_stack();
	ft_vector();
	return (0);
}
