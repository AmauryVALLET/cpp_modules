/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:17:56 by avallet           #+#    #+#             */
/*   Updated: 2024/02/08 17:17:57 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

class Span {

	private:
		unsigned int		_maxLen;
		std::vector<int>	_intContainer;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &src);
		Span	&operator=(const Span &rhs);
		~Span();

		void	addNumber(int nb);
		void	addNumber(std::vector<int> tabInt);
		int		shortestSpan();
		int		longestSpan();

	class NoSpanException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class ContainerFullException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class CapacityTooSmallException: public std::exception {
		public:
			virtual const char *what() const throw();
	};
};