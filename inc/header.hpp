/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrusso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:35:14 by frrusso           #+#    #+#             */
/*   Updated: 2023/02/08 17:35:32 by frrusso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP

/* Include ******************************************************************* */
#include <stack.hpp>
#include <vector.hpp>
#include <stack>
#include <vector>

/* Colors ******************************************************************* */
#define RESET	"\033[0m"
#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"

/* ft_containers ************************************************************ */
#define DEBUG	false
#define CHECK	"\U00002705 \033[32m"
#define CROSS	"\U0000274C \033[31m"
#define LINE	"______________________________________________________________"
#define ENDL	"\033[0m" << std::endl

#endif
