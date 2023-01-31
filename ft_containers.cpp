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
	ft::vector<std::string>		fb(fa);
	std::vector<std::string>	va;
	std::vector<std::string>	vb(va);

	std::cout << "\nsize=" << fa.size() << "\nmax_size=" << fa.max_size() << std::endl;
	std::cout << "\nsize=" << va.size() << "\nmax_size=" << va.max_size() << std::endl;
	std::cout << "\nsize=" << fb.size() << "\nmax_size=" << fb.max_size() << std::endl;
	std::cout << "\nsize=" << vb.size() << "\nmax_size=" << vb.max_size() << std::endl;
	std::cout << va[10] << std::endl;
	return (0);
}
