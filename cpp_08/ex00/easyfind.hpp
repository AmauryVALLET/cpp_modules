/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:17:24 by avallet           #+#    #+#             */
/*   Updated: 2024/02/08 17:17:25 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>

class DidNotMatchExc : public std::exception {
	public:
		virtual const char *what() const throw();
};

template < typename T >
typename T::iterator	easyfind(T &container, int value);

#include "easyfind.tpp"