/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:17:51 by avallet           #+#    #+#             */
/*   Updated: 2024/02/08 17:17:52 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(){	
};

Span::Span(const Span &src){
	(void)src;
};

Span	&Span::operator=(const Span &rhs){
	if (this != &rhs)
	{
		_maxLen = rhs._maxLen;
		_intContainer = rhs._intContainer;
	}
	return (*this);
};

Span::Span(unsigned int n): _maxLen(n){	
	if (_maxLen > _intContainer.max_size())
		throw Span::CapacityTooSmallException();
};

Span::~Span(){
};

void	Span::addNumber(int nb){
	if (_intContainer.size() == _maxLen)
		throw Span::ContainerFullException();
	_intContainer.push_back(nb);
};

// to add tab (several nb) into container
void	Span::addNumber(std::vector<int> tabInt){
	if (_intContainer.size() + tabInt.size() >= _maxLen)
		throw Span::ContainerFullException();
	_intContainer.insert(_intContainer.end(), tabInt.begin(), tabInt.end());
};

int	Span::shortestSpan(){
	int	len = _intContainer.size();
	if (len <= 1)
		throw Span::NoSpanException();
	std::sort(_intContainer.begin(), _intContainer.end());
	int	dif = abs(_intContainer[1] - _intContainer[0]);
	for (int i = 1; i < len - 1; ++i)
	{
		if (abs(_intContainer[i + 1] - _intContainer[i]) < dif)
			dif = abs(_intContainer[i + 1] - _intContainer[i]);
	}
	return (dif);
};

int	Span::longestSpan(){
	int	len = _intContainer.size();
	if (len <= 1)
		throw Span::NoSpanException();
	std::sort(_intContainer.begin(), _intContainer.end());
	return(abs(_intContainer[len - 1] - _intContainer[0]));
};

const char *Span::NoSpanException::what() const throw(){
	return ("Container lenght is either empty or too small");
};

const char *Span::ContainerFullException::what() const throw(){
	return ("Lenght max of Span reached");
};

const char *Span::CapacityTooSmallException::what() const throw(){
	return ("Container cap  too low");
};