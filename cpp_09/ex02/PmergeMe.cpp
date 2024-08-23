/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:10:08 by avallet           #+#    #+#             */
/*   Updated: 2024/03/01 10:58:38 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


// UTILS 

long long int getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

bool	isDigit(std::string str)
{
	int i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

// CONSTRUCTORS DESTRUCTORS AND ALGO 

PmergeMe::PmergeMe(){
};

PmergeMe::PmergeMe(char **av){
	int 			i = 1;
	int				nb;
	long long int	startingTime;	

	while (av[i])
	{
		if (isDigit(av[i]))
			_listInitiale.push_back(av[i]);
		else
			throw PmergeMe::WrongParameterException();
		nb = atoi(av[i]);
		if (nb < 0)
			throw PmergeMe::NegatifIntegerException();
		else 
		{
			_vectorInt.push_back(nb);
			_dequeInt.push_back(nb);
		}
		i++;
	}
	startingTime = getTime();
	sortContainer(_vectorInt);
	_timeVector = getTime() - startingTime;
	startingTime = getTime();
	sortContainer(_dequeInt);
	_timeDeque = getTime() - startingTime;
};

PmergeMe::PmergeMe(const PmergeMe &src){
	(void)src;
};

PmergeMe	&PmergeMe::operator=(const PmergeMe &rhs){
	(void)rhs;
	return (*this);
};

PmergeMe::~PmergeMe(){

};

void	insertJac(std::vector<int> &Jac)
{
	Jac.push_back(0);
	Jac.push_back(2);
	Jac.push_back(4);
	Jac.push_back(10);
	Jac.push_back(20);
	Jac.push_back(42);
	Jac.push_back(84);
	Jac.push_back(170);
	Jac.push_back(340);
	Jac.push_back(682);
	Jac.push_back(1364);
	Jac.push_back(2730);
	Jac.push_back(5460);
	Jac.push_back(10922);
	Jac.push_back(21844);
	Jac.push_back(43690);
	Jac.push_back(87380);
	Jac.push_back(174762);
	Jac.push_back(349524);
	Jac.push_back(699050);
	Jac.push_back(1398100);
	Jac.push_back(2796202);
	Jac.push_back(5592404);
	Jac.push_back(11184810);
	Jac.push_back(22369620);
	Jac.push_back(44739242);
	Jac.push_back(89478484);
	Jac.push_back(178956970);
	Jac.push_back(357913940);
	Jac.push_back(715827882);
	Jac.push_back(1431655764);
	Jac.push_back(2147483647);
}

template <typename T>
void	PmergeMe::searchInsertion(T& main, int element){
	int left = 0;
	int right = main.size() - 1;
	int middle;
	while (left <= right)
	{
		middle = left + (right - left) / 2;
		if (element < main[middle])
			right = middle - 1;
		else
			left = middle + 1;
	}
	main.insert(main.begin() + left, element);
};

template <typename T>
void	PmergeMe::sortContainer(T &container){
	std::vector<int> Jac;
	insertJac(Jac);
	
	for (size_t i = 0; i < container.size() - 1; i += 2)
		if (container[i] > container[i + 1])
			std::swap(container[i], container[i + 1]);
	if (container.size() > 2)
	{
		T pairs;
		for (size_t i = 0; i < container.size(); i += 2)
			pairs.push_back(container[i]);
		sortContainer(pairs);
		T main = pairs;
		T onHolds;
		for (size_t i = 1; i < container.size(); i += 2)
			onHolds.push_back(container[i]);
		int	sizeMax = onHolds.size();
		for (int index = 0; index < sizeMax; index++)
		{
			int j = 0;
			int optiIndex;
			while (index > Jac[j])
				j++;
			if (j != 0)
			{
				if (sizeMax - 1 <= Jac[j]) // to put close to end of ctn
					optiIndex = sizeMax - (index - Jac[j - 1]);
				else
					optiIndex = Jac[j] + 1 - (index - Jac[j - 1]); // relative pos
			}
			else
				optiIndex = 0;
			searchInsertion(main, onHolds[optiIndex]);
		}
		container = main;
	}
};


// DISPLAYS AND MESS 


void	PmergeMe::showVectorTime() const{
	std::cout <<"Time to process a range of " << _listInitiale.size() << " elements with std::vector : " << _timeVector << " us" << std::endl;
};

void	PmergeMe::showListTime() const{
		std::cout <<"Time to process a range of " << _listInitiale.size() << " elements with std::deque   : " << _timeDeque << " us" << std::endl;
};

const char *PmergeMe::WrongParameterException::what() const throw() {
	return ("Wrong param, enter digits only.");
};

const char *PmergeMe::NegatifIntegerException::what() const throw() {
	return ("Wrong param, enter only positive int.");
};



void	PmergeMe::beforeMerge() const {
	std::string str = "Before:";
	
	for (size_t i = 0; i < _listInitiale.size(); i++)
		str+= (" " + _listInitiale[i]);
	std::cout << str << std::endl;
};

void	PmergeMe::afterMerge() const {
	std::cout << "After: " ;
	for (size_t i = 0; i < _vectorInt.size(); i++)
		std::cout << " " << _vectorInt[i];
	std::cout << std::endl;
};
