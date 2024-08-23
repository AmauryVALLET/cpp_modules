/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:23:55 by avallet           #+#    #+#             */
/*   Updated: 2024/01/31 12:17:59 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>


template < typename T, typename F >
void	iter(T *array, size_t len, F function)
{
	if (!array)
	{
		std::cerr << "Array is null" << std::endl;
		return ;
	}
	for (size_t i = 0; i < len; ++i)
		function(array[i]);
};

template < typename T>
void	printArray(T data)
{
	std::cout << data << std::endl;
}

template < typename T>
void	incrementArray(T &data)
{
	++data;
}

class people {
	
	private :

		std::string		_name;
		int				_height;

		people();
		people &operator=(const people &rhs){(void)rhs; return (*this);};

	public:
		people(std::string name, int height): _name(name), _height(height){};
		people(const people &src): _name(src.getName()), _height(src.getheight()){};
		~people(){};
		std::string		getName() const { return (_name);};
		int				getheight() const { return (_height);};
		people		&operator++( void ){ _height++; return(*this);};
};

std::ostream& operator<<(std::ostream & o, people const & p){
	o << "name: " << p.getName() << std::endl
		<< "height: " << p.getheight() << "cm";
	return (o);
};