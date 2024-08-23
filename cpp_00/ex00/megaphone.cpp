/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:11:53 by avallet          #+#    #+#             */
/*   Updated: 2023/11/08 13:13:56 by avallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	std::string const str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (ac == 1)
		std::cout << str;
	for (int i = 1; av[i]; i++) {
		std::string s(av[i]);
		for (std::string::iterator it = s.begin(); it != s.end(); it++)
			*it = std::toupper(*it);
		std::cout << s;
	}
	std::cout << std::endl;
	return (0);
}
