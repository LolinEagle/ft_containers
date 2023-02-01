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

#include <vector.hpp>
#include <vector>

int	main(void)
{
	ft::vector<std::string>		fa;
	std::vector<std::string>	va;

	std::cout << "size=" << fa.size() << "\tmax_size=" << fa.max_size() << 
	std::endl;
	std::cout << "size=" << va.size() << "\tmax_size=" << va.max_size() << 
	std::endl;
	
	ft::vector<std::string>		fb(fa);
	std::vector<std::string>	vb(va);

	std::cout << "size=" << fb.size() << "\tmax_size=" << fb.max_size() << 
	std::endl;
	std::cout << "size=" << vb.size() << "\tmax_size=" << vb.max_size() << 
	std::endl;
	return (0);
}
