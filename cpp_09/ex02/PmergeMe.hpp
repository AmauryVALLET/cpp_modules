/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:10:22 by avallet           #+#    #+#             */
/*   Updated: 2024/02/29 16:34:22 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

# include <sys/time.h>
# include <iomanip>
# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>

class PmergeMe {

	private:
		
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe	&operator=(const PmergeMe &rhs);

		template <typename T>
		void	sortContainer(T &container);
		template <typename T>
		void	searchInsertion(T& container, int element);
		
		std::vector<std::string>		_listInitiale;
		std::vector<int>				_vectorInt;
		std::deque<int>					_dequeInt;
		long long int					_timeVector;
		long long int					_timeDeque;

	public:

		PmergeMe(char **av);
		~PmergeMe();

		void	beforeMerge() const;
		void	afterMerge() const;
		void	showVectorTime() const;
		void	showListTime() const;

		class WrongParameterException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NegatifIntegerException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

long long int	getTime();