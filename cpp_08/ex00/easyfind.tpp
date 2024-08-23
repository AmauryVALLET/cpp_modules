/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:17:30 by avallet           #+#    #+#             */
/*   Updated: 2024/02/08 17:17:31 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

const char	*DidNotMatchExc::what() const throw()
{
	return ("value did not match");
}

template < typename T >
typename T::iterator	easyfind(T &container, int value)
{
	typename T::iterator	iter;
	
	iter = find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw DidNotMatchExc();
	else
		return (iter);
};