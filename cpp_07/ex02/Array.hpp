/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:38:57 by avallet           #+#    #+#             */
/*   Updated: 2024/01/31 12:38:58 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <iostream>

template < typename T >
class Array {
	private:
		T		*_array;
		size_t	_size;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &src);
		~Array();
		Array	&operator=(const Array &rhs);
		T		&operator[](unsigned int index);
		size_t	size() const;
		class indexOutOfRange : public std::exception {
			virtual const char* what() const throw();
		};
};

#include "Array.tpp"