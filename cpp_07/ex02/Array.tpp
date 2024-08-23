/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:39:15 by avallet           #+#    #+#             */
/*   Updated: 2024/01/31 12:39:16 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template < typename T >
Array<T>::Array(): _array(new T), _size(1){
	
};

template < typename T >
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n){
	
};

template < typename T >
Array<T>::~Array(){
	if (_size == 1)
		delete _array;
	else
		delete [] _array;
};

template < typename T >
Array<T>::Array(const Array<T> &src):_array(new T[src.size()]), _size(src.size()){
	for (size_t i = 0; i < _size; ++i)
		_array[i] = src._array[i];
};

template < typename T >
Array<T>	&Array<T>::operator=(const Array<T> &rhs){
	if (this != &rhs)
	{
		_array = new T[rhs.size()];
		for (size_t i = 0; i < _size; ++i)
			_array[i] = rhs._array[i];
		_size = rhs._size();
	}
	return (*this);
};

template < typename T >
size_t	Array<T>::size() const{
	return (_size);
};

template < typename T >
T		&Array<T>::operator[](unsigned int index){
	if (index > _size - 1)
		throw Array<T>::indexOutOfRange();
	else
		return (_array[index]);
};

template < typename T >
const char* Array<T>::indexOutOfRange::what() const throw(){
	return ("Index out of range");
};