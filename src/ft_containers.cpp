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
	
	ft::vector<int>		fb(fa);
	std::vector<int>	vb(va);

	std::cout << "size=" << fb.size() << "\tmax_size=" << fb.max_size() << std::endl;
	std::cout << "size=" << vb.size() << "\tmax_size=" << vb.max_size() << std::endl;
}

int		main(void)
{
	ft_stack();
	ft_vector();
	return (0);
}
