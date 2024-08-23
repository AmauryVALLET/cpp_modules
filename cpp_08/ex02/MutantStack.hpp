/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:18:06 by avallet           #+#    #+#             */
/*   Updated: 2024/02/08 17:18:07 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iterator>
#include <stack>
#include <deque>
#include <algorithm>

template < typename T >
class MutantStack : public std::stack<T> 
{

	public:

		MutantStack();
		MutantStack(const MutantStack &src);
		~MutantStack();
		MutantStack	&operator=(const MutantStack &rhs);
		
		// double ended queue -> to nav bet end/beg of stack 
		typedef typename std::deque<T>::iterator iterator;
		iterator	begin();
		iterator	end();

};

#include "MutantStack.tpp"